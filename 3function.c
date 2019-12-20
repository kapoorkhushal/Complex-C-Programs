#include"header.h"

void power(int num)
{
	int i;
	for(i=0;i<20;i++)
	{
		if(2<<i == num || num ==1)
		{
			printf("YES! Power of 2\n");
			i=1;break;
		}
	}
	if(i>=20)
		printf("NOT the Power of 2\n");
}
