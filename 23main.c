#include "header.h"

int main(void)
{
	char *name[MAX],ch;
	int count = 0,choice;
	do{
		name[count] = (char *)malloc(25*sizeof(char));
		if(NULL == name[count])
		{
			printf("\nMemory Allocation Failure !");
			exit(0);
		}
		memset(name[count],0,25*sizeof(char));
		printf("\nEnter name : ");
		fgets(name[count],24,stdin);
		if('\n' == name[count][strlen(name[count])-1])
			name[count][strlen(name[count])-1] = '\0';
		count++;
		printf("Do you want to continue [Y/N] : ");
		scanf("%c",&ch);
		while('\n' != getchar())
		{	;	}
	}while((ch == 'y' || ch == 'Y') && (count<=MAX));
	printf("\nMENU :: \n1.Insertion Sort \n2.Selection Sort \n3.Quick Sort \n4.Merge Sort\n");
	printf("Enter choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insertion_sort(name,count);break;
		case 2:
			selection_sort(name,count);break;
		case 3:
			quick_sort(name,0,count-1);break;
		case 4:
			merge_sort(name,0,count-1,count-1);break;
		default : 
			printf("\nInvalid Input !\n");
	}
	printf("\nNames in Sorted Order :\n");
	for(int i=0;i<count;i++)
		printf("%d.%s\n",i+1,name[i]);
	printf("\n");
	free_array(name,count);
	return 0;
}

