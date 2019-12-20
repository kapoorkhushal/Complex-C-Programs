#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

typedef struct node
{
	char name[20];
	int num;
	struct node *next;
}node;

node input;
int insert(node**,char*,int);
int display(node*);
int luckygame(node**,int);

