#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a, b, c, x1, x2, D, guess1, guess2, temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;

	if(D<-EPSILON) {printf("Rjesenja su imaginarni brojevi."); return 0; }
	
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if(x2-x1<EPSILON && fabs(x2-x1)>EPSILON) {temp=x2; x2=x1; x1=temp;}
//printf("\n%f %f\n", x1, x2);
	
	for(;;) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &guess1);
		
		if(fabs(x1-guess1)<EPSILON) {printf("Tacno\n"); break;}
		else if(guess1-x1>=0.1) printf("Vece\n");
		else if(x1-guess1>=0.1) printf("Manje\n");
		else if(guess1-x1>=EPSILON) printf("Priblizno vece\n");
		else printf("Priblizno manje\n");
	}
	
	for(;;) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &guess2);
		if(fabs(x2-guess2)<EPSILON) {printf("Tacno\n"); break;}
		else if(guess2-x2>=0.1) printf("Vece\n");
		else if(x2-guess2>=0.1) printf("Manje\n");
		else if(guess2-x2>=EPSILON) printf("Priblizno vece\n");
		else printf("Priblizno manje\n");
	}
	
	return 0;
}
