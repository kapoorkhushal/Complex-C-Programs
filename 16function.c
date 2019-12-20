#include"header.h"

int insert(node **head,int no1,int no2)
{
	node *new;
	node *p;						//Used for trailing
	new = (node*) malloc(sizeof(node));
	if(NULL == new)						//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	new->cno = no1;
	new->eno = no2;
	if(NULL == *head)					//List is Empty
	{
		new->next = new;
		*head = new;
	}
	else
	{
		p = *head;
		while(*head != p->next)
			p = p->next;
		p->next = new;
		new->next = *head;
	}
	return success;
}

int display(node *head)
{
	node *p;
	p=head;
	if(NULL == p)
	{
		printf("\nList is Empty !\n");
		return failure;
	}
	while(head != p->next)
	{
		printf("%d(x^%d) + ",p->cno,p->eno);
		p = p->next;
	}
	printf("%d(x^%d) ",p->cno,p->eno);
	printf("\n");
	return success;
}

int derivative(node **head,node **dhead)
{
	node *dnew;
	node *p,*q;						//Used for trailing
	if(NULL == dnew)						//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	p = *head;
	do{
		dnew = (node*) malloc(sizeof(node));
		dnew->cno = (p->cno) * (p->eno);
		dnew->eno = (p->eno)-1;
		p = p->next;
		if(NULL == *dhead)
		{
			dnew->next = dnew;
			*dhead = dnew;
		}
		else
		{
			q = *dhead;
			while(*dhead != q->next)
				q = q->next;
			q->next = dnew;
			dnew->next = *dhead;
		}
	}while(*head != p);
	return success;
}

void freelist(node **head,node **dhead)
{
	node *p=*head;
	node *q=*dhead;
	while(*head != p->next)
	{
		*head = (*head)->next;
		free(p);
		p = *head;
	}
	free(p);
	p = NULL;
	while(*dhead != q->next)
	{
		*dhead = (*dhead)->next;
		free(q);
		q = *dhead;
	}
	free(q);
	q = NULL;
	*head = NULL;
	*dhead = NULL;
}
