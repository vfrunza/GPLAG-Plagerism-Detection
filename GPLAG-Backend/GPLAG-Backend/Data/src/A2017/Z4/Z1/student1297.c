// Ovo je ujedno peti zadatak sa ispisima iz fajla or-rokovi-ispisi-i-mali-zadaci.pdf

#include<stdio.h>
int x(char *a, char *b)
{
	*b = *a / *b;
	return *b;
}
int y(int *p,int a)//10 19 28 37 i 29
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
	char A[4]={10,19,28,37};
	int b=1,a=1;
	b=B[0][3]+*(A+3);
	printf("%d\n",b);//41
	b=y(A,29);
	printf("%d\n",b);//4 a ispisuje 1
	y(B,1);
	printf("%d\n",a);//1
	x(&a,&b);
	printf("%d\n",a);//1
	z(c);
	printf("%s\n",c);//---binje
	return 0;
}