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
}node;

//node *head = NULL;					//Top element of Linked List
node input;
void datainput();
int insertbeg(node**,int,char*);
int insertend(node**,int,char*);
int insertmid(node**,int,char*);
int deletebeg(node**);
int deleteend(node**);
int deletemid(node**,int);
int display(node*);
int freelist(node**);

