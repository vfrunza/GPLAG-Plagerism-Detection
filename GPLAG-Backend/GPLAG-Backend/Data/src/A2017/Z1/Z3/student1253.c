#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	int i;
	double a, b, c, x1, x2, D, y1, y2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D = pow(b,2) - 4.0*a*c;
	x1 = (-b - sqrt(D))/(2.0*a);
	x2 = (-b + sqrt(D))/(2.0*a);
	
	if(a<0) {
		x1 = (-b + sqrt(D))/(2.0*a);
		x2 = (-b - sqrt(D))/(2.0*a);
	}
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else {
		for(i=0; ;i++) {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &y1);
			if(fabs(x1-y1)<EPSILON) {
				printf("Tacno");
				break;
			}
			else if(x1<y1) {
				if(fabs(x1-y1)<0.1) {
					printf("Priblizno vece");
				}
				else {
					printf("Vece");
				}
			}
			else if(x1>y1) {
				if(fabs(x1-y1)<0.1) {
					printf("Priblizno manje");
				}
				else {
					printf("Manje");
				}
			}
			printf("\n");
		}
		
		printf("\n");
		
		for(i=0; ;i++) {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &y2);
			if(fabs(x2-y2)<EPSILON) {
				printf("Tacno");
				break;
			}
			else if(x2>y2) {
				if(fabs(x2-y2)<0.1) {
					printf("Priblizno manje");
				}
				else {
					printf("Manje");
				}
			}
			else if(x2<y2) {
				if(fabs(x2-y2)<0.1) {
					printf("Priblizno vece");
				}
				else {
					printf("Vece");
				}
			}
			
		printf("\n");
		}
	}
	
	
	
	
	return 0;
}
