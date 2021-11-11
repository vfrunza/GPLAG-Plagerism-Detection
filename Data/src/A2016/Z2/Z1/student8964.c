#include <stdio.h>
#include <math.h>

int main() {
	int x, y, a, b, c, d=0, n, i;
	printf ("Unesite broj: ");
	scanf ("%d", &x);
	if (x>=0 && x<10) {
		printf ("0");
	} else {
		x=fabs(x);
		y=x;
		for (i=0; x!=0; i++) {
			x=x/10;
		}
		for (n=i; n>1; n--) {
			a=y/(pow(10,(n-1)));
			b=pow(10,(n-1));
			c=pow(10,(n-2));
			d=d+fabs(a-(y-a*b)/c)*c;
			y=y-a*b;
		}
		printf ("%d", d);
	}
	return 0;
}
