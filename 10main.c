#include"header.h"

int main(void)
{
	int (*Arr)[10],num;
	int (*temp)[10];
	printf("\nEnter the size of Matrix : ");
	scanf("%d",&num);
	temp = (int (*) [10])malloc(num*num*sizeof(int));
	if(NULL == temp){
		printf("\nMemory Allocation Failure !\n");
		exit(0);
	}
	Arr = temp;
	memset(Arr,0,num*num*sizeof(int));
	input(Arr,num);
	display(Arr,num);
	magic(Arr,num);
	free(Arr);
	return 0;
}

