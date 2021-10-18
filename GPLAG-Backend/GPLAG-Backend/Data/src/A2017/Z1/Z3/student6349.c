#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	double x1,x2,a,b,c,D,r1,r2,t,x1u,x2u;
	
	printf("Unesite koeficijente a,b i c");
		scanf("%lf %lf %lf",&a,&b,&c);
		
	D=b*b-4*a*c;
	
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi:");
	}
	
	else {
	 	t=sqrt(D);
	 	x1=((-b+t)/(2*a));
	 	x2=((-b-t)/(2*a));
	 	if(x1<=x2) {x1=x2;}
	
	do {
		printf ("Unesite rjesenje x1:");
			scanf("%lf",&x1u);
		if (((x1-x1u)<EPSILON && ((x1-x1u)>=-EPSILON))) {
			printf ("Tacno\n");}
		else if (fabs(x1-x1u)<EPSILON && (x1-x1u)>=0){
			printf ("Priblizno manje\n");
		}
		else if {x1u<x1){
			printf("Manje/n");
		}
		else if(x1u>x1
	}
	
	return 0;
}
