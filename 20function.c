#include"header.h"

int enque(char *q[],int *front,int *rear,char* name)
{
	if((*rear+1)%MAX == *front)			//QUE OVERFLOW 
	{
		printf("\nQue is Full !\n");
		return failure;
	}
	if(empty == *front)
	{
		*front = 0;
		*rear = 0;
	}
	else
		*rear = (*rear + 1)%MAX;
	q[*rear] = (char*)malloc(strlen(name)*sizeof(char)+1);
	memset(q[*rear],0,strlen(name)*sizeof(char)+1);
	strncpy(q[*rear],name,strlen(name));
	return success;
}

int deque(char *q[],int *front,int *rear)
{
	if(empty == *front)				//Empty Que
	{
		printf("Que is Empty !\n");
		return failure;
	}
	if(*front == *rear)				//Only one Item
	{
		printf("%s\n",q[*front]);
		free(q[*front]);
		q[*front] = NULL;
		*front=*rear=empty;
	}
	else
	{
		printf("%s\n",q[*front]);
		free(q[*front]);
		q[*front] = NULL;
		*front = (*front + 1)%MAX;
	}
	return success;
}
