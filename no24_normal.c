#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	if(3 != argc)
	{
		printf("Invalid Input \n");
		return -1;
	}
	FILE *input,*output;
	char *str;
	printf("\nInput File : %s",argv[1]);
	printf("\nOutput File : %s\n",argv[2]);
	input = fopen(argv[1],"w+");
	output = fopen(argv[2],"w+");
	printf("\nEnter the Text into the Input-file [USE ctrl+D or ctrl+z to exit] : \n");
	str = (char*)malloc(1000*sizeof(char));
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(str,0,1000*sizeof(char));
	while(NULL != fgets(str,1000,stdin))
		fputs(str,input);
	rewind(input);
	char *check;
//	char delimit[] = " ,;'/-?!.: \n \t";
	check = (char*)malloc(10*sizeof(char));
	if(NULL == check)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(check,0,10*sizeof(char));
	memset(str,0,1000);
	while(EOF != fscanf(input,"%s",str))
	{
			int flag = 0;
			while(EOF != fscanf(output,"%s",check))
				if(0 == strncmp(str,check,strlen(str)))
				{
					flag = 1;
					break;
				}
			if(0  == flag)
			{
				fputs(str,output);
				fputs("\n",output);
			}
			rewind(output);
	}
	rewind(output);
	printf("\nOUTPUT FILE ::\n");
	while(NULL != fgets(check,100,output))
		puts(check);
	fclose(input);
	fclose(output);
	free(str);
	free(check);
	return 0;
}
