#include <stdio.h>
#include <stdlib.h>
int main() {
	int a, b, x, y, n;
	n=1;
	y=0;
	printf ("Unesite broj: ");
	scanf ("%d", &x);
	x=abs(x);
	while (x>=10) {
		a=x%10;
		b=(x/10)%10;
		x=x/10;
		y=y+abs(a-b)*n;
		n=n*10;
	}
	printf ("%d", y);
	return 0;
}
	
