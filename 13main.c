#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define success 1
#define failure -1

typedef struct employee
{
	int emp_id;
	long phoneno;
	char name[20];
	char department[40];
}employee;

int search(struct employee*[],int,FILE*);

int main(void)
{
	employee *emp[MAX];
	FILE *fp;
	char ch,filename[20];
	int count=0;
	printf("\nEnter the Data of Employees ::\n");
	do{
		printf("\nEnter data for Employee %d :\n",count+1);
		emp[count] = (employee*)malloc(sizeof(employee));
		if(NULL == emp[count])
		{
			printf("\nMemory Allocation Failure !\n");
			return failure;
		}
		memset(emp[count],0,sizeof(employee));
		printf("Employee-ID : ");
		scanf("%d",&emp[count]->emp_id);
		while('\n' != getchar())
			{	;	}
		printf("Name : ");
		fgets(emp[count]->name,20,stdin);
		if('\n' == emp[count]->name[strlen(emp[count]->name)-1])
			emp[count]->name[strlen(emp[count]->name)-1] = '\0';
		printf("Phone Number : ");
		scanf("%ld",&emp[count]->phoneno);
		while('\n' != getchar())
			{	;	}
		printf("Department : ");
		fgets(emp[count]->department,40,stdin);
		printf("\nDo you want to continue [Y/N] : ");
		scanf("%c",&ch);
		count++;
	}while((ch == 'y' || ch == 'Y') && (count<MAX));
	while('\n' != getchar())
		{	;	}
	memset(filename,0,20);
	printf("\nEnter Filename : ");
	fgets(filename,20,stdin);
	if('\n' == filename[strlen(filename)-1])
		filename[strlen(filename)-1] = '\0';
	fp = fopen(filename,"wb+");
	if(NULL == fp)
	{
		printf("\nFile cannot be created !\n");
		exit(-1);
	}
	int n = fwrite(emp,sizeof(employee),count,fp);
	if(count > n)
		if(feof(fp))
		{
			printf("\nError in writing into the file !\n");
			exit(-1);
		}
	rewind(fp);
	search(emp,count,fp);
	return 0;
}

int search(employee *emp[],int count,FILE *fp)
{
	int ch,emp_id,i;
	char name[20],exit;
	long phoneno;
	memset(name,0,20);
	printf("\nMENU ::\n1.Check the Record \n2.Update Record\n");
	do{
		printf("Enter Choice : ");
		scanf("%d",&ch);
		while('\n' != getchar())
			{	;	}
		switch(ch)
		{
			case 1:
				printf("\nEnter Name : ");
				fgets(name,20,stdin);
				if('\n' == name[strlen(name)-1])
					name[strlen(name)-1] = '\0';
				for(i = 0;i<count;i++)
				{
					int n = fread(emp,sizeof(employee),count,fp);
					if(count > n)
						if(ferror(fp))
						{
							printf("\nError in reading from the file !\n");
							return failure;
						}
					if(0 == strcmp(name,emp[i]->name))
					{
						printf("\nEmployee-ID : %d",emp[i]->emp_id);
						printf("\nName : %s",emp[i]->name);
						printf("\nPhone Number : %ld",emp[i]->phoneno);
						printf("\nDepartment : %s",emp[i]->department);
						i = count-1;break;
					}
				}memset(name,0,20);
				if(i == count)
					printf("\nNo Record Found !\n");break;
			case 2:
				printf("\nEnter Employee-ID : ");
				scanf("%d",&emp_id);
				for(i = 0;i<count;i++)
				{
					int n = fread(emp,sizeof(employee),count,fp);
					if(count > n)
						if(ferror(fp))
						{
							printf("\nError in reading from the file !\n");
							return failure;
						}
					if(emp_id == emp[i]->emp_id)
					{
						printf("\nNew Phone Number : ");
						scanf("%ld",&phoneno);
						emp[i]->phoneno = phoneno;
						printf("\nRecord Successfully Updated !\n\n");
						printf("\nEmployee-ID : %d",emp[i]->emp_id);
						printf("\nName : %s",emp[i]->name);
						printf("\nPhone Number : %ld",emp[i]->phoneno);
						printf("\nDepartment : %s",emp[i]->department);
						i = count-1;break;
					}
				}emp_id = 0;phoneno = 0;
				if(i == count)
					printf("\nNo Record Found !\n");
				while('\n' != getchar())
					{	;	}break;
			default :
				printf("\nInvalid Input !\n");
		}
		printf("\nDo you want to continue [Y/N] : ");
		scanf("%c",&exit);
	}while('y' == exit || 'Y' == exit);
	return success;
}
