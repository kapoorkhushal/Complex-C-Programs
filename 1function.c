#include"header.h"

void timestamp()
{
	time_t clk = time(NULL);
	printf("\n%s\n", ctime(&clk));
}

