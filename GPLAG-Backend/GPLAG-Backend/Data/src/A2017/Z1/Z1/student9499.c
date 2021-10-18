#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define ERR .000001

/* definitions */
#define P_1 6.8
#define P_2 8.0
#define P_3 5.3

#define H_1 3.3
#define H_2	3.0
#define H_3	5.0

#define C_1	5.0
#define C_2	3.9
#define C_3	6.0

/* global variable */
int _prvo = 0, _drugo = 0, _trece = 0;

/* choose meal */
int take(char a) {
	int test = 1;
	if(toupper(a) == 'P') _prvo++;
	else if(toupper(a) == 'H') _drugo++;
	else if(toupper(a) == 'C') _trece++;
	else test = 0;
	return test;
}

/* min */
double min(double a, double b) {
	return (a < b ? a:b);
}

int main() {
	/* initial */
	char _T, _B, _M, temp;
	double C1 = .0, C2 = .0, C3 = .0, C_discount = .0,
		d1 = .0, d2 = .0, d3 = .0, min_ = .0;
	
	/* input */
	printf("Unesite jelo za Tarika: "); scanf("%c", &_T); scanf("%c", &temp);
	printf("Unesite jelo za Bojana: "); scanf("%c", &_B); scanf("%c", &temp);
	printf("Unesite jelo za Mirzu: "); scanf("%c", &_M); scanf("%c", &temp);

	/* calculate */
	if(!take(_T)) return 0;
	if(!take(_B)) return 0;
	if(!take(_M)) return 0;
	
	C1 = P_1*_prvo + H_1*_drugo + C_1*_trece;
	C2 = P_2*_prvo + H_2*_drugo + C_2*_trece;
	C3 = P_3*_prvo + H_3*_drugo + C_3*_trece;
	
	/* choose min value for meal discount */
	d1 = -0.1*P_1*_prvo;
	d2 = -0.1*H_1*_drugo;
	d3 = -0.1*C_1*_trece;
	
	/* output */
	C_discount = C1 + min(min(d1, d2), d3); /* discount price */
	min_ = min(min(C1, C2), C3); /* minimum price */
	
	if(fabs(min_ - C1) < ERR)
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min_);
	else if(fabs(min_ - C2) < ERR)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min_);
	else if(fabs(min_ - C3) < ERR)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min_);
	
	if(fabs(min_ - C1) > ERR && (min_ > C_discount))
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", C_discount);

	return 0;
}