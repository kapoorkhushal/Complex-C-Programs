#include"header.h"

int string_add(char *name)
{
	int sum = 0;
	int len = strlen(name);
	for(int i = 0;i<len;i++)
		sum += *(name+i);
	return sum;
}

void insert(char *str,int location,hash **arr)
{
	hash* new;
	new = (hash*)malloc(sizeof(hash));
	if(NULL == new)
	{
		printf("\nMemory Allocation Failure !\n");
		exit(-1);
	}
	memset(new,0,sizeof(hash));
	new->name = (char*)malloc(strlen(str)*sizeof(char));
	memset(new->name,0,strlen(str));
	strncpy(new->name,str,strlen(str));
	new->next = NULL;
	hash *ptr;
	ptr = arr[location];
	if(NULL == ptr)
		arr[location] = new;
	else
	{
		while(NULL != ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void display(hash** arr)
{
	int collision = 0;
	printf("\n\n");
	for(int i=0;i<10;i++)
	{
		printf("%d) ",i+1);
		if(NULL != arr[i])
		{
			printf("%s",arr[i]->name);
			hash *ptr = arr[i];
			while(NULL != ptr->next)
			{
				collision++;
				ptr = ptr->next;
				printf("--> %s",ptr->name);
			}
		}printf("\n");
	}
	printf("Number of Collisions : %d",collision);
	printf("\n\n");
}

void free_arr(hash* arr[])
{
	for(int i=0;i<MAX;i++)
	{
		if(NULL != arr[i]->next)
			free_chain(arr[i]);
		free(arr[i]->name);
		free(arr[i]);
		arr[i] = NULL;
	}
}

int free_chain(hash* node)
{
	while(NULL == node)
		return -1;
	free_chain(node->next);
	free(node->name);
	free(node);
	node = NULL;
}
