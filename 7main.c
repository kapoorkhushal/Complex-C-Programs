#include"header.h"

int main(void)
{
	int num,ch,y;
	char str='Y';
	timestamp();
	while(str=='Y' || str=='y')
	{
		printf("\n1. Celcius to Fahrenheit \n2. Prime Number \n3. Reverse of Number \n\nEnter your Choice :");
		scanf("%d",&ch);
		printf("\nEnter the Number : ");
		scanf("%d",&num);
		switch (ch)
		{
			case 1: printf("\nFahrenheit : %f\n",celcius(num));break;
			case 2: prime(num);break;
			case 3: printf("\nReverse of Number : %d\n",reverse(num));break;
			default : printf("\nInvalid Input !\n");
		}
		printf("\nDo you want to Continue (y/n) : ");
		scanf("%s",&str);
	}	
	return 0;
}

