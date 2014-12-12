/*
A divide-and-conqure algorithm example:
	problem: Find the mininum distance between two points in a two-dimension plane.
	Introduction:
		1. force(): calculate the mininum dist. using brute force, the computation complexity is o(n^2);
		2. min_dist(): using divide-and-conquer to calculate the minimum dist.
*/


#include<stdio.h>
#include<stdlib.h>
#include "node.h"

//init the value of points in two-dimension plane.
void initList(node* p)
{
		p[0].x= 2.0;
		p[0].y= 1.0;

		p[1].x= 1.0;
		p[1].y= 2.0;

		p[2].x= 1.2;
		p[2].y= 3.0;

		p[3].x= 3.0;
		p[3].y= 4.0;

		p[4].x= 5.0;
		p[4].y= 5.0;
	
		p[5].x= 1.5;
		p[5].y= 5.5;

		p[6].x= 2.5;
		p[6].y= 7.0;

		p[7].x= 3.5;
		p[7].y= 8.0;

		p[8].x= 4.0;
		p[8].y= 9.0;

		p[9].x = 3.9;
		p[9].y = 8.8;
}

int main()
{
	node* p = (node*)malloc(sizeof(node)*10);
	initList(p);

	double ddf = force(p, 10); 
	printf("the output of force is %lf\n", ddf);

	double dd = call_min_dist(p, 10);
	printf("the output of divide-conquer is %lf\n", dd);

	getchar();
	return 0;
}