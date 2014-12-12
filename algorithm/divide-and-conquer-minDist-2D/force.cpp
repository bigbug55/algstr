// force.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include "node.h"

double dist(node* n1, node* n2)
{
	double temp1 = n1->x - n2->x;
	double temp2 = n1->y - n2->y;

	double sum = temp1*temp1 + temp2*temp2; //pow(temp1, 2)+pow(temp2, 2);
	return sqrt(sum);
}

double force(node* nodelist, int n) //n is number of elements
{
	//这里d需要有一个初始的大值;
	double d = MAX;
	double t;
	
	//函数的主体就是下面这个双层循环;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
		{
			t = dist(&nodelist[i], &nodelist[j]);
			if(t<d)
				d = t;
		}
	}
	//这里最后返回d;
	return d;
}