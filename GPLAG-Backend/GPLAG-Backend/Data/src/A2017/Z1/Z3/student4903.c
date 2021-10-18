#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double D,x1,x2,a,b,c,k=32000,m=32000;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;
	if(D<0){ 
		printf("Rjesenja su imaginarni brojevi.");
		goto izlaz;
	}
	else {
			x1=(-b+sqrt(D))/(2*a);
			x2=(-b-sqrt(D))/(2*a);
	}
	while(fabs(k-x1)>=EPSILON){
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &k);
		
		if(fabs(k-x1)<EPSILON)break;
	    if(fabs(k-x1)<0.1 && k<x1) printf("Priblizno manje\n");
		else if(fabs(k-x1)<0.1 && k>x1) printf("Priblizno vece\n");
		else if(k-x1<EPSILON)printf("Manje\n");
		else if(k-x1>EPSILON) printf("Vece\n");
	
	 
	} printf("Tacno\n");
	
	
	while(fabs(m-x2)>=EPSILON){
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &m);
		
		if(fabs(m-x2)<EPSILON) break;
	    if(fabs(m-x2)<0.1 && m<x2) printf("Priblizno manje\n");
		else if(fabs(m-x2)<0.1 && m>x2) printf("Priblizno vece\n");
		else if(m-x2<EPSILON)printf("Manje\n");
		else if(m-x2>EPSILON) printf("Vece\n");
		
	
	} printf("Tacno\n");
	

	
	izlaz:return 0;
}
