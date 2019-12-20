#include"header.h"

int main(void)
{
	int num1,ch;
	char ans;
	do{
//	system("clear");
	printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter choice :");
	scanf("%d",&ch);
	if(ch<0 ||  ch>4){
		printf("\nInvalid Input!\nKindly Enter as per the given choices\n");
		main();
	}
		printf("\nEnter the Number1 :");
		scanf("%d",&num1);
		printf("Answer : %d\n",selection(num1,0,ch));
		printf("Do you want to continue (Y/N) :");
		scanf("%s",&ans);
	}while(ans == 'y' || ans == 'Y');
	return 0;
}

