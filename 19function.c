#include"header.h"

int push(node **top,char str1,int num)
{
	node *new;
	new = (node*)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure\n");
		return failure;
	}
	new->str = str1;
	new->id = num;
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

int pop(node **top)
{
	char str1;
	if(NULL == *top)
	{
		printf("\nStack is Empty !\n");
		return failure;
	}
	str1 = (*top)->str;
	if(1 != (*top)->id)
		printf("%c",str1);
	node *p = *top;
	if(NULL == p->next)			//Only one Item
	{
		*top = NULL;
	}
	else					//More than one item
	{
		*top = p->next;
	}
	free(p);
	p = NULL;
	return success;
}

int priority(char ch1)
{
	switch(ch1)
	{
		case '(':return 1;
		case '+':return 2;
		case '-':return 2;
		case '*':return 3;
		case '/':return 3;
		case '^':return 4;
		case ')':return 5;
	}
}

int conversion(node **top,char ch,int num)
{
	node *p = *top;
	if(num == 1)
		push(top,ch,num);
	else if(num == 5)
	{
		while(1 != p->id)
			{pop(top);p=*top;}
		pop(top);
	}
	else if(num <= p->id)
	{
		while(num <= p->id)
			{pop(top);p=*top;}
		push(top,ch,num);
	}
	else
		push(top,ch,num);
	return success;
}
