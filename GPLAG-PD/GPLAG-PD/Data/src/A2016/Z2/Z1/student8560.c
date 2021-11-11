#include <stdio.h>
#include <stdlib.h>
int main () {
	int n, c1, c2, c3, novi_br=0, i=1;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	if (n<0) {
		n=abs(n);
	}
	c1=n%10;
	n=n/10;
	
    while (n>=1) {
		c2=n%10;
		c3=abs(c1-c2);
        c1=c2;
        n=n/10;
        novi_br=novi_br + (c3*i);
        i*=10;
    }

	printf ("%d", novi_br);
	return 0;
}