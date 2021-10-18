#include <stdio.h>
#include <math.h>
int main() {
	int x, a, b, c, pomocna, br=0, suma=0, i;
	printf ("Unesite broj: ");
	scanf ("%d", &x);
	x=fabs(x);
	if(x>=0 && x<=9) {
		printf("0");
		return 0;
	}
	pomocna=x;
	while(pomocna!=0) {
		pomocna/=10;
		br++;
	}
	for(i=br-1;i>0;i--) {
			a=x%10;
		    x=x/10;
		  	b=x%10;
		  	c=fabs(a-b);
			suma += c*pow(10,br-i-1);
		}
		printf ("%d", suma);

	
	return 0;
	
}
	
