#ifndef __NODE__
#define __NODE__

#define SIZE 4
#define MAX 100000.0

typedef struct{
	double x;
	double y;
}node;


//sort
void mergeX(node a[], node b[], int s, int m, int t);
void mergeY(node a[], node b[], int s, int m, int t);
void mergeSortX(node a[], node b[], int s, int t);
void mergeSortY(node a[], node b[], int s, int t);

//utility;
void show(node* a, int size);
void initList(node* list);
double dist(node* n1, node* n2);

//brute force
double force(node* nodelist, int n);

//divice-and-conquer
double combine(node* py, int n, double lx, double delta);
void copynode(node* dt, node* sr, int b, int n);
double minDist(node* px, node* py, int n);
double call_min_dist(node*p, int n);

#endif