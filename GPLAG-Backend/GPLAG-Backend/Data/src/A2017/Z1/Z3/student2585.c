#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	
	double a,b,c,D;
	double x1,x2;
	
	printf ("Unesi a,b,c: ");
	scanf ("%lf%lf%lf",&a,&b,&c);
	D=b*b-4*a*c;
	
	if (D<0) printf("Rjesenja su imaginarni brojevi.");
	
	if (D>=0) {
		
		x1=(-b-sqrt(D) )/(double)2*a;
		x2=(-b+sqrt(D) )/(double)2*a;
		
	double x1_uneseno;
	printf ("Unesi prvo rjesenje: ");
	scanf ("%lf",&x1_uneseno);
	

	
	if ( (fabs(x1_uneseno-x1)<EPSILON) || (fabs(x1-x1_uneseno)<EPSILON) ) printf ("Tacno.");


	
	else if (x1_uneseno<x1 &&  fabs(x1_uneseno-x1)>0.1) printf("Manje");
		
	else if (x1_uneseno>x1 && fabs(x1_uneseno-x1)<0.1) printf("Vece");

	else if ((x1_uneseno-x1)<0.1) printf ("Priblizno vece ");


	}
    
	return 0;
	
}
