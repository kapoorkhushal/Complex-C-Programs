#include"header.h"

int main(void)
{
	int ch;
	node *head = NULL;					//Top element of Linked List
	char exit;
	printf("\nMENU ::\n1. INSERT AT THE BEGINNING\n2. INSERT AT THE END\n3. INSERT AT THE MIDDLE\n4. DELETE FROM THE BEGINNING\n5. DELETE FROM THE END\n6. DELETE FROM THE MIDDLE\n7. DISPLAY\n");
	do{
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				datainput();
				insertbeg(&head,input.id,input.name);
				display(head);break;
			case 2:
				datainput();
				insertend(&head,input.id,input.name);
				display(head);break;
			case 3:
				datainput();
				insertmid(&head,input.id,input.name);
				display(head);break;
			case 4:
				printf("Deleted ID is : %d",deletebeg(&head));
				display(head);break;
			case 5:
				printf("Deleted ID is : %d",deleteend(&head));
				display(head);break;
			case 6:
				printf("\nEnter the ID you want to Delete : ");
				scanf("%d",&input.id);
				printf("Deleted ID is : %d",deletemid(&head,input.id));
				display(head);break;
			case 7:
				display(head);break;
			default:
				printf("\nInvalid Input !\n");
		}
		printf("\nDo you Want to Continue [Y/N] : ");
		scanf("%s",&exit);
	}while(exit == 'y' || exit == 'Y');
	freelist(&head);
	return 0;
}

