#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int c1,c2,n,k=1,br=0;
	printf ("Unesite broj: ");
	scanf ("%d",&n);
	while (abs(n)>=10)
	{
		c1=n%10;
		n=n/10;
		c2=n%10;
		br+=(abs(c1-c2)*k);
		k=k*10;
		
	}
	
	printf ("%d",br);
	return 0;
}
