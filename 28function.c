#include"header.h"

int getdata(presence *p)
{
	printf("\nEnter Presence ID : ");
	scanf("%d",&(*p).p_id);
	getchar();
	printf("Enter Name : ");
	p->name = (char*)malloc(20*sizeof(char));
	memset(p->name,0,20);
	fgets(p->name,20,stdin);
	p->name[strlen(p->name)-1] = '\0';

	printf("Enter Device ID : ");
	scanf("%d",&(*p).d.device_id);
	getchar();
	printf("Enter Device Type : ");
	(*p).d.device_type = (char*)malloc(20*sizeof(char));
	memset(p->d.device_type,0,20);
	fgets(p->d.device_type,20,stdin);
	p->d.device_type[strlen(p->d.device_type)-1] = '\0';
	return p->p_id;
}

void insert(presence* ptr,int location,presence **arr)
{
	presence* p;
	p = arr[location];
	if(NULL == p)
		arr[location] = ptr;
	else
	{
		while(NULL != p->next)
			p = p->next;
		p->next = ptr;
	}
	ptr = NULL;
}

void display(presence** arr)
{
	printf("\n\n");
	for(int i=0;i<MAX;i++)
	{
		printf("%d) ",i+1);
		if(NULL != arr[i])
		{
			printf("Presence ID : %d",arr[i]->p_id);
			printf("\n\tName : %s",arr[i]->name);
			printf("\n\tDevice ID : %d",arr[i]->d.device_id);
			printf("\n\tDevice Type : %s",arr[i]->d.device_type);
			presence *ptr = arr[i];
			while(NULL != ptr->next)
			{
				ptr = ptr->next;
				printf("\t-->\n");
				printf("\n\t\tPresence ID : %d",ptr->p_id);
				printf("\n\t\tName : %s",ptr->name);
				printf("\n\t\tDevice ID : %d",ptr->d.device_id);
				printf("\n\t\tDevice Type : %s",ptr->d.device_type);
			}
		}printf("\n\n");
	}
	printf("\n\n");
}

void free_arr(presence* arr[])
{
	for(int i=0;i<MAX;i++)
	{
		free_chain(arr[i]);
		free(arr[i]->name);
		free(arr[i]->d.device_type);
		free(arr[i]);
		arr[i] = NULL;
	}
}

int free_chain(presence* node)
{
	while(NULL == node)
		return -1;
	free_chain(node->next);
	free(node->name);
	free(node->d.device_type);
	free(node);
	node = NULL;
}
