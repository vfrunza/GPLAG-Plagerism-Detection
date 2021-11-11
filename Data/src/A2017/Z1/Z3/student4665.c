#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main()
{
	double a,b,c,D,x1,x2,x1t,x2t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=b*b-4*a*c;
	x1t=(-b-sqrt(D))/(fabs(2*a));
	x2t=(-b+sqrt(D))/(fabs(2*a));

	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}

	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);

		if(fabs(x1-x1t)<=EPSILON) {
			printf("Tacno\n");
			do {
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x2);

				if(fabs(x2-x2t)<EPSILON) {
					printf("Tacno\n");
				}else if(fabs(x2-x2t)>0.1 && fabs(x2-x2t)<EPSILON) {
					printf("Priblizno vece\n");
				}else if(fabs(x2-x2t)<0.1 && fabs(x2-x2t)>EPSILON) {
					printf("Priblizno manje\n");
				}else if(x2<x2t){
					printf("Manje\n");
				}else if(x2>x2t) {
					printf("Vece\n");
				} 
			} while(fabs(x2-x2t)>EPSILON);
		}else if(fabs(x1-x1t)>0.1 && fabs(x1-x1t)<EPSILON) {
			printf("Priblizno vece\n");
		}else if(x1>x1t) {
			printf("Vece\n");
		}else if(fabs(x1-x1t)<0.1 && fabs(x1-x1t)>EPSILON) {
			printf("Priblizno manje\n");
		} else if(x1<x1t) {
			printf("Manje\n");
		} 
	} while (fabs(x1-x1t)>EPSILON);
	return 0;
}
