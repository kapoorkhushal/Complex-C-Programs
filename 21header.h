#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

typedef struct node
{
	int priority;
	char name[20];
	struct node *next;
}node;

int enque(node**,node**,int,char*);
int display(node*,node*);
int deque(node**,node**);

