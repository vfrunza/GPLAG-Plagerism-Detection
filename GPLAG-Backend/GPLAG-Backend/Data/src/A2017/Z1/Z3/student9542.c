#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	
	double a, b, c, x1, x2, D, x11, x22;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (a==0) {return 0;}
	
	D=(b*b)-(4*a*c);
	x1=(-b+(sqrt(D)))/(2*a);
	x2=(-b-(sqrt(D)))/(2*a);
	
	if (D<0) {printf("Rjesenja su imaginarni brojevi."); return 0;}
	
	greska:
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &x11);
	
	if(fabs(x11-x1)<EPSILON){
		printf("Tacno\n");
	} else if (fabs(x11-x1)<0.1 && x11<x1) {printf("Priblizno manje\n"); goto greska;}
	  else if (fabs(x11-x1)<0.1 && x11>x1) {printf("Priblizno vece\n"); goto greska;}
	  else if(x11>x1) {printf("Vece\n"); goto greska;} 
	  else if(x11<x1) {printf("Manje\n"); goto greska;}
	
	greska1:  
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &x22);
	
    if(fabs(x22-x2)<EPSILON){
			printf("Tacno\n"); return 0;
		} else if (fabs(x22-x2)<0.1 && x22<x2) {printf("Priblizno manje\n"); goto greska1;}
		  else if (fabs(x22-x2)<0.1 && x22>x2) {printf("Priblizno vece\n"); goto greska1;}
		  else if (x22>x2) {printf("Vece\n"); goto greska1;}
		  else if (x22<x2) {printf("Manje\n"); goto greska1;}
		  
		  
	return 0;
}
