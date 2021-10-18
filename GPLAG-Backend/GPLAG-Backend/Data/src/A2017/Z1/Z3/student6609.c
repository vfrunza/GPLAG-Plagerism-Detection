#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	
	double a, b, c, D, x1=0, x2=0, prvo_rjesenje, drugo_rjesenje, temp=0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	
	if (x1>x2) {
		temp=x2;
		x2=x1;
		x1=temp;
	}
	
	for(;;) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &prvo_rjesenje);
		if(fabs(x1-prvo_rjesenje)<eps) {
			printf("Tacno\n");
			break;
		}
		
		else if(prvo_rjesenje<x1) {
			if(fabs(x1-prvo_rjesenje)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");
		}
		else if(prvo_rjesenje>x1) {
			if(fabs(x1-prvo_rjesenje)<0.1) printf("Priblizno vece\n");
			else printf("Vece\n");
		}
	}
	
	for(;;) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &drugo_rjesenje);
		if(fabs(x2-drugo_rjesenje)<eps) {
			printf("Tacno\n");
			break;
		}
		
		else if(drugo_rjesenje<x2) {
			if(fabs(x2-drugo_rjesenje)<0.1) printf("Priblizno manje\n");
			else printf("Manje\n");
		}
		else if(drugo_rjesenje>x2) {
			if(fabs(x2-drugo_rjesenje)<0.1) printf("Priblizno vece\n");
			else printf("Vece\n");
		}
	}
	
	return 0;
}
