// merge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "node.h"
#include <stdlib.h>

void mergeX(node a[], node b[], int s, int m, int t);
void mergeY(node a[], node b[], int s, int m, int t);
void mergeSortX(node a[], node b[], int s, int t);
void mergeSortY(node a[], node b[], int s, int t);
void show(node* a, int size);

void mergeSortX(node a[], node b[], int s, int t)
{
	if(s == t){
		b[s].x = a[s].x;
		b[s].y = a[s].y;
	}
	else{
		int m = (s+t)/2;
		mergeSortX(a, b, s, m);
		mergeSortX(a, b, m+1, t);
		mergeX(a, b, s, m, t);
	}
}

void mergeSortY(node a[], node b[], int s, int t)
{
	if(s == t){
		b[s].x = a[s].x;
		b[s].y = a[s].y;
	}
	else{
		int m = (s+t)/2;
		mergeSortY(a, b, s, m);
		mergeSortY(a, b, m+1, t);
		mergeY(a, b, s, m, t);
	}
}


void mergeX(node* a, node* b, int s, int m, int t)
{
	int i, j, n;

	for(i=s, j=m+1, n=s; (i<=m)&&(j<=t); n++){
		if(b[i].x<=b[j].x){
			a[n].x = b[i].x;
			a[n].y = b[i].y;
			i++;
		}else{
			a[n].x = b[j].x;
			a[n].y = b[j].y;
			j++;
		}
	}
	while(i<=m){
		a[n].x = b[i].x;
		a[n++].y = b[i++].y;
	}

	while(j<=t){
		a[n].x = b[j].x;
		a[n++].y = b[j++].y;
	}

	//这里需要将a中的数据重新拷贝到b中;
	for(int i=s; i<=t; i++){
		b[i].x = a[i].x;
		b[i].y = a[i].y;
	}
}

void mergeY(node* a, node* b, int s, int m, int t)
{
	int i, j, n;

	for(i=s, j=m+1, n=s; (i<=m)&&(j<=t); n++){
		if(b[i].y<=b[j].y){
			a[n].x = b[i].x;
			a[n].y = b[i].y;
			i++;
		}else{
			a[n].x = b[j].x;
			a[n].y = b[j].y;
			j++;
		}
	}
	while(i<=m){
		a[n].x = b[i].x;
		a[n++].y = b[i++].y;
	}

	while(j<=t){
		a[n].x = b[j].x;
		a[n++].y = b[j++].y;
	}

	//这里需要将a中的数据重新拷贝到b中;
	for(int i=s; i<=t; i++){
		b[i].x = a[i].x;
		b[i].y = a[i].y;
	}
}

void show(node* a, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d: %lf, %lf \n", i, a[i].x, a[i].y);
	printf("\n");
}

/*
void initList3(node* py)
{
		py[0].x= 2.0;
		py[0].y= 1.0;

		py[1].x= 1.0;
		py[1].y= 2.0;

		py[2].x= 1.2;
		py[2].y= 3.0;

		py[3].x= 3.0;
		py[3].y= 4.0;

		py[4].x= 5.0;
		py[4].y= 5.0;
	
		py[5].x= 1.5;
		py[5].y= 5.5;

		py[6].x= 2.5;
		py[6].y= 7.0;

		py[7].x= 3.5;
		py[7].y= 8.0;

		py[8].x= 4.0;
		py[8].y= 9.0;
}
*/

//测试sort的正确性;
/*
int mainold4()
{
	node* p = (node*)malloc(sizeof(node)*9);
	initList3(p);

	show(p, 9);
	node* px = (node*)malloc(sizeof(node)*9);
    mergeSortX(p, px, 0, 8);

	printf("after X sort\n");
	show(p, 9);

	node* py = (node*)malloc(sizeof(node)*9);
    mergeSortY(p, py, 0, 8);
	printf("after Y sort\n");
	show(p, 9);



	getchar();
	return 0;
}
*/