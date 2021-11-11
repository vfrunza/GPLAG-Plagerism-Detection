#include <stdio.h>
#include <math.h>

#define EPSILON 0.001
#define priblizno 0.1

int main()
{

	
	double x1u, x2u, x1, x2, a, b, c, D,t;
	double min,max;



	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c );


	D=pow(b,2)-(4*a*c);

	if 	 (D<0) {

		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}

	else {

		x1=(-b-(sqrt(D)))/(2.*a);
		x2=(-b+(sqrt(D)))/(2.*a);


		min=x1;
		max=x2;
		
			
		if(x1>x2) {
			t=x2;
			x2=x1;
			x1=t;
		}

	
		do {
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf", &x1u);

			if(fabs(x1u-min)<EPSILON) {
				printf("Tacno\n");
				break;
			}	
			else if (fabs(x1u-min)<priblizno && x1u<min) {
				printf("Priblizno manje\n");


			}
			else if (x1u<min) {
				printf ("Manje\n");

			}
		
			else if  (fabs(x1u-min)<priblizno && x1u>min) {
				printf("Priblizno vece\n");

			}
			
			else if (x1u>min){
				printf("Vece\n");
			}

		} while(fabs(x1u-min)>=EPSILON);

		do {
			printf ("Unesite rjesenje x2: ");
			scanf ("%lf", &x2u);

			if(fabs(x2u-max)<EPSILON) {
				printf("Tacno\n");
				break;
			}
			else if (fabs(x2u-max)<priblizno && x2u<max) {
				printf("Priblizno manje\n");


			}

			else if (x2u<max) {
				printf ("Manje\n");

			}
			else if  (fabs(x2u-max)<priblizno && x2u>max) {
				printf("Priblizno vece\n");

			}
			
			else if (x2u>max){
				printf("Vece\n");

			}
		} while(fabs(x2u-max)>=EPSILON);

	}
	return 0;
}
