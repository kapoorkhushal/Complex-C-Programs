#include"header.h"

void datainput()
{
	printf("\nEnter the Unique ID : ");
	scanf("%d",&input.id);
	printf("\nEnter the Name : ");
	getchar();
	fgets(input.name,20,stdin);
	int len = strlen(input.name);
	if('\n' == input.name[len-1])				//Removing new line character
		input.name[len-1] = '\0';
}

int insertbeg(node **head,int item,char* str)			//To Insert an Item in the beginning of LL
{
	node* new;						//Inserting New Node in LL
	new = (node*) malloc(sizeof(node));			//Dynamic Memory Allocation
	if(NULL == new)						//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->id = item;
	strcpy(new->name,str);
	if(NULL == *head)					//Empty LIST
	{
		//new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
	return success;
}

int insertend(node **head,int item,char* str)		//To Insert an Item in the end of LL
{
	node* new;					//Inserting New Node in LL
	node *p;					//Used for Traversal to the End
	new = (node*) malloc(sizeof(node));		//Dynamic Memory Allocation
	if(NULL == new)					//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->id = item;
	strcpy(new->name,str);
	if(NULL == *head)				//Empty LIST
	{
		//new->next = NULL;
		*head = new;
	}
	else
	{
		p = *head;
		while(NULL != p->next)
		{
			p = p->next;
		}
		p->next = new;
	}
	return success;
}

int insertmid(node **head,int item,char* str)		//To Insert an Item in the middle of LL
{
	node* new;					//Inserting New Node in LL
	node *p,*q;					//Used for Traversal
	new = (node*) malloc(sizeof(node));		//Dynamic Memory Allocation
	if(NULL == new)					//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->id = item;
	strcpy(new->name,str);
	if(NULL == *head)				//Empty LIST
	{
		//new->next = NULL;
		*head = new;
	}
	if(item < (*head)->id)				//Item inserted is less than the First element
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		p = (*head)->next;
		q = *head;
		while(item > p->id && p->next != NULL)
		{
			q=p;
			p = p->next;
		}
		if(item > p->id && p->next == NULL)	//For the Last Element
		{
			p->next = new;
			new->next = NULL;
		}
		else
		{
			new->next = p;
			q->next = new;
		}
	}
	return success;
}

int deletebeg(node **head)				//Deleting node from the Beginning
{
	node *p;
	int item;
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return failure;
	}
	p=*head;
	item = p->id;
	if(NULL == p->next)				//Only Node
	{
		printf("Name : %s\n",p->name);
		*head = NULL;
	}
	else						//Non-Empty List
	{
		printf("Name : %s\n",p->name);
		*head = p->next;
	}
	free(p);
	p = NULL;
	return item;
}

int deleteend(node **head)				//Deleting node from the End
{
	node *p;					//Used for Traversal
	node *q;					//Used to set the 2nd last element's next equal to NULL
	int item;
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return failure;
	}
	p=*head;
	if(NULL == p->next)				//Only Node
	{
		printf("Name : %s\n",p->name);
		*head = NULL;
	}
	else						//Non-Empty List
	{
		q=p;
		while(p->next != NULL)
		{
			q=p;
			p = p->next;
		}
		printf("Name : %s\n",p->name);
		q->next = NULL;
		item = p->id;
	}
	free(p);
	p = NULL;
	return item;
}

int deletemid(node **head,int item)			//Deleting node from the Middle
{
	node *p;					//Used for Traversal
	node *q;					//Used to set the 2nd last element's next equal to NULL
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return failure;
	}
	p=*head;
	if(NULL == p->next && item == (*head)->id)	//Only Node
	{
		printf("Name : %s\n",p->name);
		*head = NULL;
		free(p);
		p = NULL;
		return item;

	}
	else if(item == p->id)				//ID found in the Beginning
	{
		*head = p->next;
		printf("Name : %s\n",p->name);
		free(p);
		p = NULL;
		return item;
	}
	else if(item > p->id)				//Checking ID in the Remaining
	{
		q=p;
		while(item > p->id && p->next != NULL)
		{
			q=p;
			p = p->next;
		}
		if(item == p->id && p->next == NULL)	//If its the Last Element
		{
			printf("Name : %s\n",p->name);
			q->next = NULL;
			free(p);
			p = NULL;
			return item;
		}
		else if(item == p->id)			//If not the Last
		{
			printf("Name : %s\n",p->name);
			q->next = p->next;
			free(p);
			p = NULL;
			return item;
		}
	}
	if(p != NULL)					//Otherwise Not Found
	{
		printf("\nID Not Found !\n");
		return failure;
	}
}

int display(node *head)					//To display the List
{
	node *p;
	p=head;
	if(NULL == p)
		printf("\nList is Empty !\n");
	while(NULL != p)
	{
		printf("\nName : %s\t\tID : %d\n",p->name,p->id);
		p = p->next;
	}
	return success;
}

int freelist(node **head)				//To Free Memory
{
	node *p;
	p=*head;
	while(NULL != p)
	{
		*head = (*head)->next;
		free(p);
		p = *head;
	}
	return success;
}
