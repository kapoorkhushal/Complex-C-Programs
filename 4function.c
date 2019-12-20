#include"header.h"

void inputcheck(int count)
{
	int num;
	int positive=0,negative=0,zero=0;
	while(count>0)
	{
		while('\n'!=getchar()){ ; }
		printf("Enter The Number :");
AGAIN :
		if(0 == scanf("%d",&num))		//Amendments Reqd
		{
			printf("Re-Enter the Number :");
			while('\n'!=getchar()){ ; }
			goto AGAIN;
		}
		else
		{
			if(num == 0)
				zero++;
			else if(num > 0)
				positive++;
			else
				negative++;
		}
		printf("\nZEROS :%d\nPOSITIVE :%d\nNEGATIVE :%d\n",zero,positive,negative);
	count--;}
	printf("\n\nFINAL O/P::\nZEROS :%d\nPOSITIVE :%d\nNEGATIVE :%d\n",zero,positive,negative);
}
