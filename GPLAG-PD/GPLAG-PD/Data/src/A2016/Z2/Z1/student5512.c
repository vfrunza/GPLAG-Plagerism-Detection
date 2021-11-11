#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int y=0,q=0,l=0,n,x,b=0;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	x=1;
	y=abs(n);
	while (y>=10){
		l=(y/10)%10;
		q=y%10;
		b+=abs(q-l)*x;
		y/=10;
		x*=10;}
	printf ("%d", b);
		return 0;}
