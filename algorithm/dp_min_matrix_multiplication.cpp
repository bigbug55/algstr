/*
A Dynamic programing algorithm example
	problem: find out in which order should an array of matrixes be multiplied.
	
	backgroud:
		It is well known that matrix multiplication requires large amount of computation.
		As for two matrix:
			A[p*q];
			B[q*r];
		A*B require p*q*r times of multiplication.
		
		Given three matrixes:{A1, A2, A3}
			A1: 10*100;
			A2:  100*5;
			A3:   5*50;
		
		case1: Mutiply (A1A2) and then the result being multiplied by A3, it requires 
			(A1A2)A3 = 10*100*5+10*5*50=7500;
		case2: Mutiply (A2A3) and then the result being multiplied by A1, it requires 
			A1(A2A3) = 100*5*50+10*100*50=75000;
		
		The result of case1 equals with the result of case2, but the computation cost differs greatly,
		which tells us it is necessary to optimal the order of matrix multiplication.
		
	Introduction to the following example:
		A[0]: 30*35;
		A[1]: 35*15;
		A[2]: 15*5;
		A[3]: 5*10;
		A[4]: 10*20;
		A[5]: 20*25;
	array p: sizes of matrixes;
	array m: times of multiplications for subarray of matrixes;
	array s: where to break the subrray of matrixes to decide the order;
*/

#include <stdio.h>
#include <iostream>

#define N 7

void matrix(int*p, int m[][N-1], int s[][N-1])
{
	int i;
	int d, k;

	int n = N-1;

	for(i=0; i<n; i++)
		m[i][i] = 0;

	for(d=1; d<n; d++)
		for(i=0; i<n-d; i++)
		{
			if( d == 1){
				m[i][i+d] = p[i]*p[i+d]*p[i+d+1];
				s[i][i+d] = i;
			}
			else{
				m[i][i+d] = m[i][i] + m[i+1][i+d] + p[i]*p[i+1]*p[i+d+1];
				s[i][i+d] = i; 

				for(k=i+1; k<i+d; k++){
					int t = m[i][k] + m[k+1][i+d] + p[i]*p[k+1]*p[i+d+1]; 
					if(t < m[i][i+d]){
						m[i][i+d] = t;
						s[i][i+d] = k;
					}
					
				}
			}

		}
}

void showMatrix(int a[][N-1])
{
	int i,j;
	int n=N-1;

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
				printf("%d\t ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void initMatrix(int a[][N-1])
{
	int i,j;
	int n=N-1;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j] = 0;
}

void list1(int a, int b, int s[][N-1])
{
	if(a == b) return;
	else{
		list1(a, s[a][b], s);
		list1(s[a][b]+1, b, s);
		printf("mutiply A[%d,%d] and A[%d,%d]\n", a, s[a][b], s[a][b]+1, b);
	}
}

void list2(int a, int b, int s[][N-1])
{
	if(a == b){
		printf("A%d", a);
		return;
	}
	else{
		printf("(");
		list2(a, s[a][b], s);
		list2(s[a][b]+1, b, s);
		printf(")");
	}
}

int main(int argc, char* argv[])
{

	int p[N]={30, 35, 15, 5, 10, 20, 25};
	int m[N-1][N-1];
	int s[N-1][N-1];

	initMatrix(m);
	initMatrix(s);

	matrix(p, m, s);

	//showMatrix(m);
	//showMatrix(s);

	printf("order of multiplication:\n");
	list1(0, 5, s);
	printf("\n");

	printf("order of multiplication:\n");
	list2(0, 5, s);

	getchar();
	return 0;
}

