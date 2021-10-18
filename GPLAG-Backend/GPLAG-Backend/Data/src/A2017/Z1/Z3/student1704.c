#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a=0, b, c, D, x1, x2, X1, X2,k;
	while (a==0) {
		printf("Unesite koeficijente a, b i c: ");
		scanf("%lf %lf %lf", &a, &b, &c);
	}
	D=b*b-4*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}

	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if(x2<x1) {
		k=x2;
		x2=x1;
		x1=k;
	}
	
	
	do {
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &X1);
	
	if(fabs(x1-X1)<e) {
		printf("Tacno\n");
		
		do {
			printf("\nUnesite rjesenje x2: ");
			scanf("%lf", &X2);
			
			if(fabs(x2-X2)<e) {
		printf("Tacno");
		return 1;}
		
		else if((X2-x2)>=e && (X2-x2)<0.1) {
		printf("Priblizno vece");
	}
	else if((X2-x2)<=-e && (X2-x2)>-0.1) {
		printf("Priblizno manje");
	}
	else if(X2<x2) {
		printf("Manje");}
		else {
			printf("Vece");
		}
		
			
		}
		while (fabs(x2-X2)>=e);
		
		
	}
	
	else if((X1-x1)>=e && (X1-x1)<0.1) {
		printf("Priblizno vece\n");
	}
	
	else if((X1-x1)<=-e && (X1-x1)>-0.1) {
		printf("Priblizno manje\n");
	}
	
	else if(X1<x1) {
		printf("Manje\n");}
		
		else {
			printf("Vece\n");
		}
	}
	
	while (fabs(x1-X1)>=e);
	
	
	
	
	return 0;
}
