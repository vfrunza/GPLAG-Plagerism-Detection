#include <stdio.h>
#include <math.h>

int main() 
{
	int n, a, b, c, suma=0, d, suma1=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
	n=n*(-1);
	if(n>=0 && n<=9)
	{
	printf("0");
	return 0;
	}
	
	while(n!=0)
	{
		a=n%10;
		b=(n%100)/10;
		c=a-b;
		if(c<0)
		c=c*(-1);
		suma=suma*10+c;
		n/=10;
	}
	
	suma/=10;
	while(suma!=0)
	{
		d=suma%10;
		suma1=suma1*10+d;
		suma/=10;
	}
	
	printf("%d", suma1);
	return 0;
}
