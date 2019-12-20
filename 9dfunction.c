#include"header.h"

void display(const int *aptr,const int *bptr)
{
	int i;
	printf("Array - A\n");
	for(i=0;i<10;i++)
		printf("%d\t",*(aptr+i));
	printf("\n\n");
	printf("Array - B\n");
	for(i=0;i<15;i++)
		printf("%d\t",*(bptr+i));
	printf("\n\n");
}

void common(const int *aptr,const int *bptr)
{
	int cptr[10];
	int i,j;
	static int num=0;
	for(i=0;i<10;i++)
		for(j=0;j<15;j++)
			if(*(aptr+i) == *(bptr+j))		// && *(aptr+i)!=*(aptr+j)) also for i!=j
			{
				cptr[num]=*(aptr+i);
				num++;break;
			}
	printf("Common - Array :\n");
	for(i=0;i<num;i++)
		printf("%d\t",cptr[i]);
	printf("\n\n");
}
