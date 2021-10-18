#include <stdio.h>
#define E 0.001
#include <math.h>
int main() {
	double a,b,c,x1,x2,r1,r2,D,t1,t2,q,w;
	t1 = 0;
	t2 = 0;
	printf ("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D = b*b - (4*a*c);
	if (D < 0) {
		printf ("Rjesenja su imaginarni brojevi.");
	} else {
		x1 = (-b + sqrt(D)) / (2*a);
		x2 = (-b - sqrt(D)) / (2*a);
		do {
			printf ("Unesite rjesenje x1: ");
			r1 =0; 
			scanf ("%lf",&r1);
			q = fabs(x1 - r1);
			if (q < 0.001) {
				printf ("Tacno\n");
				t1 = 1;
			} else if (fabs(x1 - r1) < 0.1) {
				if (r1 > x1) {
					printf ("Priblizno vece\n");
				} else if ( r1 < x1 ) {
					printf ("Priblizno manje\n");
				}
			} else if (r1 < x1) {
				printf ("Manje\n");
			} else if (r1 > x1) {
				printf ("Vece\n");
			}
		} while (t1 == 0);
		do {
			printf ("Unesite rjesenje x2: ");
			r2 =0; 
			scanf ("%lf",&r2);
			w = fabs(x2 - r2);
			if (w < 0.001) {
				printf ("Tacno\n");
				t2 = 1;
			} else if (fabs(x2 - r2) < 0.1) {
				if (r2 > x2) {
					printf ("Priblizno vece\n");
				} else if ( r2 < x2 ) {
					printf ("Priblizno manje\n");
				}
			} else if (r2 < x2) {
				printf ("Manje\n");
			} else if (r2 > x2) {
				printf ("Vece\n");
			}
	} while (t2 == 0);
	}
	return 0;
}
