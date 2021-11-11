#include <stdio.h>
#include<math.h>
#define E 0.001
#define e 0.1

int main()
{
	double a,b,c,D,x1,x2,d1,d2,K=0;
	do {
		printf("Unesite koeficijente a, b i c: ");
		scanf("%lf %lf %lf",&a,&b,&c);
	} while(fabs(a-K)<0.000001);
	D=b*b-4*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} else {
		if(fabs(b-K)<0.000001) {
			x1=(sqrt(D)/(2*a));
			if((c-K)<0.000001){ x2=sqrt(D)/(2*a);} else{
			x2=-sqrt(D)/(2*a);}

		} else {
			x1=	(-b-sqrt(D))/(2*a);
			x2= (-b+sqrt(D))/(2*a);
		}
	

	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&d1);
		if(fabs(d1-x1)>=E) {
			if(fabs(d1-x1)<e) {
				if((d1<x1)) {
					printf("Priblizno manje\n");
				} else {

					if((x1<d1))
						printf("Priblizno vece\n");
				}
			}

			else {
				if(d1<x1) {
					printf("Manje\n");
				} else {
					if(d1>x1) {
						printf("Vece\n");
					}
				}
			}
		} else {

			if(fabs(d1-x1)-E<0.000001) {
				printf("Tacno\n");

			}
		}
	}

	while((fabs(d1-x1)>=E));
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&d2);
		if(fabs(d2-x2)>=E) {
			if(fabs(d2-x2)<e) {
				if((d2<x2)) {
					printf("Priblizno manje\n");
				} else {

					if((x2<d2))
						printf("Priblizno vece\n");
				}
			}

			else {
				if(d2<x2) {
					printf("Manje\n");
				} else {
					if(d2>x2) {
						printf("Vece\n");
					}
				}
			}
		} else {

			if(fabs(d2-x2)-E<0.000001) {
				printf("Tacno\n");

			}
		}
	}

	while((fabs(d2-x2)>=E));

}


return 0;
}
