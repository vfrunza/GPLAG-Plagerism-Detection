#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	
	double a,b,c,D,x1,x2,x1f,x2f;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=pow(b,2)-4*a*c;
	x1f=(-b-sqrt(D))/(2*a);
	x2f=(-b+sqrt(D))/(2*a);
	
	if(x1f>x2f) {
		a=x1f;
		x1f=x2f;
		x2f=a;
	}
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	do {
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &x1);
	
	if(fabs(x1-x1f)<eps) {
		printf("Tacno\n");
		
	} else if(x1<x1f && fabs(x1-x1f)>=0.1) {
		printf("Manje\n");
		
	} else if(x1>x1f && fabs(x1-x1f)>=0.1) {
		printf("Vece\n");
	} else if(fabs(x1-x1f)<=0.1 && x1<x1f) {
		printf("Priblizno manje\n");
	} else if(fabs(x1-x1f)<=0.1 && x1>x1f) {
		printf("Priblizno vece\n");
	} 
	} while(fabs(x1-x1f)>=eps);
	

	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
	
     	if(fabs(x2-x2f)<eps) {
	    	printf("Tacno\n");
     	} else if(x2<x2f && fabs(x2-x2f)>=0.1) {
     		printf("Manje\n");
     	} else if(x2>x2f && fabs(x2-x2f)>=0.1) {
     		printf("Vece\n");
     	} else if(fabs(x1-x1f)<=0.1 && x2<x2f) {
     		printf("Priblizno manje\n");
     	} else if(fabs(x2-x2f)<=0.1 && x2>x2f) {
     		printf("Priblizno vece\n");
     	}
	} while(fabs(x2-x2f)>=eps);
	
	return 0;
}
