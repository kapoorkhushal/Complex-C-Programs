#include"header.h"

int main(void)
{
	int ch;float num1,num2,num3;
	printf("\nAreas of ::\n1.Square\n2.Circle\n3.Triangle\nEnter Your Choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter Side :");
			scanf("%f",&num1);
			printf("\nArea : %f\n",square(num1));break;
		case 2:
			printf("Enter Radius :");
			scanf("%f",&num1);
			printf("\nArea : %f\n",circle(num1));break;
		case 3:
			printf("Enter Side1,Side 2,Side 3 :");
			scanf("%f%f%f",&num1,&num2,&num3);
			if(num1<=num2+num3 && num2<=num1+num3 && num3<=num2+num1)
				printf("\nArea : %f\n",triangle(num1,num2,num3));
			else
				printf("\nImpossible Triangle !\n");break;
		default:
			printf("\nInvalid Input !\n");
	}
	return 0;
}
