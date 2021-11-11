#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,x1,x2,x1p,x2p;
	double D;
	int izlazak=0;

	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf", &a);
	scanf ("%lf", &b);
	scanf ("%lf", &c);

	D=((b*b)-(4*a*c));
	if(D<0)
		printf("Rjesenja su imaginarni brojevi.");
	else {
		x1=(((-b)/(2*a))+((sqrt(D))/(2*a)));
		x2=(((-b)/(2*a))-((sqrt(D))/(2*a)));

		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1p);

		do {

			if(fabs(x1p-x1)<0.001) {

				printf("Tacno\n");
				izlazak=1;
			} else if (fabs(x1p-x1)>=0.001 && x1p<x1 && !(fabs(x1-x1p)<0.1)) {
				printf("Manje\n");
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1p);
			} else if (fabs(x1p-x1)>=0.001 && x1p>x1 && !(fabs(x1p-x1)<0.1)) {
				printf("Vece\n");
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1p);
			}

			else if(fabs(x1p-x1)>=0.001 && (x1-x1p)<0.1 && (x1-x1p)>0) {


				printf("Priblizno manje\n");
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1p);
			} else if(fabs(x1p-x1)>=0.001 && (x1p-x1)<0.1 && (x1p-x1)>0) {


				printf("Priblizno vece\n");
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1p);
			}
		} while (izlazak==0);
		izlazak=0;
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2p);

		do {
			if(fabs(x2p-x2)<0.001) {
				printf("Tacno\n");
				izlazak=1;
			} else if (fabs(x2p-x2)>=0.001 && x2p<x2 && !(fabs(x2-x2p)<0.1)) {
				printf("Manje\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2p);
			} else if (fabs(x2p-x2)>=0.001 && x2p>x2 && !(fabs(x2p-x2)<0.1)) {
				printf("Vece\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2p);
			} else if (fabs(x2p-x2)>=0.001 && (x2-x2p)<0.1 && (x2-x2p)>0) {
				printf("Priblizno manje\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2p);
			} else if (fabs(x2p-x2)>=0.001 && (x2p-x2)<0.1 && (x2p-x2)>0) {
				printf("Priblizno vece\n");
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2p);
			}

		} while (izlazak==0);
	}
	return 0;
}















