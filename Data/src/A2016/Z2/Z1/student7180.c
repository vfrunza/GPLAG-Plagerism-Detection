#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, m, a, b, c, d=0, k=1;
	printf("Unesite broj: ");
	scanf("%d", &n); 
	if(n<0) n=-n;
	m=n;
	while (n>10)
	{
		a=n%10;
		n/=10;
		m/=10;
		b=m%10;
		c=abs(a-b); 
		d+=k*c; k*=10;
	}
	printf("%d", d);
	return 0;
}
