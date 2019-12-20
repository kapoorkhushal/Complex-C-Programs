#include"header.h"

int main(void)
{
	int i=0,lucky;
	char ch;
	node *head = NULL;
	printf("Do you want to Begin the Game [Y/N] : ");
	scanf("%c",&ch);
	if(ch == 'Y' || ch == 'y')
	{
		do{
			printf("\nEnter Name of participant %d : ",++i);
			getchar();
			fgets(input.name,20,stdin);
			int len = strlen(input.name);
			if('\n' == input.name[len-1])				//Removing new line character
				input.name[len-1] = '\0';
			insert(&head,input.name,i);
			printf("Do you want to continue [Y/N] : ");
			scanf("%c",&ch);
		}while(ch == 'Y' || ch == 'y');
		display(head);
		printf("Enter the Lucky Number : ");
		scanf("%d",&lucky);
		luckygame(&head,lucky);
	}
	return 0;
}

