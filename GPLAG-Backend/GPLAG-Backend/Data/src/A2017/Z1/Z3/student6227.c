#include <stdio.h>
#include <math.h>
int main() {
	double E1=0.001, E2=0.1;
	double a, b, c, D, x1, x2, rez, dx1, dx2, temp;
	int pret_1 = 0, pret_2 = 0, pret_3 = 0, pret_4 = 0;
	printf("Unesite koeficijente a, b i c: "); scanf("%lf %lf %lf", &a, &b, &c);
	D = b*b - 4*a*c;
	if(D < 0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1 = ( (-b - sqrt( D ) ) / (2 * a) );
	x2 = ( (-b + sqrt( D ) ) / (2 * a) );
	if(x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	} 
	if( fabs(x1) < E1 || fabs(x2) < E1 ) {
		E1 = E1/10;
		E2 = E2/10;
	}
	do {
		printf("Unesite rjesenje x1: "); scanf("%lf", &rez);
		dx1 = fabs(x1-rez);
		if(dx1 >= -E2 && dx1 <= E2  && dx1 != 0 && fabs(x1-rez) > E1 && rez > x1 && fabs(x2-rez) > E1 ) {
			printf("Priblizno vece\n");
			pret_1 = 1;
		}
		if(dx1 >= -E2 && dx1 <= E2 && dx1 != 0  && fabs(x1-rez) > E1 && rez < x1 && fabs(x2-rez) > E1 ) {
			printf("Priblizno manje\n");
			pret_2 = 1;
		}
		if( rez > x1 && pret_1 != 1 && pret_2 != 1 && dx1 > E1 ) printf("Vece\n");
		if( rez < x1 && pret_1 != 1 && pret_2 != 1 && dx1 > E1 ) printf("Manje\n");
		
	}while( fabs(x1 - rez) > E1 );
	printf("Tacno\n");
	do {
		printf("Unesite rjesenje x2: "); scanf("%lf", &rez);
		dx2 = fabs(x2-rez);
		if(dx2 >= -E2 && dx2 <= E2  && dx2 != 0 && fabs(x2-rez) > E1 && rez > x2 && fabs(x2-rez) > E1 ) {
			printf("Priblizno vece\n");
			pret_3 = 1;
		}
		if(dx2 >= -E2 && dx2 <= E2 && dx2 != 0  && fabs(x2-rez) > E1 && rez < x2 && fabs(x2-rez) > E1 ) {
			printf("Priblizno manje\n");
			pret_4 = 1;
		}
		if( rez > x2 && pret_3 != 1 && pret_4 != 1 && dx2 > E1 ) printf("Vece\n");
		if( rez < x2 && pret_3 != 1 && pret_4 != 1 && dx2 > E1 ) printf("Manje\n");
		
	}while( fabs(x2 - rez) > E1 );
	printf("Tacno\n");
	return 0;
}
