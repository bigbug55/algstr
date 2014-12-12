//problem: To find a given number in a two-dimension array,
//	values in a incremental order for each row and column respectively.
//	if the targeted number not found,
//		return -1;
//	otherwise return the targeted number;

#include<stdio.h>
#include<iostream>
#include<memory>
#include<assert.h>

int find_value(int *p, int rows, int columns, int number)
{
	if(p == NULL)
		return -1;

	int i_row = 0;
	int i_col = columns;

	while(i_row < rows && i_col >=0)
	{
		int current = p[i_row*columns + i_col -1];

		if( current == number)
			return number;
		else if( current < number )
			i_row++;
		else
			i_col--;
	}
	return -1;
}

//testcase1:
//	the required number is the max of 2D;
//	or
//	the required number is the min of 2D;
int test1()
{
}

//testcase2:
//	the required number is neither the max nor min of the 2D array;
//	but it is in the 2D;
int test2()
{
	int p[16] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10,13,
		6, 8, 11, 15};
	//printf("find_value = %d\n", p[2*4+1]);
	return find_value(p, 4, 4, 7);
}

//testcase3:
//	the required number is bigger than the max of 2D;
//	or
//	the required number is smaller than the min of 2D;
int test3()
{
	
	int p[16] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10,13,
		6, 8, 11, 15};
	//printf("find_value = %d\n", p[2*4+1]);
	return find_value(p, 4, 4, 15);
}

//testcase4:
//	the inputed p is set to null by accident;
int test4()
{
	int* p = NULL;
	return find_value(p, 4, 4, 15);
}

int main()
{
	assert( test2() == 7 );
	assert( test3() == 15 );
	assert( test4() == -1 );
	return 0;	
}
