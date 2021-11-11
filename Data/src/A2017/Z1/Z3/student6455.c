#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main()
{

	double a,b,c,x1,x2,D,k1,k2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	D=(b*b-4*a*c);

	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}


	if((a<0) && (b<=0)) {
		x1=(-b+(sqrt(D)))/(2*a);
		x2=(-b-(sqrt(D)))/(2*a);
	}

	else {
		x2=(-b+(sqrt(D)))/(2*a);
		x1=(-b-(sqrt(D)))/(2*a);
	}



	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &k1);


		if(fabs(k1-x1)<epsilon)
			printf("Tacno\n");
		else if(k1>x1) {
			if((fabs(k1-x1))<0.1) {
				printf("Priblizno vece\n");
			} else {
				printf("Vece\n");
			}

		} else if(k1<x1) {

			if((fabs(x1-k1))<0.1)
				printf("Priblizno manje\n");
			else
				printf("Manje\n");
		}

	} while(((fabs(k1-x1))>=epsilon));





	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &k2);

		if((fabs(k2-x2))<epsilon)
			printf("Tacno\n");
		else if(k2>x2) {
			if((fabs(k2-x2))<0.1)
				printf("Priblizno vece\n");
			else
				printf("Vece\n");

		} else if(k2<x2) {

			if((fabs(x2-k2))<0.1) {
				printf("Priblizno manje\n");
			} else {
				printf("Manje\n");
			}
		}

	} while(((fabs(k2-x2))>=epsilon));






	return 0;
}
