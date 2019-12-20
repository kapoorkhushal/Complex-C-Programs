#include"header.h"

void input(int (*arr)[10],int count)
{
	for(int i=0;i<count;i++)
		for(int j=0;j<count;j++){
			printf("Enter element at position [%d][%d] : ",i,j);
			scanf("%d",(*(arr+i)+j));
		}
}

void display(int (*arr)[10],int count)
{
	for(int i=0;i<count;i++){
		for(int j=0;j<count;j++)
			printf("%d\t",*(*(arr+i)+j));
		printf("\n");
	}printf("\n\n\n");
}

void magic(int (*arr)[10],int count)
{
	int size = 2*count+2;
	int row=0,col=0,diag=0;
	int marr[size];
	memset(marr,0,size*sizeof(int));
	for(int k=0;k<size;k++)
	{
		for(int i=0;i<count;i++)
			for(int j=0;j<count;j++)
			{
				if(i == row && row<count)
					marr[k] += *(*(arr+i)+j);
				else if(j == col-count && col<2*count && col>count-1)
					marr[k] += *(*(arr+i)+j);
				else if(i==j && diag==2*count)
					marr[k] += *(*(arr+i)+j);
				else if(count-1 == i+j && diag==2*count+1)
					marr[k] += *(*(arr+i)+j);
			}
		row++;col++;diag++;
	}
	int flag = 0;
	for(int k=0;k<size-1;k++)			//check here for row & column
	{
		if(marr[k] == marr[k+1])
			flag = 1;
		else
		{
			flag = 0;break;
		}
	}
	if(flag == 1)
		printf("Matrix is a Magic Matrix !");
	else
		printf("Matrix is not a Magic Matrix !");
	printf("\n\n");
}
