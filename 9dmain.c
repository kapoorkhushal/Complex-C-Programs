#include"header.h"

int main(void)
{
	int A[10],B[15],i;
	printf("Enter elements for Array - A\n");
	for(i=0;i<10;i++)
	{
		printf("Enter element at position %d : ",i);
		scanf("%d",&A[i]);
	}printf("\n\n");
	printf("Enter elements for Array - B\n");
	for(i=0;i<15;i++)
	{
		printf("Enter element at position %d : ",i);
		scanf("%d",&B[i]);
	}printf("\n\n");
	display(A,B);
	common(A,B);
	return 0;
}

