#include"header.h"

int main(void)
{
	char ch;
	int choice;
	node input;
	node *front = NULL;
	node *rear = NULL;
	printf("\nMENU ::\n1.Insert into Que\n2.Deletion from the Que");
	do{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);while('\n' != getchar()){;}
		switch(choice)
		{
			case 1:
				printf("\nEnter name : ");
				fgets(input.name,19,stdin);
				if('\n' == input.name[strlen(input.name)-1])
					input.name[strlen(input.name)-1] = '\0';
				printf("\nEnter priority : ");
				scanf("%d",&input.priority);while('\n' != getchar()){;}
				enque(&front,&rear,input.priority,input.name);
				display(front,rear);break;
			case 2:
				deque(&front,&rear);
				display(front,rear);break;
			default:
				printf("\nInvalid Input !\n");
		}
		printf("\nDo you want to continue [Y/N] : ");
		scanf("%c",&ch);
	}while(ch == 'Y' || ch == 'y');
	return 0;
}

