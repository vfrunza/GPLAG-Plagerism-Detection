#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.001

int main() {
	double a, b, c, D, x1, x2, prvo_rjesenje, drugo_rjesenje;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=(b*b)-(4*a*c);
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &prvo_rjesenje);
		if(fabs(prvo_rjesenje-x1)<eps){
		      printf("Tacno\n");
		      break;
		}
		if((prvo_rjesenje-x1)>=eps && (prvo_rjesenje-x1)<0.1 && prvo_rjesenje>x1){
			/*printf("Razlika je: %g\n", fabs(prvo_rjesenje-x1));*/
			printf("Priblizno vece\n");
		}
		else if((prvo_rjesenje-x1)<=eps && (prvo_rjesenje-x1)>-0.1) printf("Priblizno manje\n");
		else if(prvo_rjesenje>x1) printf("Vece\n");
		else if(prvo_rjesenje<x1) printf("Manje\n");
	}while(fabs(prvo_rjesenje-x1)>=eps);
	
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &drugo_rjesenje);
		if(fabs(drugo_rjesenje-x2)<eps){
		      printf("Tacno\n");
		      break;
		}
		if((drugo_rjesenje-x2)>=eps && (drugo_rjesenje-x2)<0.1 && drugo_rjesenje>x2) printf("Priblizno vece\n");
		else if((drugo_rjesenje-x2)<=eps && (drugo_rjesenje-x2)>-0.1) printf("Priblizno manje\n");
		else if(drugo_rjesenje>x2) printf("Vece\n");
		else if(drugo_rjesenje<x2) printf("Manje\n");
	}while(fabs(x2-drugo_rjesenje)>=eps);
	
	return 0;
}
	
