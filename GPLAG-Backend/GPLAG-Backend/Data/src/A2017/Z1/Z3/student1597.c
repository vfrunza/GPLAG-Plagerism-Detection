#include <stdio.h>
#include <math.h>
#define ep 0.001

int main() {
	double a,b,c,D,x1,x2,r1,r2,razlika1,razlika2, izmjena;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if (D < 0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if (fabs(a) < ep) {
		printf("Neispravan unos.");
		return 0;
	}
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if (x2 < x1) {
		izmjena = x1;
		x1 = x2;
		x2 = izmjena;
	} 
	do {
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&r1);
	razlika1 = fabs(x1-r1);
	if (ep > razlika1 && razlika1 > -ep) {
				printf("Tacno\n"); 
				break;
	}
			if (0.1 > x1-r1 && x1-r1 >= ep) 
				printf("Priblizno manje\n");
			if (x1-r1 >= 0.1)
				printf("Manje\n");
			if (x1-r1 <= -0.1)
				printf("Vece\n");
			if (-0.1 < x1-r1 && x1-r1 <= -ep)
				printf("Priblizno vece\n");
	}
	while (razlika1 >= ep);  
	do {
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&r2);
	razlika2=fabs(x2-r2);
	if (ep > razlika2 && razlika2 > -ep) {
				printf("Tacno\n"); 
				break;
	}
			if (0.1 > x2-r2 && x2-r2 >= ep) 
				printf("Priblizno manje\n");
			if (x2-r2 >= 0.1)
				printf("Manje\n");
			if (x2-r2 <= -0.1)
				printf("Vece\n");
			if (-0.1 < x2-r2 && x2-r2 <= -ep)
				printf("Priblizno vece\n");
		} 
	while (razlika2 >= ep);
	
	return 0;
}
