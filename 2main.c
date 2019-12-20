#include"header.h"

int main(void)
{
	int no;
	printf("\nEnter the Number :");
	scanf("%u",&no);
	printf("\nNumber in Binary form is : %d\n",binary(no));
	int zero=0,one=0;
	for(;j>=0;j--)
	{
		if(arr[j] == 0)
			zero++;
		else
			one++;
	}
	printf("\nZeros : %d\nOnes : %d\n\n",zero,one);
	return 0;
}
