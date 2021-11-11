#include <stdio.h>
#include <math.h>
int main ()
{
	int c1, c2, x, c, broj=0, brojac=1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0)
	{
		x=fabs(x);
	}
	
	while(x!=0 )
	{
		if(x<10)
		{
			break;
		}
		c1=x%10;
		x/=10;
		c2=x%10;
		c=fabs(c1-c2);
		broj=c*brojac+broj;
		
		brojac*=10;
			}
	printf("%d", broj);
	return 0;
}