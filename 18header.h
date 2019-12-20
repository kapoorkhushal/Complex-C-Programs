#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}node;

//node *top = NULL;
int push(node**,char);
char pop(node**);
