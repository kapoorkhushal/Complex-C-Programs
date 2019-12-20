#include"header.h"

int main(void)
{
	FILE *fpi,*fpo;
	node *top = NULL;
	char *str,*word1,*word2;
	char character;
	char filename[15];
	int count = 0,i=0;
	memset(filename,0,15);
	printf("\nEnter File-Name : ");
	fgets(filename,15,stdin);
	if('\n' == filename[strlen(filename)-1])
		filename[strlen(filename)-1] = '\0';
	fpi = fopen(filename,"w+");
	fpo = fopen("palindrome.txt","w+");
	if(NULL == fpi || NULL == fpo)
	{
		printf("\nFile cannot be created !\n");
		exit(-1);
	}
	printf("\nEnter into the file [USE ctrl+D or ctrl+z to exit] : \n");
	str = (char*)malloc(sizeof(char)*100);
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(str,0,sizeof(char)*100);
	while(NULL != fgets(str,100,stdin))
		fputs(str,fpi);
	memset(str,0,100);
	rewind(fpi);
	word1 = (char*)malloc(sizeof(char)*10);
	if(NULL == word1)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(word1,0,sizeof(char)*10);
	word2 = (char*)malloc(sizeof(char)*10);
	if(NULL == word2)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(word2,0,sizeof(char)*10);
	while(EOF != (character = fgetc(fpi)))
	{
		if(character == ' ' || character == '.' || character == '\n' || character == ',')
		{	i = 0;
			while(count>0)
			{
				word2[i] = pop(&top);
				count--;i++;
			}
			if(0 == strcmp(word1,word2))
			{
				fputs(word1,fpo);
				fputc('\n',fpo);
			}
			memset(word1,0,10);
			memset(word2,0,10);
			character = fgetc(fpi);
			count = 0;i = 0;
		}
		word1[i] = character;
		count++;i++;
		push(&top,character);
	}
	free(word1);
	free(word2);
	word1 = word2 = NULL;
	rewind(fpo);
	memset(str,0,100);
	printf("\n\n");
	printf("Output ::\n");
	while(NULL != fgets(str,100,fpo))
		printf("%s",str);
	free(str);
	str = NULL;
	fclose(fpi);
	fclose(fpo);
	return 0;
}

