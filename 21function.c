#include"header.h"

int enque(node **front,node **rear,int pnum,char *data)
{
	node *new,*q,*p = *front;
	new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure !\n");
		return failure;
	}
	memset(new,0,sizeof(node));
	new->priority = pnum;
	strncpy(new->name,data,strlen(data));
	if(NULL == *front)					//Que is empty
	{
		*front = new;
		*rear = new;
		new->next = NULL;
	}
	else if((*front)->priority > new->priority)
	{
		new->next = *front;
		*front = new;
	}
	else if((*rear)->priority < new->priority)
	{
		(*rear)->next = new;
		new->next = NULL;
		*rear = new;
	}
	else
	{
		q = p;
		while(new->priority > p->priority)
		{
			q = p;
			p = p->next;
		}
		q->next = new;
		new->next = p;
	}
	return success;
}

int display(node *front,node *rear)
{
	node *p = front;
	printf("\n**********************************************************\n");
	if(NULL == front)
	{
		printf("\nQue is Empty !\n");
		return failure;
	}
	while(rear != p)
	{
		printf("\nPriority : %d\nName : %s\n",p->priority,p->name);
		p = p->next;
	}
	printf("\nPriority : %d\nName : %s\n",p->priority,p->name);
	printf("\n**********************************************************\n");
	return success;
}

int deque(node **front,node **rear)
{
	node *p = *front;	
	if(NULL == *front)					//Que is Empty
	{
		printf("\nQue is Empty !\n");
		return failure;
	}
	printf("\nPopped Item ::\nPriority : %d\nName : %s\n",p->priority,p->name);
	if(*front == *rear)					//Only single Item
	{
		free(p);
		p = NULL;
		*front = *rear = NULL;
	}
	else
	{
		*front = p->next;
		free(p);
		p = NULL;
	}
	return success;
}
