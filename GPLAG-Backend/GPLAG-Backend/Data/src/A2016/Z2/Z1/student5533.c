#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int c1,c2,n,suma=0, k=1;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	c1=n%10;
	n/=10;
	while (n)
	{
		c2=n%10;
		suma+=(abs(c1-c2))*k;
		k*=10;
		c1=c2;
		n/=10;
	}
	printf("%d", suma);
	return 0;
}
