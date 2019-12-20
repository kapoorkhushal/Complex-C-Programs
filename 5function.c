#include"header.h"

int selection(int no1,int no2,int ch)
{
	switch(ch)
	{
		case 1:
			no1=addition(no1,no2);
			printf("Enter the Number2 :");
			scanf("%d",&no2);
			return addition(no1,no2);break;
		case 2:
			no1=addition(no1,no2);
			printf("\nEnter the Number2 :");
			scanf("%d",&no2);
			return subtraction(no1,no2);break;
		case 3:
			no1=addition(no1,no2);
			printf("\nEnter the Number2 :");
			scanf("%d",&no2);
			return multiplication(no1,no2);break;
		case 4:
			no1=addition(no1,no2);
			printf("\nEnter the Number2 :");
			scanf("%d",&no2);
			return division(no1,no2);break;
	}
}

int addition(int no1,int no2)
{
	return no1+no2;
}

int subtraction(int no1,int no2)
{
	return no1-no2;
}

int multiplication(int no1,int no2)
{
	return no1*no2;
}

float division(int no1,int no2)
{
	return no1/no2;
}
