#include"header.h"

int insert(node **head,char *str,int no)
{
	node *new;
	node *p;						//Used for trailing
	new = (node*) malloc(sizeof(node));
	if(NULL == new)						//M.A.F
	{
		printf("\nMemory Allocaion Failure !\n");
		return failure;
	}
	strcpy(new->name,str);
	new->num = no;
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
		printf("%d.  %s\n",p->num,p->name);
		p = p->next;
	}
	printf("%d.  %s\n",p->num,p->name);
	printf("\n");
	return success;
}

int luckygame(node **head,int num)
{
	node *p,*k;
	while(*head != p->next)
		p = p->next;
	*head = p;
	p = (*head)->next;
	k = *head;
	while(*head != p->next)
	{
		int no=1;
		while(no < num)
		{
			++no;
			k = p;
			p = p->next;
		}
		printf("Out Name : %s\n",p->name);
		k->next = p->next;
		free(p);
		p = k->next;
		*head = k;
		p = (*head)->next;
	}
	if(num%2 != 0)
		{k=k->next;p=p->next;}
	printf("Out Name : %s\n",k->name);
	free(k);
	k = NULL;
	printf("Winner : %s\n",p->name);
	free(p);
	p = NULL;
	*head = NULL;
	return success;
}
