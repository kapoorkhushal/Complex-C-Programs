#include"header.h"

void prime(int no)
{
	int clk=sqrt(no);
	int flag = 0;
	for(int i=2;i<=clk;i++)
	{
		if(no%i==0)
		{
			flag = 1;break;	
		}
	}
	if(flag == 1)
		printf("\n%d is not Prime!\n\n",no);
	else
		printf("\n%d is Prime!\n\n",no);
}

int reverse(int no)
{
	int palen=0;
	while(no>=10)
	{
		palen=(palen*10)+no%10;
		no/=10;
	}palen=(palen*10)+no;
	return palen;
}

float celcius(int no)
{
	return 32 + 9*no /5;
}

void timestamp(void)
{
	time_t clk = time(NULL);
	printf("\n%s\n", ctime(&clk));
}

