#include "header.h"

int main(void)
{
	node *root = NULL;
	int item,choice;
	char ch;
	printf("\nMENU ::\n1.Insert into Tree\n2.Delete Element from Tree\n3.Display Tree\n4.PreOrder Display\n5.InOrder Display\n6.PostOrder Display\n7.Level Order");
	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Number : ");
				scanf("%d",&item);
				insert(&root,item);
				break;
			case 2:
				printf("Enter Number to Delete : ");
				scanf("%d",&item);
				delete(&root,item);break;
			case 3:
				display(root,5);printf("\n\n");break;
			case 4:
				printf("\nPre-Order Traversal : ");
				preorder(root);printf("\n");break;
			case 5:
				printf("\nIn-Order Traversal : ");
				inorder(root);printf("\n");break;
			case 6:
				printf("\nPost-Order Traversal : ");
				postorder(root);printf("\n");break;
			case 7:
				printf("\nLevel-Order Traversal : ");
				levelorder(root);printf("\n");break;
			default:
				printf("\nInvalid Input !\n");break;
		}
		getchar();
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');
	display(root,5);printf("\n\n");
	free_mem(root);
	return 0;
}

