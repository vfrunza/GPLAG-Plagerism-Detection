#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	double a, b, c, x1, x2, D, K, rjesenje1, rjesenje2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D>0 || fabs(D)<eps) {
		K=sqrt(D);
		x1=(-b+K)/(2*a);
		x2=(-b-K)/(2*a);
		
		
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&rjesenje1);
			if(fabs(x1-rjesenje1)<eps)
			printf("Tacno\n");
			else if(rjesenje1 > x1 && fabs(rjesenje1-x1)<0.1)
			printf("Priblizno vece\n");
			else if(rjesenje1 < x1 && fabs(rjesenje1-x1)<0.1)
			printf("Priblizno manje\n");
			else if(rjesenje1 > x1)
			printf("Vece\n");
			else if(rjesenje1 < x1)
			printf("Manje\n");
			}
		while(!(fabs(rjesenje1 - x1)<eps));
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&rjesenje2);
			if(fabs(x2-rjesenje2)<eps)
			printf("Tacno\n");
			else if(rjesenje2 > x2 && fabs(rjesenje2 - x2)<0.1)
			printf("Priblizno vece\n");
			else if(rjesenje2 < x2 && fabs(rjesenje2 - x2)<0.1)
			printf("Priblizno manje\n");
			else if(rjesenje2 > x2)
			printf("Vece\n");
			else if(rjesenje2 < x2)
			printf("Manje\n");
			}
		while(!(fabs(rjesenje2 - x2)<eps));
		}
	else { 
		printf("Rjesenja su imaginarni brojevi."); 
	}
	return 0;
}
