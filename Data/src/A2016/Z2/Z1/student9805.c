#include <stdio.h>
#include <math.h>
int main() {
	int a, b=0, c=0, d=0, k=1;
	printf ("Unesite broj: ");
	scanf ("%d", &a);
	do {
		a=fabs (a);
		b=a%10;
		a=(a/10);
		if (a==0){
			break;
		}
		c=a%10;
		d+=fabs(b-c)*k;
		
		k*=10;
		
	} while (a!=0);
	printf ("%d",d);
	return 0;
}
