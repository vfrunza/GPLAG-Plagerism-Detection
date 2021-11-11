#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	int a,b,c,d,x,num=0,n=0;
	printf("\nUnesite broj: ");
	scanf("%d", &a);
	b=a%10;
	a=a/10;
	while (a!=0)
	{
		c=a%10;
		a=a/10;
		d=abs(b-c);
		x=d*(pow(10,n));
		num=num+x;
		b=c;
		n++;
	}
	printf("%d", num);
	return 0;
}
