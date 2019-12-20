#include"header.h"

int main(void)
{
	char ch;
	char *name;
	char *q[MAX];
	int front = empty,rear=empty;

	int i = 0;
	do{
		printf("\nEnter Name : ");
		name = (char*)malloc(50*sizeof(char));
		if(NULL == name)
		{
			printf("\nMemory Allocation failure !\n");
			return failure;
		}
		memset(name,0,50*sizeof(char));
		fgets(name,49*sizeof(char),stdin);
		int len = strlen(name);
		if('\n' == name[len-1])
			name[len-1] = '\0';
		i++;
		if(failure == enque(q,&front,&rear,name))
			break;
		free(name);
		name = NULL;
		printf("Do you want to Continue [Y/N] : ");
		scanf("%c",&ch);
		while('\n' != getchar())
		{
			;
		}
	}while((ch == 'y' || ch == 'Y'));
	i--;
	printf("\nNames are :: \n");
	while(i>=0){
		deque(q,&front,&rear);
		i--;}
	printf("\n");
	return 0;
}

