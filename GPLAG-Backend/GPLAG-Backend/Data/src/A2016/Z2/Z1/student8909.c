/*zadaca 2, zadatak 1. */

#include <stdio.h>
#include <math.h>

int main() 
{
	int n, x=1, m, a, b, broj=0;
	printf("Unesite broj: ");
	scanf("%d", &m);
	
	n=fabs(m);
	
	do
	{
		if(n<10 && n>=0)
		{
			printf("0");
			return 0;
		}
		
		a=n%10;
		b=(n/10)%10;
		broj=broj+fabs(a-b)*x;
		
		x=x*10;
		
		n=n/10;
		
	}
	while (n >= 10);
	
	
	printf("%d", broj);
	
	
	
	return 0;
}
