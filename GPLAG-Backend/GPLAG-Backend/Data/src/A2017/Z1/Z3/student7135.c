#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	int C;
	double a, b, c, x1, x2, D, tx1, tx2;
	printf("Unesite koeficijente a, b i c: "); 
	scanf("%lf%lf%lf", &a, &b, &c);
	D=b*b-4*a*c;
	x1=(-b+sqrt(b*b-4*a*c))/((2*a));
	x2=(-b-sqrt(b*b-4*a*c))/((2*a));
	if (D<0) {
	printf("Rjesenja su imaginarni brojevi.");
	} else {
	do {
	C=0;
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &tx1);
	if(fabs(tx1-x1)<epsilon) {
	printf("Tacno\n");
	C=1;
	} else if(tx1<x1) {
	if(x1-tx1<0.1) {
	printf("Priblizno manje\n");
    } else {
	printf("Manje\n");
	} 
	}
	else if(tx1>x1) {
	if(-x1+tx1<0.1) {
	printf("Priblizno vece\n");
	} else {
	printf("Vece\n");
	}
	} 
	} while (C==0);
	do {
	C=0;
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &tx2);
	if(fabs(tx2-x2)<epsilon) {
	printf("Tacno\n");
	C=1;
	} else if(tx2<x2) {
	if(x2-tx2<0.1) {
	printf("Priblizno manje\n");
    } else { 
	printf("Manje\n");
	} 
	}
	else if(tx2>x2) {
	if(-x2+tx2<0.1) {
	printf("Priblizno vece\n");
	} else {
	printf("Vece\n");
	}
	} 
	} while (C==0);
	}
	return 0;
}
