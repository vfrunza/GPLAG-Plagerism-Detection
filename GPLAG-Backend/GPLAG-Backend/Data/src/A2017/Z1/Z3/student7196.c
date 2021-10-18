#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, x1, x2, D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4*a*c;
	
	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	
	double x1p, x2p;
	
	x1p=(-b-sqrt(D))/(2*a);
	x2p=(-b+sqrt(D))/(2*a);
	
	if(x2p<x1p) {
		x2p=(-b-sqrt(D))/(2*a);
		x1p=(-b+sqrt(D))/(2*a);
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if (fabs(x1-x1p)>=EPSILON || fabs(x1-x1p)>fabs(x1-x2p)) {
			if (x1<x1p) {
				if (fabs(x1-x1p)<0.1 && fabs (x1-x1p)>=EPSILON) {
					printf("Priblizno manje\n");
				}
				else if (fabs(x1-x1p)>=0.1) {
					printf("Manje\n");
				}
			}
			else if (x1>x1p) {
				if (fabs(x1-x1p)<0.1 && fabs(x1-x1p)>=EPSILON) {
					printf("Priblizno vece\n");
				}
				else if (fabs(x1-x1p)>=0.1) {
					printf("Vece\n");
				}
			}
		}
		else break;
	} while (fabs(x1-x1p)>=EPSILON || fabs(x1-x1p)>fabs(x1-x2p));
	
	printf("Tacno\n");
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if (fabs(x2-x2p)>=EPSILON || fabs(x2-x2p)>fabs(x2-x1p)) {
			if (x2<x2p) {
				if (fabs(x2-x2p)<0.1 && fabs (x2-x2p)>=EPSILON) {
					printf("Priblizno manje\n");
				}
				else if (fabs(x2-x2p)>=0.1) {
					printf("Manje\n");
				}
			}
			else if (x2>x2p) {
				if (fabs(x2-x2p)<0.1 && fabs(x2-x2p)>=EPSILON) {
					printf("Priblizno vece\n");
				}
				else if (fabs(x2-x2p)>=0.1) {
					printf("Vece\n");
				}
			}
		}
		else break;
	} while (fabs(x2-x2p)>=EPSILON || fabs(x2-x1p)>fabs(x2-x2p));
	
	printf("Tacno");
	
	return 0;
}