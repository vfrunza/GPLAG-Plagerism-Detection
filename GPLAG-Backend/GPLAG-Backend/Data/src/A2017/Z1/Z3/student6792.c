#include <stdio.h>
#include <math.h>
#define E 0.001
int main()
{
	double a,b,c,D,x1,x2,x,l;

	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	if(fabs(a)<E) printf("Linearna jednacina\n");
	else {
		
		D=b*b-4*a*c;
		if(D<0)	printf("Rjesenja su imaginarni brojevi.");
		else {
			x1=(-b-sqrt(D))/(2*a);
			x2=(-b+sqrt(D))/(2*a);
			if(x2<x1) {
				l=x1;
				x1=x2;
				x2=l;
			}

			do {
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x);
				if(fabs(x-x1)<E) {
					printf("Tacno\n");
					break;
				}

				if(x<x1) {
					if(fabs(x-x1)<0.1) printf("Priblizno manje\n");
					else printf("Manje\n");
				}   else {
					if(fabs(x-x1)<0.1) printf("Priblizno vece\n");
					else printf("Vece\n");
				}
			} while(1);

			do {
				printf("Unesite rjesenje x2: ");
				scanf("%lf", &x);

				if(fabs(x-x2)<=E) {
					printf("Tacno\n");
					break;
				}

				if(x<x2) {
					if(fabs(x-x2)<0.1) printf("Priblizno manje\n");
					else printf("Manje\n");
				}

				else {
					if(fabs(x-x2)<0.1)
						printf("Priblizno vece\n");
					else
						printf("Vece\n");
				}
			} while(1);
		}
	}
	return 0;
}