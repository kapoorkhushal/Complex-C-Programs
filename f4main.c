#include"header.h"

int main(void)
{
	char filename[20];
	char *str;
	FILE *fp1,*fp2;
	memset(filename,0,20);
	printf("\nEnter File name -I : ");
	fgets(filename,20,stdin);
	if('\n' == filename[strlen(filename)-1])
		filename[strlen(filename)-1] = '\0';
	fp1 = fopen(filename,"r");
	if(NULL == fp1)
	{
		printf("\nFile does not exist !\n");
		exit(-1);
	}
	fp2 = fopen("new_document.txt","w");
	if(NULL == fp2)
	{
		printf("\nFile is not created !\n");
		exit(-1);
	}
	printf("\nNew Document is created \n");
	str = (char*) malloc(100*sizeof(char));
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		exit(-1);
	}
	while(fgets(str,100,fp1) != NULL)
		if(0 != strcmp(str,"\n"))
			fputs(str,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
