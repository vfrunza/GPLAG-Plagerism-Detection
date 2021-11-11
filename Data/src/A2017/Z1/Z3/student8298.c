#include <stdio.h>
#include <math.h>
#define E 0.001

int main()
{
	int i, j;
	double a, b, c, x1, x2, D=0, X1=0, X2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=(pow(b,2)-4.00*a*c);
	X1=((-b+sqrt(D))/2*a);
	X2=((-b-sqrt(D))/2*a);

	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	for (i=0;; i++) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if((X1-x1)<E) {
			printf("Tacno\n");
			break;
		} else if (x1>X1) {
			if(fabs(X1-x1)<0.1)
				printf("Priblizno vece\n");
		} else if(fabs(X1-x1)>=0.1) {
			printf("Vece\n");
		} else if (x1<X1) {
			if(fabs(X1-x1)<0.1)
				printf("Priblizno manje\n");
		} else if(fabs(X1-x1)>=0.1) {
			printf("Manje\n");
		}}
		for(j=0;; j++) {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			if(abs(X2-x2)<E) {
				printf("Tacno\n");
				break;
			} else if (x2>X2) {
				if (fabs(X1-x1)<0.1) {
					printf("Priblizno vece\n");
				} else if(fabs(X2-x2)>=0.1) {
					printf("Vece\n");
				} else if (x2<X2) {
					if(fabs(X2-x2)<0.1)
						printf("Priblizno manje\n");
				} else if(fabs(X2-x2)>=0.1) {
					printf("Manje\n");
				}
			}
		}
		return 0;
	}