#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define success 1
#define failure -1

struct edgelist;
typedef struct gnode
{
	char data;
	struct gnode *next;
	struct edgelist *elist;
}gnode;

typedef struct edgelist
{
	struct gnode *list;
	struct edgelist *elist;
}edgelist;

int find(gnode*,gnode**,gnode**,char);
int insert_node(gnode**,char);
int find_edge(gnode*,edgelist**,edgelist**,char);
int insert_edge(gnode**,char,char);
int display(gnode*);

gnode *start = NULL;

int main(void)
{
	int choice;
	char ch,data1,data2;
	printf("\nMENU ::\n1.Insert NODE\n2.Insert Edge\n3.Display");
	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getchar();
				printf("Enter Node : ");
				scanf("%c",&data1);
				insert_node(&start,data1);
				break;
			case 2:
				getchar();
				printf("Enter Data1 : ");
				scanf("%c",&data1);
				getchar();
				printf("Enter Data2 : ");
				scanf("%c",&data2);
				insert_edge(&start,data1,data2);break;
			case 3:
				display(start);printf("\n\n");break;
		}
		getchar();
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');
	printf("\n\n");display(start);printf("\n\n");
	return 0;
}

int find(gnode *start,gnode **location,gnode **successor,char data)
{
	if(NULL == start)
	{
		*location = NULL;
		*successor = NULL;
		return success;
	}
	gnode *ptr = start;
	while(NULL != ptr)
	{
		if(data == ptr->data)
		{
			*location = ptr;
			return success;
		}
		*successor = ptr;
		ptr = ptr->next;
	}
	return failure;
}

int insert_node(gnode **start,char data)
{
	gnode *location = NULL,*successor = NULL;
	find(*start,&location,&successor,data);
	if(NULL != location)
	{
		printf("\nDuplicate Entry !\n");
		return failure;
	}
	gnode *new;
	new = (gnode*)malloc(sizeof(gnode));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure\n");
		return failure;
	}
	memset(new,0,sizeof(gnode));
	new->data = data;
	new->next = NULL;
	new->elist = NULL;
	if(NULL == successor)
		*start = new;
	else
		successor->next = new;
	return success;
}

int insert_edge(gnode **start,char data1,char data2)
{
	gnode *location1 = NULL,*location2 = NULL;
	gnode *successor1=NULL,*successor2 = NULL;
	find(*start,&location1,&successor1,data1);
	find(*start,&location2,&successor2,data2);
	if(NULL ==  location1 || NULL == location2)
	{
		printf("\nNode not Exist\nCannot create Connection !\n");
		return failure;
	}
	edgelist *sublocation = NULL,*esuccessor = NULL;
	find_edge(location1,&sublocation,&esuccessor,data2);
	if(NULL != sublocation)
	{
		printf("\nConnection already exist !\n");
		return failure;
	}
	edgelist *new;
	new = (edgelist*)malloc(sizeof(edgelist));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure !\n");
		return failure;
	}
	new->elist = NULL;
	if(NULL == esuccessor)
		location1->elist = new;
	else
		esuccessor->elist = new;
	new->list = location2;
	return success;
}

int find_edge(gnode *head,edgelist **sublocation,edgelist **esuccessor,char data)
{
	edgelist *eptr = head->elist;
	if(NULL == eptr)
	{
		*sublocation = NULL;
		*esuccessor = NULL;
		return failure;
	}
	while(NULL != eptr)
	{
		if(data == eptr->list->data)
		{
			*sublocation = eptr;
			return failure;
		}
		*esuccessor = eptr;
		eptr = eptr->elist;
	}
	*sublocation = NULL;
	return success;
}

int display(gnode *start)
{
	gnode *gptr = start;
	edgelist *eptr;
	while(NULL != gptr)
	{
		printf("%c",gptr->data);
		eptr = gptr->elist;
		while(NULL != eptr)
		{
			printf("-->%c",eptr->list->data);
			eptr = eptr->elist;
		}
		printf("\n|\n|\n");
		gptr = gptr->next;
	}
	return success;
}

