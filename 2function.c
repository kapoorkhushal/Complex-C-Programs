#include"header.h"

int binary(int no)
{
	int i=0;
	while(no>1)
	{
		arr[i++] = no%2;
		no /= 2;
	}arr[i] = 1;
	int num1=0;
	j=i;
	while(i>=0)
	{
		num1 = num1*10 + arr[i];
		i--;
	}return num1;
}

