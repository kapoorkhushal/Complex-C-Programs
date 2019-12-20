#include"header.h"

int main(void)
{
	char char_curr,char_prev;
	FILE *fp1,*fp2;
	fp1 = fopen("wrong.txt","r");
	if(NULL == fp1)
	{
		printf("\nFile does not exist !\n");
		exit(-1);
	}
	fp2 = fopen("right.txt","w");
	if(NULL == fp2)
	{
		printf("\nFile does not Created !\n");
		exit(-1);
	}
	char_curr = fgetc(fp1);
	char_curr = toupper(char_curr);
	fputc(char_curr,fp2);
	while((char_curr = fgetc(fp1)) != EOF)
	{
		fputc(char_curr,fp2);
		if(char_curr == '\n' || char_curr == '.')
		{
			char_curr = fgetc(fp1);
			char_curr = toupper(char_curr);
			fputc(char_curr,fp2);
			if(char_curr == 'A')
			{
				char_prev = fgetc(fp1);
				char_curr = fgetc(fp1);
			if((char_prev == ' ') && (char_curr == 'a' || char_curr == 'e' || char_curr == 'i' || char_curr == 'o' || char_curr == 'u'))
				fputc('n',fp2);
				fputc(char_prev,fp2);
				fputc(char_curr,fp2);
			}
		}
		if(char_curr == ' ')
		{
			char_curr = fgetc(fp1);
			fputc(char_curr,fp2);
			if(char_curr == 'a')
			{
				char_prev = fgetc(fp1);
				char_curr = fgetc(fp1);
			if((char_prev == ' ') && (char_curr == 'a' || char_curr == 'e' || char_curr == 'i' || char_curr == 'o' || char_curr == 'u'))
				fputc('n',fp2);
				fputc(char_prev,fp2);
				fputc(char_curr,fp2);
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
