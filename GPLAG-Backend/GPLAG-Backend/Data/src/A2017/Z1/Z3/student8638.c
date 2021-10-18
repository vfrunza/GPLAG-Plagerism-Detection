#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a, b, c, x1, x2, D, X1, X2;
	double temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	
	if(x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	while (1) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &X1);
		if(fabs(X1-x1) < E) {
			printf("Tacno\n");
			break;
			}
		else if ((X1-x1) < 0 && fabs(X1-x1) < 0.1)
		printf("Priblizno manje\n");
		else if ((X1-x1) > 0 && fabs(X1-x1) < 0.1)
		printf("Priblizno vece\n");
		else if ((X1-x1) < 0 && fabs(X1-x1) >= 0.1)
		printf("Manje\n");
		else 
		printf("Vece\n");
	}
	
	while (2) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &X2);
		if(fabs(X2-x2) < E) {
		printf("Tacno\n");
		break;
		}
		else if ((X2-x2) < 0 && fabs(X2-x2) < 0.1)
			printf("Priblizno manje\n");
		else if ((X2-x2) > 0 && fabs(X2-x2) < 0.1)
			printf("Priblizno vece\n");
		else if ((X2-x2) < 0 && fabs(X2-x2) >= 0.1)
			printf("Manje\n");
		else
			printf("Vece\n");
	}
	
	
	return 0;
}
