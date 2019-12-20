#include"header.h"

int main(void)
{
	char filename[20],char_curr,char_plus;
	FILE *fp1,*fp2;
	printf("\nEnter File name : ");
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
		printf("\nFile does not Created !\n");
		exit(-1);
	}
	while((char_curr = fgetc(fp1)) != EOF)
	{
		if(char_curr == '/')
		{
			char_plus = fgetc(fp1);
			fseek(fp1,-1,SEEK_CUR);
			if(char_plus == '/')				// "//" : case
				while(char_curr != '\n')
					char_curr = fgetc(fp1);
			else if(char_plus == '*')			// "/*...*/" : case
			{
				while(char_curr != '*' || char_plus != '/')
				{
					char_curr = fgetc(fp1);
					char_plus = fgetc(fp1);
				}
				char_curr = fgetc(fp1);
			}
		}
		fputc(char_curr,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove(filename);
	rename("temporary.txt",filename);
	return 0;
}
