#include<stdio.h>
int x(char *a, char *b)
{
	*b = *a / *b;
	return *b;
}
int y(int *p,int a)
{
	int *c = p;
	while(*c++<a);
	return c-p;
}

void z(char *p)
{
	*(p+1)='-';
	*p++='-';
	p+=1;
	*p--='-';
}
int main()
{
	int B[3][3]={1,2,3,4};
	char c[9]="Trebinje";
	int A[4]={10,19,28,37};
	int b=1,a=1;
	b=B[0][3]+*(A+3);
	printf("%d\n",b);
	b=y(A,29);
	printf("%d\n",b);
	y(B,1);
	printf("%d\n",a);
	x(&a,&b);
	printf("%d\n",a);
	z(c);
	printf("%s\n",c);
	return 0;
}
