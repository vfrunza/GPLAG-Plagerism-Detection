#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	double max,min;
	double E = 0.001;
	double a,b,c,D,x1,x2;
	double prvo_rjesenje,drugo_rjesenje; 
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D = b*b - 4*a*c;
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	x1 = (-b - sqrt(D)) / (2*a) ;
	x2 = (-b + sqrt(D)) / (2*a) ;
	
	min = x1;
	max = x2;
	if(x2<min) {
		min = x2;
		max = x1;
	}
	
	x1 = min;
	x2 = max;
	
	// Prvo rješenje
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&prvo_rjesenje);
		if(fabs(x1-prvo_rjesenje) < E) {
			printf("Tacno\n");
			break;
		}
		else if (fabs(x1-prvo_rjesenje) < 0.1) {
			if(prvo_rjesenje > x1) {
				printf("Priblizno vece\n");
			}
			else {
				printf("Priblizno manje\n");
			}
		}
		else {
			if(prvo_rjesenje > x1){
				printf("Vece\n");
			}
			else {
				printf("Manje\n");
			}
		}
	}
	while(fabs(x1-prvo_rjesenje) >= E );
	
	// Drugo rješenje
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&drugo_rjesenje);
		if(fabs(x2-drugo_rjesenje) < E) {
			printf("Tacno\n");
			break;
		}
		else if (fabs(x2-drugo_rjesenje) < 0.1) {
			if(drugo_rjesenje > x2) {
				printf("Priblizno vece\n");
			}
			else {
				printf("Priblizno manje\n");
			}
		}
		else {
			if(drugo_rjesenje > x2){
				printf("Vece\n");
			}
			else {
				printf("Manje\n");
			}
		}
	}
	while(fabs(x2-drugo_rjesenje) >= E );
	
	return 0;
}
