
#include "node.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double combine(node* py, int n, double lx, double delta);
void copynode(node* dt, node* sr, int b, int n);
double minDist(node* px, node* py, int n);
double callMinDist(node*p, int n);

double combine(node* py, int n, double lx, double delta)
{
	int num; double d=MAX;
	double tempd;
	node* temp = (node*)malloc(n*sizeof(node));

	int j=0;

	for(int i=0; i<n; i++)
	{
		if(fabs(py[i].x - lx)<= delta){
			temp[j].x = py[i].x;
			temp[j].y = py[i].y;
			j++;
		}
	}

	num = j;  //temp中的元素

	for(int i=0; i<num; i++)
	{
		for(j=i+1; j<(i+8) && (j<num); j++)
		{
			tempd = dist(&temp[i], &temp[j]);
			if(tempd < d)
				d=tempd;
		}
	}

	free(temp);
	return d;
}

void copynode(node* dt, node* sr, int b, int n) //n is max of index;
{
	int k=0;

	for(int i=b; i<=n; i++)
	{
		dt[k].x = sr[i].x;
		dt[k].y = sr[i].y;
		k++;
	}
}

double min(double x, double y)
{
	if(x<=y)
		return x;
	return y;
}

double minDist(node* px, node* py, int n)
{
		//printf("n is %d\n", n);
		if(n<=3){
			//show(px, n); //n is number of elements;
			double d = force(px, n); //n is number of elements;
			//printf("n=%d is %lf\n",n, d);
			return d;
		}
		
		int m=n/2;
		double fx = px[m].x;

		node* lx = (node*)malloc(m*sizeof(node));
		node* ly = (node*)malloc(m*sizeof(node));
		node* rx = (node*)malloc((n-m)*sizeof(node));
		node* ry = (node*)malloc((n-m)*sizeof(node));
		
		
		copynode(lx, px, 0, m-1); //对copy而言,这里的m应该是index;
		//show(lx, m);  //show中的n是number of elements;
		//printf("lx :%x\n", lx);

		copynode(rx, px, m, n-1); //copy这边是index;
		//show(rx, n-m);

		copynode(ly, py, 0, m-1);
		//show(ly, m);

		copynode(ry, py, m, n-1);
		//show(ry, n-m);
		
		double d1 = minDist(lx, ly, m); //m is number of elements;
		double dr = minDist(rx, ry, n-m);
		
		double delta = min(d1, dr);
		double d = combine(py, n, fx, delta); //对combine而言,这里的n是number of elements;

		//printf("lx :%x\n", lx);
		free(lx);
		free(ly);
		free(rx);
		free(ry);
		
		return min(delta, d);
}

double call_min_dist(node* p, int n){

	node* px = (node*)malloc(n*sizeof(node)); //n主要是用于此处的空间申请;
	node* py = (node*)malloc(n*sizeof(node));

	//show(p, n);
	mergeSortX(p, px, 0, n-1);
	copynode(px, p, 0, n-1);
	//show(px, n);

	//show(p, n);
	mergeSortY(p, py, 0, n-1);
	copynode(py, p, 0, n-1);
	//show(py, n);

	double min = minDist(px, py, n);

	free(px);
	free(py);

	return min;
}

//测试combine的正确性;
/*
int main()
{
	node* py = (node*)malloc(sizeof(node)*10);
	initList(py);

	//double d=combine(py, 9, 3.0, 1.0);
	//printf("d is %lf\n", d);

	//printf("sqrt(1.25) = %lf\n", sqrt(1.25));  //上述的py[4]和py[5]之间最近;

	getchar();
	return 0;
}
*/