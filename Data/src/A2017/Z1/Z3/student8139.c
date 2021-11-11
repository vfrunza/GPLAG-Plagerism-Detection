#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, D, rjesenje1, rjesenje2, x1, x2;
	printf ("Unesite koeficijente a, b i c: ");
	
scanf ("%lf %lf %lf", &a, &b, &c);
D=b*b-4*a*c;
if (D<0.) {
	printf ("Rjesenja su imaginarni brojevi.");
	return 0;
}
	rjesenje1=(-b+sqrt(D))/(2*a);
	rjesenje2=(-b-sqrt(D))/(2*a);
//	printf("%lf %lf",rjesenje1,rjesenje2);
for ( ; ; ) {
	printf ("Unesite rjesenje x1: ");
	scanf ("%lf", &x1);
		
	if(fabs(x1-rjesenje1)<0.001) {
		printf ("Tacno\n");
		break;
	    }
		if ((x1-rjesenje1)>(-0.1) && (x1-rjesenje1)<0) {printf ("Priblizno manje\n");continue; }
		if ((x1-rjesenje1)<=(-0.1)) {printf ("Manje\n"); continue; }
		if ((x1-rjesenje1)<0.1 && (x1-rjesenje1)>0) {printf ("Priblizno vece\n"); continue; }
		if ((x1-rjesenje1)>=0.1) {printf ("Vece\n"); continue;  }
			
	}

for ( ; ; ) {
	printf ("Unesite rjesenje x2: ");
	scanf ("%lf", &x2);
	
if(fabs(x2-rjesenje2)<0.001) {printf ("Tacno\n");break;}
if ((x2-rjesenje2)>(-0.1) && (x2-rjesenje2)<0) {printf ("Priblizno manje\n");continue; }
if ((x2-rjesenje2)<=(-0.1)) {printf ("Manje\n"); continue; }
if ((x2-rjesenje2)<0.1 && (x2-rjesenje2)>0) {printf ("Priblizno vece\n"); continue; }
if ((x2-rjesenje2)>=0.1) {printf ("Vece\n"); continue;  }
}
	return 0;
}
