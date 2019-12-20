#include"header.h"

void max(int *arr,int count)
{
	int max1=0,max2=0;
	for(int i=0;i<count;i++)
	{
		if(max1 <= *(arr+i))
		{
			max2 = max1;
			max1=*(arr+i);
		}
		else if(max2 <= *(arr+i) && max2<max1)
			max2 = *(arr+i);
	}	
	printf("\nMaxumum-1 : %d\nMaxumum-2 : %d\n",max1,max2);
}

void sorted(int *arr,int count)
{
	int flag =0;
	for(int i=0;i<count-1;i++)
	{
		if(*(arr)<*(arr+1))
		{
			if(*(arr+i)>=*(arr+i+1))
				{flag =1;break;}
		}
		else
		{
			if(*(arr+i)<=*(arr+i+1))
				{flag =1;break;}
		}
	}
	if(0 == flag)
		printf("\nArray is Sorted!\n");
	else
		printf("\nArray is not Sorted!\n");
}

void rotate(int *arr,int count)
{
	int num,swap;
	printf("\nEnter the Number by which you want to rotate : ");
	scanf("%d",&num);
	for(int j=0;j<num;j++)
	{
		swap = *arr;
		for(int i=0;i<count-1;i++)
			*(arr+i)=*(arr+i+1);
		*(arr+count-1)=swap;
	}printf("\n\nArray after Rotation :: \n");
	for(int i=0;i<count;i++)
		printf("%d\t",*(arr+i));
	printf("\n\n");
}

