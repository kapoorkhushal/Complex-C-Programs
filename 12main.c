#include"header.h"

int main(int argc,char *argv[])
{
	FILE *fpi,*fps,*fpo;
	int num;
	char *str;
	if(4 != argc)
	{
		printf("\nInvalid Input !\n");
		return -1;
	}
	printf("\nInteger File : %s",argv[1]);
	printf("\nString File : %s",argv[2]);
	printf("\nOutput File : %s\n",argv[3]);
	char filename[15];
	//memset(filename,0,15);
	strncpy(filename,argv[1],strlen(filename));
	fpi = fopen(filename,"w+");
	//memset(filename,0,15);
	strncpy(filename,argv[2],strlen(filename));
	fps = fopen(filename,"w+");
	//memset(filename,0,15);
	strncpy(filename,argv[3],strlen(filename));
	fpo = fopen(filename,"w+");
	printf("\nEnter the Integer into the Integer-file [USE ctrl+D or ctrl+z to exit] : ");
	while((num=getchar()) != EOF)
		fputc(num,fpi);
	printf("\nEnter the String into the string-file [USE ctrl+D or ctrl+z to exit] : ");
	str = (char*)malloc(sizeof(char)*100);
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		return -1;
	}
	memset(str,0,sizeof(char)*100);
	while(NULL != fgets(str,100,stdin))
		fputs(str,fps);
	num = 0;
	memset(str,0,100);
	rewind(fpi);
	rewind(fps);
	while((fgets(str,100,fps) != NULL) && ((num = fgetc(fpi)) != EOF))
	{
		if(num == '\n')
			num = fgetc(fpi);
		fputc(num,fpo);
		fputs(" ",fpo);
		fputs(str,fpo);
	}
	rewind(fpo);
	memset(str,0,100);
	printf("\n\n");
	while(fgets(str,100,fpo) != NULL)
		puts(str);
	free(str);
	str = NULL;
	fclose(fpi);
	fclose(fps);
	fclose(fpo);
	return 0;
}
