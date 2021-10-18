#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a, b, c, D, x1, x2, ux1=100000, ux2=100000;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=pow(b,2)-4*a*c;
	x1=((-b)-sqrt(D))/(2*a);
	x2=((-b)+sqrt(D))/(2*a);
	
	if(D<=EPSILON) {
		x1=(-b)/(2*a);
		x2=(-b)/(2*a);
	}
	
	if(a<0) {
		x2=((-b)-sqrt(D))/(2*a);
		x1=((-b)+sqrt(D))/(2*a);		
	}
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} else {
		while(fabs(ux1-x1)>=EPSILON) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &ux1);
		
			if(ux1-x1>0 && ux1-x1<0.1 && fabs(ux1-x1)>=EPSILON) {
				printf("Priblizno vece");
				printf("\n");
			} else if(ux1-x1>0 && fabs(ux1-x1)>=EPSILON) {
				printf("Vece");
				printf("\n");
			} else if(ux1-x1<0 && ux1-x1>-0.1 && fabs(ux1-x1)>=EPSILON) {
				printf("Priblizno manje");
				printf("\n");
			} else if(ux1-x1<0 && fabs(ux1-x1)>=EPSILON) {
				printf("Manje");
				printf("\n");
			} 
		}
		printf("Tacno");
		printf("\n");
		
		while(fabs(ux2-x2)>=EPSILON) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &ux2);
		
			if(ux2-x2>0 && ux2-x2<0.1 && ux2-x2>=EPSILON) {
				printf("Priblizno vece");
				printf("\n");
			} else if(ux2-x2>0 && ux2-x2>=EPSILON) {
				printf("Vece");
				printf("\n");
			} else if(ux2-x2<0 && ux2-x2>-0.1 && fabs(ux2-x2)>=EPSILON) {
				printf("Priblizno manje");
				printf("\n");
			} else if(ux2-x2<0 && fabs(ux2-x2)>=EPSILON) {
				printf("Manje");
				printf("\n");
			}
		}
		printf("Tacno");
		}
	return 0;
}
