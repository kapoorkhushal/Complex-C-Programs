#include"header.h"

int main(void)
{
	hash *table[MAX];
	char *name,ch;
	int i;
	for(i=0;i<MAX;i++)
		table[i] = NULL;
	do{
		printf("\nEnter Name : ");
		name = (char*)malloc(20*sizeof(char));
		memset(name,0,20);
		fgets(name,19,stdin);
		name[strlen(name)-1] = '\0';
		int id = string_add(name)%MAX;
		insert(name,id,table);
		i--;
		printf("Do you want to Continue [Y/N] : ");
		scanf("%c",&ch);
		getchar();
	}while((ch == 'Y' || ch == 'y') && (i>=0));
	display(table);
	free_arr(table);
	return 0;
}


