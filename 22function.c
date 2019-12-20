#include"header.h"

int bubble_sort(char *string[],int count)
{
	char *temp;
	temp = (char*)malloc(sizeof(char)*25);
	if(NULL == temp)
		exit(0);
	memset(temp,0,25);
	for(int i=0;i<count-1;i++)
		for(int j=0;j<count-1-i;j++){
			if(0 > strcmp(string[j+1],string[j]))
			{
				strcpy(temp,string[j]);
				strcpy(string[j],string[j+1]);
				strcpy(string[j+1],temp);
			}memset(temp,0,25);
		}
	free(temp);
	temp = NULL;
	return 1;
}

int binary_search(char *string[],int top,int bottom,char *name)
{
	int mid = (top+bottom)/2;
	if(0 == strcmp(string[top],name))
		return top;
	else if(0 == strcmp(string[bottom],name))
		return bottom;
	else if(0 == strcmp(string[mid],name))
		return mid;
	else if(top == bottom)
		return -1;
	else if(0 > strcmp(string[mid],name))
		binary_search(string,mid+1,bottom,name);
	else if(0 < strcmp(string[mid],name))
		binary_search(string,top,mid-1,name);
}

int free_array(char *string[],int count)
{
	for(int i=0;i<count;i++)
	{
		free(string[i]);
		string[i] = NULL;
	}
	return 1;
}
