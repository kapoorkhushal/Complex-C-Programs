#include"header.h"

int main(void)
{
	char ch;
	int no1,no2,i=0;
	node *head = NULL;				//for Original Expression
	node *dhead = NULL;				//for Derived Expression
	printf("Enter the polynomial :\n");
	do{
		printf("\nEnter the coefficient of expression %d :",++i);
		scanf("%d",&no1);
		printf("\nEnter the exponential of expression %d :",i);
		scanf("%d",&no2);
		insert(&head,no1,no2);
		printf("\nDo you want to continue [Y/N] :");
		scanf("%s",&ch);
	}while(ch == 'y' || ch == 'Y');
	printf("\nPolynomial : ");display(head);
	derivative(&head,&dhead);
	printf("\nDerivative : ");display(dhead);
	freelist(&head,&dhead);
	return 0;
}

