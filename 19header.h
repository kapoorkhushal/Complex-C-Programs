#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

typedef struct node
{
	char str;
	int id;
	struct node *next;
}node;

int push(node**,char,int);
int pop(node**);
int priority(char);
int conversion(node**,char,int);

