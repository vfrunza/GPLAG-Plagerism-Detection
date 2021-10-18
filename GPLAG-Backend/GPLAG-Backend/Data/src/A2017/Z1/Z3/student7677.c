#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define konstanca 0.1

int main() {
	
	double a,b,c,x1,x2,D,rjesenje2,rjesenje1;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	
	D=b*b-4*a*c;
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	if(x2 < x1)
	{
		double t = x2;
		x2 = x1;
		x1 = t;
	}
	
	while(1){
	
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &rjesenje1);
	
	if(fabs(x1-rjesenje1)<EPSILON) {
		printf("Tacno\n");
		break;
	} 
	
    else if(fabs(rjesenje1-x1) < konstanca && rjesenje1 < x1)
	    printf("Priblizno manje\n");
	 
	else if(fabs(rjesenje1-x1) < konstanca && rjesenje1 > x1)
	    printf("Priblizno vece\n");
	    
	else if(rjesenje1<x1)
	    printf("Manje\n");
	
	else if(rjesenje1>x1)
	    printf("Vece\n");
    }
	
	
	
	while(1){
	
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &rjesenje2);
	
	if(fabs(x2-rjesenje2)<EPSILON) {
		printf("Tacno\n");
		break;
	} 
	
	else if(fabs(rjesenje2-x2) < konstanca && rjesenje2 < x2)
	    printf("Priblizno manje\n");
	 
	else if(fabs(rjesenje2-x2) < konstanca && rjesenje2 > x2)
	    printf("Priblizno vece\n");
	    
	else if(rjesenje2<x2)
	    printf("Manje\n");
	
	else if(rjesenje2>x2)
	    printf("Vece\n");
    }
    
	return 0;
}
