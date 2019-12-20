#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

typedef struct node
{
	char name[20];
	int id;
	struct node *next;
	struct node *prev;
}node;

node input;
void datainput();
int insertbeg(node**,node**,int,char*);
int insertend(node**,node**,int,char*);
int insertmid(node**,node**,int,char*);
int deletebeg(node**,node**);
int deleteend(node**,node**);
int deletemid(node**,node**,int);
int display(node*);
int freelist(node**);

