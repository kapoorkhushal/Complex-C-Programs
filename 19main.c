#include"header.h"

int main(void)
{
	char *ch;
	int no;
	node *top = NULL;
	ch = (char*)malloc(sizeof(char)*40);
	if(NULL == ch)
	{
		printf("\nMemory Allocation Failure\n");
		return failure;
	}
	memset(ch,0,sizeof(char)*20);
	printf("\nEnter the Infix Expression : ");
	fgets(ch,40,stdin);
	int len = strlen(ch);
	if('\n' == ch[len-1])
		ch[len-1] = '\0';
	printf("Postfix Expression : ");
	for(int i=0;i<len-1;i++)
	{
		if('(' == *(ch+i))
		{	
			no = priority(*(ch+i));
			conversion(&top,*(ch+i),no);
		}
		else if('+' == *(ch+i) || '-' == *(ch+i) || '*' == *(ch+i) || '/' == *(ch+i) || '^' == *(ch+i))
		{
			no = priority(*(ch+i));
			conversion(&top,*(ch+i),no);
		}
		else if(')' == *(ch+i))
		{
			no = priority(*(ch+i));
			conversion(&top,*(ch+i),no);
		}
		else
			printf("%c",*(ch+i));
	}printf("\n\n");
	free(ch);
	ch = NULL;
	return 0;
}

