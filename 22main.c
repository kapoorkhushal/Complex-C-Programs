#include "header.h"

int main(void)
{
	char *names[MAX],*search,ch;
	int count = 0;
	do{
		names[count] = (char *)malloc(25*sizeof(char));
		if(NULL == names[count])
		{
			printf("\nMemory Allocation Failure !");
			exit(0);
		}
		memset(names[count],0,25*sizeof(char));
		printf("\nEnter name : ");
		fgets(names[count],24,stdin);
		if('\n' == names[count][strlen(names[count])-1])
			names[count][strlen(names[count])-1] = '\0';
		count++;
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
		while('\n' != getchar())
		{	;	}
	}while((ch == 'y' || ch == 'Y') && (count<=MAX));
	bubble_sort(names,count);
	printf("\nList has been Sorted !\n");
	do{
		printf("Enter the name to be Searched : ");
		search = (char*)malloc(25*sizeof(char));
		if(NULL == search)
			exit(-1);
		memset(search,0,25);
		fgets(search,24,stdin);
		if('\n' == search[strlen(search)-1])
			search[strlen(search)-1] = '\0';
		int loc = binary_search(names,0,count-1,search); 
		if(-1 == loc)
			printf("\nName does not exist !\n");
		else
			printf("\n\"%s\" exist at %d\n",search,loc+1);
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
		while('\n' != getchar())
		{	;	}
	}while(ch == 'y' || ch == 'Y');
	free_array(names,count);
	return 0;
}

