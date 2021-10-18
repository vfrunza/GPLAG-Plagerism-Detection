#include <stdio.h>
#include <math.h>
const double EPSILON=0.001;
int main() {
	int a,b,c;
	float x1,x2,x11,x22,D;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%d%d%d", &a, &b, &c);
	if (((b*b)-(4*a*c))<0) {
		printf ("\nRjesenja su imaginarni brojevi.");
		return 1;}
	x22 = (-1*b+sqrt((b*b)-(4*a*c)))/(2*a);
	x11 = (-1*b-sqrt((b*b)-(4*a*c)))/(2*a);
	
	printf ("\nUnesite rjesenje x1: ");
	scanf ("%f", &x1);
	

		while (((x1-x11)>0.1)) {
		printf ("\nVece");
		printf ("\nUnesite rjesenje x1: ");
		scanf ("%f", &x1);
		}
		while ((x11-x1)>0.1) {
		printf ("\nManje"); 
		printf ("\nUnesite rjesenje x1: ");
		scanf ("%f", &x1);
		}
		while ((x1-x11)<0.1 && (x1-x11)>EPSILON) {
		printf ("\nPriblizno vece");
			printf ("\nUnesite rjesenje x1: ");
		scanf ("%f", &x1);
		}
		while ((x11-x1)<0.1 && (x11-x1)>EPSILON) {
		printf ("\n Priblizno manje");
				printf ("\nUnesite rjesenje x1: ");
		scanf ("%f", &x1);
		}
		if ((fabs(x1-x11))<EPSILON) {
			printf ("\nTacno");
		}
		
		printf ("Unesite rjesenje x2: ");
		scanf ("%f", &x2);
	
		while ((x2-x22)>0.1) {
		printf ("\nVece");
		printf ("\nUnesite rjesenje x2: ");
		scanf ("%f", &x2);
		}
		while ((x22-x2)>0.1) {
		printf ("\nManje"); 
		printf ("\nUnesite rjesenje x2: ");
		scanf ("%f", &x2);
		}
		while ((x2-x22)<0.1 && (x2-x22)>EPSILON) {
		printf ("\nPriblizno vece");
			printf ("\nUnesite rjesenje x2: ");
		scanf ("%f", &x2);
		}
		while ((fabs(x22-x2))<0.1 && (fabs(x22-x2))>EPSILON) {
		printf ("\nPriblizno manje");
		printf ("\nUnesite rjesenje x2: ");
		scanf ("%f", &x2);
		}
		if ((fabs(x22-x2))<EPSILON) {
		printf ("Tacno"); }
return 0;
}