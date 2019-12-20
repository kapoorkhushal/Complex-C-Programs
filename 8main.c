#include "header.h"
//#include "function.c"
int main(void)
{
	const int i=1;
	const int *pi;
	pi= &i;
	int j=1;
	int *const pj = &j;	 
	int n1, n2, n3, vp=99;
	void *vptr;
	int *ptr=&n1;
	int **dptr=&ptr;
	vptr=&vp;
	int a=10, *iptr=&a;
	int x=15, *iptrr=&x;
	float b=10.55, *fptr=&b;
	float y=8.55, *fptrr=&y;
	char c='a', *cptr=&c;
	char z='b', *cptrr=&z;
	int ch;
	char choice;
	do{

	printf("\nMENU-");
	printf("\n1.Types of Pointers and their sizes-");
	printf("\n2.Operations on Pointers-");
	printf("\n3.Void Pointer-");
	printf("\n4.Double Pointer-");
	printf("\n5.Call by Value and Call by Reference-");
	printf("\n6.Exit-");	
	printf("\nEnter your choice- ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				printf("Pointer To Constant\n");
				printf("Address of i = Value of pi = %p || Value of i = %d\n",pi,*pi);
				printf("Constant Pointer\n");				
				printf("Address of j = Value of pj = %p || Value of j = %d\n\n",pj,*pj);
				printf("Different Pointers and their sizes\n\n");
				printf("Integer Pointer\nSize of Integer Pointer = %ld\n",sizeof(iptr));
				printf("Float Pointer\nSize of Float Pointer = %ld\n",sizeof(fptr));
				printf("Character Pointer\nSize of Char Pointer = %ld\n",sizeof(cptr));
				printf("Double Pointer\nSize of Double Pointer = %ld\n",sizeof(dptr));
				printf("Void Pointer\nSize of Void Pointer = %ld\n\n",sizeof(vptr));
				break;

		case 2:
				printf("Value of iptr = Address of a = %p || Value of a = %d\n",iptr,*iptr);
				printf("Value of fptr = Address of b = %p || Value of b = %f\n",fptr,*fptr);
				printf("Value of cptr = Address of c = %p || Value of c = %c\n\n",cptr,*cptr);
				printf("Pointers Arithmetic\n");
				printf("INCREMENT OPERATION\n");
				iptr++;
				fptr++;
				cptr++;
				printf("Value of iptr++ = %p\n",iptr);
				printf("Value of fptr++ = %p\n",fptr);
				printf("Value of cptr++ = %p\n\n",cptr);
				printf("DECREMENT OPERATION\n");
				iptr--;
				fptr--;
				cptr--;
				printf("Value of iptr-- = Address of a = %p\n",iptr);
				printf("Value of fptr-- = Address of b = %p\n",fptr);
				printf("Value of cptr-- = Address of c = %p\n\n",cptr);
				printf("Value of iptrr = Address of x = %p || Value of x = %d\n",iptrr,*iptrr);
				printf("Value of fptrr = Address of y = %p || Value of y = %f\n",fptrr,*fptrr);
				printf("Value of cptrr = Address of z = %p || Value of z = %c\n\n",cptrr,*cptrr);
				printf("Subtraction of one pointer from another\n");
				n1=iptr-iptrr;
				n2=fptr-fptrr;
				n3=cptr-cptrr;
				printf("Value of n1 = %d\n",n1);
				printf("Value of n2 = %d\n",n2);
				printf("Value of n3 = %d\n\n",n3);
				break;

		case 3:
				printf("Void Pointer\n");	
				printf("Address of vp = Value of vptr= %p\n",(int *)vptr);
				printf("Value of vp = %d\n\n",*(int *)vptr);
				break;

		case 4:
				printf("Double Pointer\n");
				printf("Value of dptr = Address of ptr = %p\n",dptr);
				printf("Value of **dptr = Value of n1 = %d\n\n",**dptr);
				break;
			
		case 5:
				printf("Call by Value\n");
				printf("Before calling function swap\n");
				printf("a= %d || x= %d\n",a,x);
				swap(a,x);
				printf("After calling function swap\n");
				printf("a= %d || x= %d\n\n",a,x);
				printf("Call by Reference\n");
				printf("Before calling function swapp\n");
				printf("b= %f || y=%f\n",b,y);
				swapp(&b,&y);
				printf("After Calling function swapp\n");
				printf("b= %f || y= %f\n\n",b,y);
				break;

		case 6:
				exit(1);
				break;
		default:printf("Wrong Choice\n");
	}
	printf("Do you want to Continue [Y/N] : ");
	scanf("%s",&choice);
	}while(choice == 'y' || choice == 'Y');
}

