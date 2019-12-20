#include"header.h"

int main(void)
{
	presence *table[MAX];
	presence *ptr;
	char ch;
	int i;
	for(i=0;i<MAX;i++)
		table[i] = NULL;
	do{
		ptr = (presence*)malloc(sizeof(presence));
		if(NULL == ptr)
		{
			printf("\nMemory Allocation Failure !\n");
			exit(-1);
		}
		memset(ptr,0,sizeof(presence));
		int id = getdata(ptr)%MAX;
		insert(ptr,id,table);
		i--;
		printf("Do you want to Continue [Y/N] : ");
		scanf("%c",&ch);
		getchar();
	}while((ch == 'Y' || ch == 'y') && (i>=0));
	display(table);
	free_arr(table);
	return 0;
}
