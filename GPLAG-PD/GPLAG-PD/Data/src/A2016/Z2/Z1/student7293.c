#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int x,p=0,d=0,broj=0,k=1;
	printf ("Unesite broj: ");
	scanf ("%d", &x);
	x=fabs(x);

	if (x<=9)
	{
		printf ("0");
		return 0;
	}
	
	while (x>=10 && x!=0)
	{
		
		p=x%10;
		d=(x/10)%10;
		broj+=fabs(p-d)*k;
		k*=10;
		x/=10;
	}
	

	printf ("%d", broj);
	
	return 0;
}
