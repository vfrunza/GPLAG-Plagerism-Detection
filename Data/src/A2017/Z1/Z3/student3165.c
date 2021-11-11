#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a,b,c,D,x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	    goto end;
		
	}
	else{
		x1=(-b+sqrt(D))/(2*a);
		x2=(-b-sqrt(D))/(2*a);
	
	
	return 0; 
	}
		