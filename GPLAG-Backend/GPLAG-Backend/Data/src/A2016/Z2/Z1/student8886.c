#include <stdio.h>
#include <stdlib.h>
int main () {
	int  n, c1=0, c2=0, k=1, r=0;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	n=abs(n);
	while (n>9) {
		c1=n%10;
		c2=(n/10)%10;
		r=r+abs(c1-c2)*k;
		n=n/10;
		k*=10;
		}
		printf ("%d", r);
	return 0;
}