#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, x1, x2, rj_x1, rj_x2;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	x1=-b+sqrt((b*b)-4*a*c)/2*a;
	x2=-b-sqrt((b*b)-4*a*c)/2*a;
	printf ("X1 je %lf", x1);
	if (x1*x1<0 && x2*x2<0){
		printf ("Rjesenja su imaginarni brojevi.");
	}
	else {
	printf ("Unesite rjesenje x1: ");
	scanf ("%lf", &rj_x1);}
	
	
	
	
	return 0;
}
