#include"header.h"

int push(node **top,char item)
{
	node *new;
	new = (node*) malloc(sizeof(node));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure\n");
		return -1;
	}
	new->data = item;
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
	return 1;
}

char pop(node **top)
{
	char str;
	if(NULL == *top)
	{
		printf("\nStack is Empty !\n");
		return -1;
	}
	str = (*top)->data;
	node *p = *top;
	if(NULL == p->next)
		*top = NULL;
	else
		*top = p->next;
	free(p);
	p = NULL;
	return str;
}
