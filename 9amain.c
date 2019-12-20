#include"header.h"

int main(void)
{
	int Arr[20];
	static int count=0;
	char ch;
	do{
		printf("\nEnter the number :");
		scanf("%d",&Arr[count]);
		count++;
		printf("Do you want to continue [Y/N] : ");
		scanf("%s",&ch);
	}while(ch == 'y' || ch == 'Y');
	printf("\nOriginal Array :: \n");
	for(int i=0;i<count;i++)
		printf("%d\t",*(Arr+i));
	printf("\nCount : %d",count);
	max(Arr,count);
	sorted(Arr,count);
	rotate(Arr,count);
	return 0;
}

