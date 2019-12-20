#include"header.h"

int main(int argc,char* argv[])
{
	if(3 != argc)
	{
		printf("Invalid Input \n");
		return -1;
	}
	FILE *input,*output;
	node *root = NULL;
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
	check = (char*)malloc(100*sizeof(char));
	if(NULL == check)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(check,0,100*sizeof(char));
	memset(str,0,1000);
	while(EOF != fscanf(input,"%s",str))
		insert(&root,str);
	insert_file(root,output);
	rewind(output);
	printf("\nOUTPUT FILE ::\n");
	while(NULL != fgets(check,100,output))
		puts(check);
	fclose(input);
	fclose(output);
	free_mem(root);
	free(str);
	free(check);
	return 0;
}

