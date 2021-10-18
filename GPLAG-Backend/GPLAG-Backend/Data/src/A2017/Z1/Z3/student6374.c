#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define E 0.1
int main()
{
	double a, b, c, D, x1, x2, X1, X2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;
	if (a>0) {
		x1=(-b+sqrt(D))/2*a;
		x2=(-b-sqrt(D))/2*a;
	} else if (a<0) {
		x2=(-b+sqrt(D))/2*a;
		x1=(-b-sqrt(D))/2*a;
	}
	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &X1);
		if (fabs(x1-X1)<EPSILON) {
			break;
		}
		if (X1<x1 && fabs(x1-X1)<E) {
			printf("Priblizno manje\n");
		} 
		if (X1<x1)
			printf ("Manje\n");

		if (X1>x1 && fabs(x1-X1)<E) {
			printf("Priblizno vece\n");
		} 
		if (X1>x1)
			printf ("Vece\n");

	} while (x1!=X1);
	printf ("Tacno");

	do {
		printf("\nUnesite rjesenje x2: ");
		scanf("%lf", &X2);
		if (fabs(x1-X1)<EPSILON) {
			break;
		}
		if ((X2<x2) && fabs(x2-X2)<E) {
			printf("Priblizno manje\n");
		} 
		if (X2<x2)
			printf ("Manje\n");

		if ((X2>x2) && fabs(x2-X2)<E) {
			printf("Priblizno vece\n");
		} 
		if (X2>x2)
			printf ("Vece\n");

	} while (x2!=X2);
	printf("Tacno");


	return 0;
}
