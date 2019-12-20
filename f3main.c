#include"header.h"

int main(void)
{
	char filename[20];
	char *str;
	FILE *fp1,*fp2,*fp3;
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
	memset(filename,0,20);
	printf("\nEnter File name -II : ");
	fgets(filename,20,stdin);
	if('\n' == filename[strlen(filename)-1])
		filename[strlen(filename)-1] = '\0';
	fp2 = fopen(filename,"r");
	if(NULL == fp2)
	{
		printf("\nFile does not exist !\n");
		exit(-1);
	}
	fp3 = fopen("merge.txt","w");
	if(NULL == fp3)
	{
		printf("\nFile is not created !\n");
		exit(-1);
	}
	printf("\nMerged File is created \n");
	str = (char*) malloc(100*sizeof(char));
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		exit(-1);
	}
	memset(str,0,sizeof(char)*100);
	while(fgets(str,100,fp1) != NULL)
		fputs(str,fp3);
	memset(str,0,sizeof(char)*100);
	while(fgets(str,100,fp2) != NULL)
		fputs(str,fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
