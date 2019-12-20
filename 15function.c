#include"header.h"

void datainput()
{
	printf("\nEnter the Unique ID : ");
	scanf("%d",&input.id);
	printf("\nEnter the Name : ");
	getchar();
	fgets(input.name,20,stdin);
	int len = strlen(input.name);
	if('\n' == input.name[len-1])
		input.name[len-1] = '\0';
}

int insertbeg(node **head,node **tail,int item,char* str)		//To Insert an Item in the beginning of LL
{
	node* new;					//Inserting New Node in LL
	new = (node*) malloc(sizeof(node));		//Dynamic Memory Allocation
	if(NULL == new)					//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->id = item;
	strcpy(new->name,str);
	new->prev = NULL;				//By Default
	if(NULL == *head)				//Empty LIST so Only Node
	{
		new->next = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		//new->prev = NULL;
		*head = new;
	}
	return success;
}

int insertend(node **head,node **tail,int item,char* str)		//To Insert an Item in the end of LL
{
	node* new;					//Inserting New Node in LL  //No Traversal required due to presence of Tail
	new = (node*) malloc(sizeof(node));		//Dynamic Memory Allocation
	if(NULL == new)					//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->id = item;
	strcpy(new->name,str);
	new->next = NULL;				//By Default
	if(NULL == *head)				//Empty LIST so Only Node
	{
		new->prev = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
	return success;
}

int insertmid(node **head,node **tail,int item,char* str)		//To Insert an Item in the middle of LL
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
	if(NULL == *head)				//Empty LIST so Only Node
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		*tail = new;
	}
	if(item < (*head)->id)				//Item inserted is less than the First element
	{
		new->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	else if(item > (*tail)->id)			//Item to be inserted is bigger than the last item
	{
		new->next = NULL;
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
	else
	{
		p = *head;
		q = NULL;
		while(item > p->id)
		{
			p = p->next;
		}
		q = p->prev;
		q->next = new;
		new->prev = q;
		new->next = p;
		p->prev = new;
	}
	return success;
}

int deletebeg(node **head,node **tail)			//Deleting node from the Beginning
{
	node *p;
	int item;
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return -failure;
	}
	p=*head;
	item = p->id;
	if(*head == *tail)				//Only Node
	{
		printf("Name : %s\n",p->name);
		*head = NULL;
		*tail = NULL;
	}
	else						//Non-Empty List
	{
		printf("Name : %s\n",p->name);
		*head = p->next;
		(*head)->prev = NULL;
	}
	free(p);
	p = NULL;
	return item;
}

int deleteend(node **head,node **tail)			//Deleting node from the End
{
	node *p;					//Used to set the Last Element
	int item;
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return failure;
	}
	p=*tail;
	if(*head == *tail)				//Only Node
	{
		printf("Name : %s\n",p->name);
		*head = NULL;
		*tail = NULL;
	}
	else						//Non-Empty List
	{
		printf("Name : %s\n",p->name);
		*tail = p->prev;
		(*tail)->next = NULL;
	}
	free(p);
	p = NULL;
	return item;
}

int deletemid(node **head,node **tail,int item)		//Deleting node from the Middle
{
	node *p;					//Used for Deletion & Check
	node *q,*r;					//Used for Deletion of In-Between Node
	if(NULL == *head)				//Empty List
	{
		printf("\nList is empty\n");
		return failure;
	}
	if(item < (*head)->id || item > (*tail)->id)	//Item is less than Top or greater than Bottom
	{
		printf("\nID Not Found !\n");
		return failure;
	}
	p=*head;
	if(item == p->id)				//If item is the First Item
	{
		printf("Name : %s\n",p->name);
		if(p->next == NULL)			//First,Last & Only Item
		{
			*head = NULL;
			*tail = NULL;
		}
		else					//Otherwise First
		{
			*head = p->next;
			(*head)->prev = NULL;
		}
		free(p);
		p = NULL;
		return item;
	}
	p = *tail;
	if(item == p->id)				//ID found at the Bottom
	{
		printf("Name : %s\n",p->name);
		*tail = p->prev;
		(*tail)->next = NULL;
		free(p);
		p = NULL;
		return item;
	}
	p = (*head)->next;
	while(item > p->id && NULL != p->next)		//Checking ID in the Remaining
	{
		p = p->next;
	}	
	if(item == p->id)
	{
		printf("Name : %s\n",p->name);
		q = p->prev;
		r = p->next;
		q->next = r;
		r->prev = q;
		free(p);
		p = NULL;
		return item;
	}
	else						//Otherwise Not Found
	{	printf("\nID Not Found !\n");
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
