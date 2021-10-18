#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a, b, c, x1, x2, D, R1, R2;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;
	
if (D<0)
printf ("Rjesenja su imaginarni brojevi.");

else {	
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a); 
	

do {
printf ("Unesite rjesenje x1: ");
scanf ("%lf", &R1);
	if (fabs (R1-x1)<E) printf ("Tacno\n");
	else if (fabs(R1-x1)<0.1 && R1<x1) printf ("Priblizno manje\n");
	else if (fabs(R1-x1)<0.1 && R1>x1) printf ("Priblizno vece\n");
	else if (R1<x1) printf ("Manje\n");
	else if (R1>x1) printf ("Vece\n");
}
while (fabs (R1-x1)>=E); 



do {
printf ("Unesite rjesenje x2: ");
scanf ("%lf", &R2);
	if (fabs (R2-x2)<E) printf ("Tacno\n");
	else if (fabs(R2-x2)<0.1 && R2<x2) printf ("Priblizno manje\n");
	else if (fabs(R2-x2)<0.1 && R2>x2) printf ("Priblizno vece\n");
	else if (R2<x2) printf ("Manje\n");
	else if (R2>x2) printf ("Vece\n");
}
while (fabs (R2-x2)>=E);
	
}
	return 0;
}