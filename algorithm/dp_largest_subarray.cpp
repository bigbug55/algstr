/*
A Dynamic programing algorithm example
	problem: find the subarray with the largest sum and then output the sum and range.
	
	Example: -2, 11, -3, 13, -5, -20, 12
		"11, -3, 13" is the largest subarray with the value of 21, and it starts from index 1 to index 3.
		Be aware that "11, 13, 12" is not the largest because it is not a subarray.
*/


#include <stdio.h>
bool largest_subsum(int a[], int length)
{
	if(a == NULL || length <= 0)
		return false;
	
	int j = 0;

	while(a[j]<0) 
		j++;

	int temp = 0;
	int t_end = j;
	int t_begin = j;

	int sum = 0;
	int begin=0;
	int end=0; 

	for(int i=j; i<length; i++)
	{
		if(temp == 0)
		{
			if(a[i] > 0) {t_begin = t_end = i; }
		}else
			t_end = i;

		temp += a[i];

		if(temp > sum){
			begin = t_begin;
			end = t_end;
			sum = temp;

		}else if(temp <0){
			temp = 0;
		}
	}
	printf("the sum is %d, begin %d, end %d\n", sum, begin, end);
	return true;
}

void test_nomal(){
	printf("test_nomal: ");
	int a[7]= {-2, 11, -3, 13, -5, -20, 12};
	largest_subsum(a, 7);
}

void test_all_negative(){
	printf("test with all values negative: ");
	int a[7]= {-2, -3, -3, -4, -5, -20, -12};
	largest_subsum(a, 7);
}

void test_null(){
	printf("test with a null: ");
	int* a = NULL;
	largest_subsum(a, 7);
}

int main(int argc, char* argv[])
{

	test_nomal();
	test_all_negative();
	test_null();


	getchar();
	return 0;
}