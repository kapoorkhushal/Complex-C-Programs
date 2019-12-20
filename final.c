#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

struct edgelist;
typedef struct gnode
{
	char data;
	struct gnode *next;
	struct edgelist *elist;
}gnode;

typedef struct edgelist
{
	struct gnode *list;
	struct edgelist *elist;
}edgelist;

typedef struct qnode
{
	gnode* element;
	struct qnode *next;
}qnode;

typedef struct snode
{
	gnode *element;
	struct snode *next;
}snode;

int find(gnode*,gnode**,gnode**,char);
int insert_node(gnode**,char);
int find_edge(gnode*,edgelist**,edgelist**,char);
int insert_edge(gnode**,char,char);
int display(gnode*);
int enque(qnode**,qnode**,gnode*);
gnode* deque(qnode**,qnode**);
int breadth(gnode*,char);
int status1(qnode*,char);
int push(snode **top,gnode *item);
gnode *pop(snode**);
int depth(gnode*,char);

gnode *start = NULL;
qnode *front = NULL;
qnode *rear = NULL;
snode *top = NULL;

int main(void)
{
	int choice;
	char ch,data1,data2;
	printf("\nMENU ::\n1.Insert NODE\n2.Insert Edge\n3.Display\n4.BFS\n5.DFS");
	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getchar();
				printf("Enter Node : ");
				scanf("%c",&data1);
				insert_node(&start,data1);
				break;
			case 2:
				getchar();
				printf("Enter Data1 : ");
				scanf("%c",&data1);
				getchar();
				printf("Enter Data2 : ");
				scanf("%c",&data2);
				insert_edge(&start,data1,data2);break;
			case 3:
				display(start);printf("\n\n");break;
			case 4:
				getchar();
				printf("Enter Starting Node : ");
				scanf("%c",&data1);
				getchar();
				printf("Enter Ending Node : ");
				scanf("%c",&data2);
				gnode *location = NULL,*successor = NULL;
				find(start,&location,&successor,data1);
				if(NULL == location)
				{
					printf("\nCannot find Starting Node !\n");
					exit(-1);
				}
				breadth(location,data2);break;
			case 5:
				getchar();
				printf("Enter Starting Node : ");
				scanf("%c",&data1);
				getchar();
				printf("Enter Ending Node : ");
				scanf("%c",&data2);
				gnode *dlocation = NULL,*dsuccessor = NULL;
				find(start,&dlocation,&dsuccessor,data1);
				if(NULL == dlocation)
				{
					printf("\nCannot find Starting Node !\n");
					exit(-1);
				}
				depth(dlocation,data2);break;
		}
		getchar();
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');
	printf("\n\n");display(start);printf("\n\n");
	return 0;
}

int find(gnode *start,gnode **location,gnode **successor,char data)
{
	if(NULL == start)
	{
		*location = NULL;
		*successor = NULL;
		return success;
	}
	gnode *ptr = start;
	while(NULL != ptr)
	{
		if(data == ptr->data)
		{
			*location = ptr;
			return success;
		}
		*successor = ptr;
		ptr = ptr->next;
	}
	return failure;
}

int insert_node(gnode **start,char data)
{
	gnode *location = NULL,*successor = NULL;
	find(*start,&location,&successor,data);
	if(NULL != location)
	{
		printf("\nDuplicate Entry !\n");
		return failure;
	}
	gnode *new;
	new = (gnode*)malloc(sizeof(gnode));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure\n");
		return failure;
	}
	memset(new,0,sizeof(gnode));
	new->data = data;
	new->next = NULL;
	new->elist = NULL;
	if(NULL == successor)
		*start = new;
	else
		successor->next = new;
	return success;
}

int insert_edge(gnode **start,char data1,char data2)
{
	gnode *location1 = NULL,*location2 = NULL;
	gnode *successor1=NULL,*successor2 = NULL;
	find(*start,&location1,&successor1,data1);
	find(*start,&location2,&successor2,data2);
	if(NULL ==  location1 || NULL == location2)
	{
		printf("\nNode not Exist\nCannot create Connection !\n");
		return failure;
	}

/*	edgelist *eptr = location1->elist;
	edgelist *esuccessor = NULL;
	while(NULL != eptr)
	{
		if(data2 == eptr->list->data)
		{
			printf("\nConnection already Exist !\n");
			return failure;
		}
		esuccessor = eptr;
		eptr = eptr->elist;
	}
*/

	edgelist *sublocation = NULL,*esuccessor = NULL;
	find_edge(location1,&sublocation,&esuccessor,data2);
	if(NULL != sublocation)
	{
		printf("\nConnection already exist !\n");
		return failure;
	}
	edgelist *new;
	new = (edgelist*)malloc(sizeof(edgelist));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure !\n");
		return failure;
	}
	new->elist = NULL;
	if(NULL == esuccessor)
		location1->elist = new;
	else
		esuccessor->elist = new;
	new->list = location2;
	return success;
}

int find_edge(gnode *head,edgelist **sublocation,edgelist **esuccessor,char data)
{
	edgelist *eptr = head->elist;
	if(NULL == eptr)
	{
		*sublocation = NULL;
		*esuccessor = NULL;
		return failure;
	}
	while(NULL != eptr)
	{
		if(data == eptr->list->data)
		{
			*sublocation = eptr;
			return failure;
		}
		*esuccessor = eptr;
		eptr = eptr->elist;
	}
	*sublocation = NULL;
	return success;
}

int display(gnode *start)
{
	gnode *gptr = start;
	edgelist *eptr;
	while(NULL != gptr)
	{
		printf("%c",gptr->data);
		eptr = gptr->elist;
		while(NULL != eptr)
		{
			printf("-->%c",eptr->list->data);
			eptr = eptr->elist;
		}
		printf("\n|\n|\n");
		gptr = gptr->next;
	}
	return success;
}

int enque(qnode** front,qnode** rear,gnode* item)
{
	qnode *new;
	new = (qnode*) malloc(sizeof(qnode));
	if(NULL == new)
	{
		printf("\nMemory Allocation Faliure !\n");
		return failure;
	}
	new->element = item;
	new->next = NULL;
	if(NULL == *front)
	{
		*front = new;
		*rear = new;
	}
	else
	{
		(*rear)->next = new;
		*rear = new;
	}
	return success;
}

gnode* deque(qnode** front,qnode** rear)
{
	gnode *item;
	item = (*front)->element;
	if(NULL == *front)
		exit(-1);
	else if(*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
		*front = (*front)->next;
	printf("%c\t",item->data);
	return item;
}

int breadth(gnode *head,char data)
{
	gnode *gptr = head;
	edgelist *eptr;
	enque(&front,&rear,gptr);
	while(NULL != gptr && data != gptr->data)
	{
		eptr = gptr->elist;
		while(NULL != eptr)
		{
			if(success == status1(front,eptr->list->data))
				enque(&front,&rear,eptr->list);
			eptr = eptr->elist;
		}
		gptr = deque(&front,&rear);
	}
	return success;
}

int status1(qnode *front,char data)
{
	qnode *ptr = front;
	while(NULL != ptr)
	{
		if(data == ptr->element->data)
			return failure;
		ptr = ptr->next;
	}
	return success;
}

int push(snode **top,gnode *item)
{
	snode *new;
	new = (snode*)malloc(sizeof(snode));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure\n");
		return failure;
	}
	new->element = item;
	if(NULL == *top)
	{
		*top = new;
		new->next = NULL;
	}
	else
	{
		new->next = *top;
		*top = new;
	}
	return success;
}

gnode *pop(snode **top)
{
	gnode *item;
	if(NULL == *top)
	{
		printf("\nStack is Empty !\n");
		exit(-1);
	}
	item = (*top)->element;
	snode *p = *top;
	if(NULL == p->next)			//Only one Item
		*top = NULL;
	else					//More than one item
		*top = p->next;
	printf("%c\t",item->data);
	return item;
}

int depth(gnode *head,char data)
{
	gnode *gptr = head;
	edgelist *eptr;
	push(&top,gptr);
	printf("%c\t",gptr->data);
	while(NULL != gptr && data != gptr->data)
	{
		eptr = gptr->elist;
		while(NULL != eptr)
		{
			if(success == status1((qnode*)top,eptr->list->data))
				push(&top,eptr->list);
			eptr = eptr->elist;
		}
		gptr = pop(&top);
	}
	return success;
}

