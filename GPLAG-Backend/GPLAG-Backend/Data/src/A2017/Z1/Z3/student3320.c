#include <stdio.h>
#include <math.h>

#define eps 0.001
#define T 0.1

int main() {
	int a, b, c;
	double D, x1, x2, t;
	double unos1, unos2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	
	D=b*b-4.0*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	t=sqrt(D);
	x1=(-b+t)/(2*a);
	x2=(-b-t)/(2*a);
	

ponovi:	
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &unos1);
	if((unos1-x1<=eps && unos1-x1>=0) || (x1-unos1<=eps && x1-unos1>=0)) { 
		printf("Tacno\n");
		goto dalje;
	} else {
		if((fabs(unos1-x1))<=T && (fabs(unos1-x1))>=0) {
			if(unos1<x1) {
				printf("Priblizno manje\n");
				goto ponovi;
			} else {
				if(unos1>x1) {
					printf("Priblizno vece\n");
					goto ponovi;
				}
			}
		} else {
			if(unos1<x1) {
				printf("Manje\n");
				goto ponovi;
			} else {
				if(unos1>x1) {
					printf("Vece\n");
					goto ponovi;
				}
			}
		}
	}
	
dalje:
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &unos2);
	if((unos2-x2<=eps && unos2-x2>=0) || (x2-unos2<=eps && x2-unos2>=0)) {
		printf("Tacno");
		return 0;
	} else {
		if((fabs(unos2-x2))<=T && (fabs(unos2-x2))>=0) {
			if(unos2<x2) {
				printf("Priblizno manje\n");
				goto dalje;
			} else {
				if(unos2>x2) {
					printf("Priblizno vece\n");
					goto dalje;
				}
			}
		} else {
			if(unos2<x2) {
				printf("Manje\n");
				goto dalje;
			} else {
				if(unos2>x2) {
					printf("Vece\n");
					goto dalje;
				}
			}
		}
	}

	return 0;
}
