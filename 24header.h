#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define success 1
#define failure -1

typedef struct node
{
	char* name;
	struct node *left;
	struct node *right;
}node;

int find(node*,node**,node**,char*);
int insert(node**,char*);
int insert_file(node*,FILE*);
int free_mem(node*);

