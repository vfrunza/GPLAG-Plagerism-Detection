#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main()
{
	double a,b,c,x1,x2,x11,x22,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);

	D = (pow(b,2)-(4*a*c));
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
		
	if (a<0 && b<0) {
		x11=(-b-(sqrt(D)))/(2*a);
		x22=(-b+(sqrt(D)))/(2*a);
	} else 	 {
		x11=(-b+(sqrt(D)))/(2*a);
		x22=(-b-(sqrt(D)))/(2*a);
	}

	do {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x1);
		
		if (fabs (x11-x1)<epsilon) {
			printf ("Tacno\n");
		}

		if ((x1-x11)>=0.1) {
			printf("Vece\n");
		}


		if ((x1-x11)<0.1 && (x1-x11)>=epsilon) {
			printf("Priblizno vece\n");
		}
		if ((x1-x11)<=(-0.1)) {
			printf("Manje\n");
		}

		if ((x1-x11)>-0.1 && (x1-x11)<=(-epsilon)) {
			printf("Priblizno manje\n");
		}


	} while (fabs (x11-x1)>=epsilon);
	
	

	do {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &x2);


		if (fabs (x22-x2)<=epsilon) {
			printf ("Tacno\n");
		}

		if ((x2-x22)>=0.1) {
			printf("Vece\n");
		}


		if ((x2-x22)<0.1 && (x2-x22)>=epsilon) {
			printf("Priblizno vece\n");
		}
		if ((x2-x22)<=(-0.1)) {
			printf("Manje\n");
		}

		if ((x2-x22)>-0.1 && (x2-x22)<=(-epsilon)) {
			printf("Priblizno manje\n");
		}


	} while (fabs (x22-x2)>=epsilon);

	return 0;
}
	