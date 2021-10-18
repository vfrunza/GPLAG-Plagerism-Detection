#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main()
{

	double x1,x2,x11,x22,r1,r2,a,b,c,D;



	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a,&b,&c);


	D=sqrt((b*b) - (4*a*c));
	
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
		
	} else if (D>0) {
		x1=(-b + sqrt(b*b - 4*a*c))/(2*a);
		x2=(-b - sqrt(b*b - 4*a*c))/(2*a);}
	do {
		printf("Unesite rjesenje x1:");
		scanf("%lf%", &x11);
		r1=x1-x11;
		if (x11<x1) {
			printf("Manje\n");
		} else {
			printf("Vece\n");

		}
	} while (fabs(r1>EPSILON));

	do {
		printf ("Unesite rjesenje x1:");

		if (fabs(r1<0.1)) {

			printf ("Priblizno manje\n");
		} else {
			printf ("Priblizno vece\n");

		}
	} while (fabs (r1>EPSILON));
	if(fabs(r1<EPSILON)) {
		printf ("Tacno\n");
	}

	do {
		printf ("Unesite rjesenje x2:");
		scanf ("%lf", &x22);
		r2=x2-x22;
		if(x22<x2) {
			printf("Manje\n");
		} else {
			printf ("Vece\n");
		}

	} while (fabs(r2>EPSILON));

	do {
		printf ("Unesite rjesenje x2:");
		scanf ("%lf",&x22);
		if (fabs(r2<0.1)) {
			printf("Priblizno manje\n");
		} else {
			printf ("Priblizno vece\n");
		}
	} while (fabs(r2>EPSILON));
	if(fabs(r2<EPSILON)) {
		printf ("Tacno");
	}


	return 0;
}
