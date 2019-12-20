/* Size of Data types */

#include"header.h"

int main(void)
{
	timestamp();
	printf("\nsize of character : %ld",sizeof(char));
	printf("\nsize of integer : %ld",sizeof(int));
	printf("\nsize of float : %ld",sizeof(float));
	printf("\nsize of double : %ld",sizeof(double));
	printf("\nsize of long : %ld",sizeof(long));
	printf("\nsize of short : %ld",sizeof(short));
	printf("\nsize of long double: %ld\n",sizeof(long double));	
	return 0;
}


