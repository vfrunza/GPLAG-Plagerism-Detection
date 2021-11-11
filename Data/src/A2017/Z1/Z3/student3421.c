#include <stdio.h>
#define e 0.001
#include <math.h>
int main() {
	double a,b,c,D,t,x1,x2,broj1,broj2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=(b*b)-(4.0*a*c);
	
	if(D<0) {
		t=sqrt(-D);
		printf("Rjesenja su imaginarni brojevi."); 
		return 0;
	}
	  
	do {
		if (D>0) {
		t=sqrt(D);
		x1=-b-t/(2*a);
		x2=-b+t/(2*a); 
		
	}
	else if(D==0.0f) {
	  x1=-b/(2*a);
	  x2=x1; }
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &broj1);
		
		if(fabs(broj1-x1)<(e)) {
			printf("Tacno\n");
		}
		
		 else if((broj1<x1) && (fabs(broj1-x1))>=0.1) {
			printf("Manje\n");
			
		} else if(broj1>x1 && (fabs(broj1-x1))>=0.1) {
			printf("Vece\n");
		} else if( broj1<x1 && (broj1-x1)<0.1) {
			printf("Priblizno manje\n");
		} else if (broj1>x1 && (broj1-x1)<0.1) {
			printf("Priblizno vece\n");
		} 
		
	
	} while (fabs(broj1-x1)>=(e));
	
	do { 
		printf("\nUnesite rjesenje x2: ");
		scanf("%lf",&broj2);
		if((fabs(broj2-x2))<(e)) {
			printf("Tacno\n");
		}
		else if(broj2<x2 && (fabs(broj2-x2))>=0.1) {
			printf("Manje");
		} else if(broj2>x2 && (fabs(broj2-x2))>=0.1 ) {
			printf("Vece\n");
		} else if( broj2<x2 && (broj2-x2)<0.1) {
			printf("Priblizno manje\n");
		}else if(broj2>x2 && (broj2-x2)<0.1) {
			printf("Priblizno vece\n");
		} 
		
	} while(fabs(broj2-x2)>=(e));

	return 0;
}