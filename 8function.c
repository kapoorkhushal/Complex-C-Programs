#include "header.h"
void swap(int p, int q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}

void swapp(float *c, float *d)
{
	float temp;
	temp = *c;
	*c = *d;
	*d = temp;
}

