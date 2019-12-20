#include"header.h"

int main(int argc,char *argv[])
{
	int num=atoi(argv[1]),flag=0;
	char *string[num];char line[100];
	int checklen = strlen(argv[2])+1;
	char check[checklen];
	memset(check,0,checklen*sizeof(char));
	strncpy(check,argv[2],checklen-1);
	if(3 != argc)
	{
		printf("\nInvalid Input !\n");
		return -1;
	}
	printf("Number of Arguments : %d\n",argc);
//	for(int i=0;i<argc;i++)
//		printf("%s\n",argv[i]);
	printf("Enter the strings :\n");
	for(int i=0;i<num;i++)
	{
		memset(line,0,100);
		fgets(line,100,stdin);
		int len = strlen(line);
		if('\n' == line[len-1])
		{
			line[len-1] = '\0';
		}
		if(0 == strcmp(line,"end"))
			break;
		if(strstr(line,check) != NULL)
		{
			char *temp;
			temp = (char*)malloc(sizeof(len+1));
			if(NULL == temp)
			{
				printf("Memory Allocation Failure!\n");
				exit(0);
			}
			string[flag]=temp;
			memset(string[flag],0,len+1);
			strncpy(string[flag],line,len);
			flag++;
		}
	}
	printf("\nStrings in which %s occurs ::\n",argv[2]);
	for(int i=flag-1;i>=0;i--)
		printf("%s\n",string[i]);
	for(int i=0;i<flag;i++)
	{
		free(string[i]);
		string[i] = NULL;
	}
	return 0;
}
