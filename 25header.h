#include<stdio.h>
#include<stdlib.h>
#define success 1
#define failure -1

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

typedef struct qnode
{
	node* element;
	struct qnode *next;
}qnode;

int find(node*,node**,node**,int);
int insert(node**,int);
int delete(node**,int);
int delete_1_child(node**,node*,node*);
int delete_2_child(node**,node*,node*);
int display(node*,int);
int preorder(node*);
int inorder(node*);
int postorder(node*);
int levelorder(node*);
int enque(qnode**,qnode**,node*);
node* deque(qnode**,qnode**);
int free_mem(node*);
