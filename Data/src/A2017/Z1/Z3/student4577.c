#include <stdio.h>
#include <math.h>
#define eps 0.001


int main()
{
	double a,b,c;
	double x1,x2,pretvarac;
	double D;
	double r1,r2;


	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-(4.0)*a*c;
	x1=((-1)*b+sqrt(D))/(2.0*a);
	x2=((-1)*b-sqrt(D))/(2.0*a);
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else {
		if(x1>x2) {
			pretvarac=x1;
			x1=x2;
			x2=pretvarac;
		}
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&r1);
			if(fabs(r1-x1)<eps) {
				printf("Tacno\n");


			} else {
				if(r1<=x1 && x1-r1<0.1) printf("Priblizno manje\n");
				else if(r1<=x1 && x1-r1>=0.1) printf("Manje\n");
				else if(r1>=x1 && r1-x1<0.1) printf("Priblizno vece\n");
				else if(r1>=x1 && r1-x1>=0.1) printf("Vece\n");

			}


		} while(fabs(r1-x1)>=eps);



		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&r2);
			if(fabs(r2-x2)<eps) {
				printf("Tacno\n");


			} else {
				if(r2<x2 && x2-r2<0.1) printf("Priblizno manje\n");
				else if(r2<x2 && x2-r2>=0.1) printf("Manje\n");
				else if(r2>x2 && r2-x2<0.1) printf("Priblizno vece\n");
				else if(r2>x2 && r2-x2>=0.1) printf("Vece\n");

			}
		} while(fabs(r2-x2)>=eps);



	}






	return 0;
}
