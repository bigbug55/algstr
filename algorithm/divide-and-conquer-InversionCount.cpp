/*
A divide-and-conqure algorithm example
	problem: using divide-and-conqure to calculate how many inversions in a data array.
	
	Example: 
	Given an array "1, 2, 4, 3", there is only one inversion (4,3), so the number of inversions should be 1.

	Introduction:
	The following version is based on merge sort, it is quite intuitive that the merge sort can be used in such a way.
*/

#include<stdio.h>
#include<stdlib.h>

int sortCount(int a[], int s, int n);
int mergeCount(int a[], int s, int m, int n);

int sortCount(int a[], int s, int n)
{
	if(a == NULL || n<0 || s>n )
		return -1;

	int b, c, d;

	if(n==s)
		return 0;
	else{
		int m = s+(n-s)/2;
		b = sortCount(a, s, m);
		c = sortCount(a, m+1, n);
		d = mergeCount(a, s, m, n);
	}
	return (b+c+d);
}

int mergeCount(int a[], int s, int m, int n)
{
	int *b = (int*)malloc((n-s+1)*sizeof(int));

	int i, j, k;
	int count = 0;

	for(i=s, j=m+1, k=0; (i<=m)&&(j<=n); k++){
		if(a[i]<=a[j]){
			b[k] = a[i++];
		}else{
			b[k] = a[j++];
			count+=(m-i+1);
		}
	}
	while(i<=m) b[k++] = a[i++];
	while(j<=n) b[k++] = a[j++];

	k=0;
	for(int i = s; i<=n; i++)
		a[i] = b[k++];

	free(b);
	return count;
}

int test_mergeCount()
{
	int a[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	return sortCount(a, 0, 7);
}

int main(int argc, char* argv[])
{
	printf("b is %d\n", test_mergeCount());

	getchar();
	return 0;
}