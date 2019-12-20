#include"header.h"

int insertion_sort(char *string[],int count)
{
	char *temp;
	temp = (char*)malloc(25*sizeof(char));
	if(NULL == temp)
		exit(-1);
	for(int i=1;i<count;i++)
	{
		memset(temp,0,25);
		strcpy(temp,string[i]);
		int j = i-1;
		while((j>=0) && (0 > strcmp(temp,string[j])))
		{
			strcpy(string[j+1],string[j]);
			j--;
		}strcpy(string[j+1],temp);
	}
	free(temp);
	temp = NULL;
	return 1;
}

int selection_sort(char *string[],int count)
{
	char *temp;
	for(int i=0;i<count-1;i++)
	{
		temp = (char*) malloc(25*sizeof(char));
		if(NULL == temp)
			exit(-1);
		memset(temp,0,25);
		strcpy(temp,string[i]);
		for(int j = i+1;j<count;j++)
		{
			if(0 < strcmp(string[i],string[j]))
			{
				strcpy(temp,string[i]);
				strcpy(string[i],string[j]);
				strcpy(string[j],temp);
			}
		}
		free(temp);
		temp = NULL;
	}
	return 1;
}

int quick_sort(char *string[],int beginning,int end)
{
	if(beginning < end)
	{
		int p = partition(string,beginning,end);
		quick_sort(string,beginning,p-1);
		quick_sort(string,p+1,end);
	}
	return 1;
}

int partition(char*string[],int beginning,int end)
{
	char *temp;
	int left = beginning,right= end,location = beginning;
	while(left < right)
	{
		while((0 > strcmp(string[location],string[right])) && (location != right))
			right--;
		if(right == location)
			return location;
		temp = (char*) malloc(25*sizeof(char));
		if(NULL == temp)
			exit(-1);
		memset(temp,0,25);
		strcpy(temp,string[location]);
		strcpy(string[location],string[right]);
		strcpy(string[right],temp);
		location = right;
		while((0 > strcmp(string[left],string[location])) && (location != left))
			left++;
		if(left == location)
			return location;
		memset(temp,0,25);
		strcpy(temp,string[location]);
		strcpy(string[location],string[left]);
		strcpy(string[left],temp);
		location = left;
	}
}

int merge_sort(char *string[],int beginning,int end,int count)
{
	if(beginning < end)
	{
		int mid = (beginning+end)/2;
		merge_sort(string,beginning,mid,count);
		merge_sort(string,mid+1,end,count);
		merge(string,beginning,mid,mid+1,end,count);
	}
}

int merge(char *string[],int lower_bound1,int upper_bound1,int lower_bound2,int upper_bound2,int count)
{
	char *sub_string[MAX];
	int i = lower_bound1,j = lower_bound2,k = 0;
	for(int loop = 0;loop <= count;loop++)
	{
		sub_string[loop] = (char*)malloc(25*sizeof(char));
		if(NULL == sub_string[loop])
		{
			printf("\nMemory Allocation Failure !");
			exit(0);
		}
		memset(sub_string[loop],0,25*sizeof(char));
	}
	while((i <= upper_bound1) && (j <= upper_bound2))
	{
		if(0 > strcmp(string[i],string[j]))
		{
			strcpy(sub_string[k],string[i]);
			i++;
			k++;
		}
		else
		{
			strcpy(sub_string[k],string[j]);
			j++;
			k++;
		}
	}
	while(i <= upper_bound1)
	{
			strcpy(sub_string[k],string[i]);
			i++;
			k++;
	}
	while(j <= upper_bound2)
	{
			strcpy(sub_string[k],string[j]);
			j++;
			k++;
	}
	i = lower_bound1;
	k = 0;
	while(i <= upper_bound2)
	{
		memset(string[i],0,25);
		strcpy(string[i],sub_string[k]);
		free(sub_string[k]);
		sub_string[k] = NULL;
		i++;k++;
	}
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
