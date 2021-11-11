#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define EPSILON1 0.1

int main() {
	double a, b, c, D, x1, x2, broj1, broj2, p;
	
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	D = b*b - 4*a*c;
	
	if (D<0) printf ("Rjesenja su imaginarni brojevi.");
	else {
		broj1 = (-b-sqrt(D))/(2*a);
		broj2 = (-b+sqrt(D))/(2*a);
		if (broj2<broj1) { /*u slucaju da broj1 nije manje rjesenje, vrsi se zamjena*/
			p=broj1;
			broj1=broj2;
			broj2=p;
			
		}
		
		do {
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf", &x1);
			
 			if (fabs(x1 - broj1)<EPSILON1 && fabs(x1 - broj1)>=EPSILON) {
 				if (x1<broj1)
 					printf ("Priblizno manje\n");
 				else if (x1>broj1)
 					printf ("Priblizno vece\n");
 			}
			else if (x1 > broj1 && fabs(x1 - broj1)>=EPSILON) printf ("Vece\n");
			else if (x1 < broj1 && fabs(x1 - broj1)>=EPSILON) printf ("Manje\n");
			
		} while (fabs(x1 - broj1)>=EPSILON);
		
		
		if (fabs(x1 - broj1)<EPSILON) {
			printf ("Tacno");
			
			do {
			printf ("\nUnesite rjesenje x2: ");
			scanf ("%lf", &x2);
			
 			if (fabs(x2 - broj2)<EPSILON1 && fabs(x2 - broj2)>=EPSILON) {
 				if (x2<broj2)
 					printf ("Priblizno manje");
 				else if (x2>broj2)
 					printf ("Priblizno vece");
 			}
			else if (x2 > broj2 && fabs(x2 - broj2)>=EPSILON) printf ("Vece");
			else if (x2 < broj2 && fabs(x2 - broj2)>=EPSILON) printf ("Manje");
			
		} while (fabs(x2 - broj2)>=EPSILON);
			
			if (fabs(x2 - broj2)<EPSILON) {
				printf ("Tacno");
			}
		}
		
	}
	
	
	return 0;
}
