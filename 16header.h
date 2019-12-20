#include<stdio.h>
#include<stdlib.h>
#define success 1
#define failure -1

typedef struct node
{
	int cno;
	int eno;
	struct node *next;
}node;

int insert(node**,int,int);
int display(node*);
int derivative(node**,node**);
void freelist(node**,node**);

