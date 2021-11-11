#include <stdio.h>
#include <math.h>
#include <math.h>

int main() {
	
	int temp,i,n,ukupno=0,broj=0,b=0,c=0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n<0)
	n=fabs(n);
	temp=n;
	while (temp!=0)
	{
		b=temp%10;
		ukupno++;
		temp/=10;
	}
	b=0;
    for (i=0;i<ukupno-1;i++)
	{
		b=0;
		c=0;
		b=n%10;
		n/=10;
		c=n%10;
	
		broj+=fabs(b-c)*pow(10,i);
	}
	printf("%d",broj);
	
	return 0;
}
