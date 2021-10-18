#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define DELTA 0.1

int main() {
	double a,b,c, d, x1, x2, mx1, mx2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	d = b*b - 4*a*c;
	if (d<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1 = (-b + sqrt(d)) / (2*a);
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &mx1);
		if (fabs(x1-mx1) < EPSILON) {
			printf("Tacno\n");
			break;
		}
		if (x1-mx1 > 0 && x1-mx1 < DELTA)
			printf("Priblizno manje\n");
		else if (mx1-x1 > 0 && mx1-x1 < DELTA)
			printf("Priblizno vece\n");
		else if (x1>mx1)
			printf("Manje\n");
		else
			printf("Vece\n");
	} while(1);
	x1 = (-b - sqrt(d)) / (2*a);
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &mx1);
		if (fabs(x1-mx1) < EPSILON) {
			printf("Tacno\n");
			break;
		}
		if (x1-mx1 > 0 && x1-mx1 < DELTA)
			printf("Priblizno manje\n");
		else if (mx1-x1 > 0 && mx1-x1 < DELTA)
			printf("Priblizno vece\n");
		else if (x1>mx1)
			printf("Manje\n");
		else
			printf("Vece\n");
	} while(1);
	
	return 0;
}
