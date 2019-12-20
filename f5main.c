#include"header.h"

int main(void)
{
	char filename[20];
	char *str;
	FILE *fp1,*fp2;
	int line,pagenumber;
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
	fp2 = fopen("temporary.txt","w");
	if(NULL == fp2)
	{
		printf("\nTemporary File cannot be created !\n");
		exit(-1);
	}
	str = (char*) malloc(100*sizeof(char));
	if(NULL == str)
	{
		printf("\nMemory Allocation Failure !\n");
		exit(-1);
	}
	line = 0;
	pagenumber = 1;
	fprintf(fp2,"\t\t\t*********%d*********\n",pagenumber);
	while(fgets(str,100,fp1) != NULL)
	{
		line++;
		if(0 == line%80){
			pagenumber++;
			fprintf(fp2,"\t\t\t*********%d*********\n",pagenumber);
		}
		fprintf(fp2,"%d",line);
		fputs(" ",fp2);
		fputs(str,fp2);
	}
	printf("\nDocument has been updated up with the line Number !\n");
	fclose(fp1);
	fclose(fp2);
	remove(filename);
	rename("temporary.txt",filename);
	return 0;
}
