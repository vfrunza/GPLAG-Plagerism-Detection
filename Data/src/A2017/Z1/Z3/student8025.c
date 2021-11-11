#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a=0, b, c, x1, x2, r1, r2, D, z;
	
	while (a==0){
		printf ("Unesite koeficijente a, b i c: ");
		scanf ("%lf %lf %lf", &a, &b, &c);
	}
	
	D=b*b-4*a*c;
	
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	
	if (x2 < x1){
		z=x2;
		x2=x1;
		x1=z;
	}
	
	do{
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &r1);
		
		if (fabs(x1-r1)<e) {
			printf ("Tacno \n");
		
		
	do {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &r2);
		
		if (fabs(x2-r2)<e){
			printf ("Tacno \n");
			return 0;
		}
		
		else if ((r2-x2)>=e && (r2-x2)<0.1){
		printf ("Priblizno vece \n");	
		}
		
		else if((r2-x2)<=-e && (r2-x2)>-0.1){
			printf("Priblizno manje \n");
		}
		
		else if (r2<x2){
			printf("Manje \n");
		}
		
		else{
			printf ("Vece \n");
		}
	}
	
	while (fabs(x2-r2)>=e);
	
		}
	
	else if ((r1-x1)>=e && (r1-x1)<0.1){
		printf ("Priblizno vece \n");
	}
	
	else if ((r1-x1)<=-e && (r1-x1)>-0.1){
		printf ("Priblizno manje \n");
	}
	
	else if (r1<x1){
		printf ("Manje \n");
	}
	
	else {
		printf ("Vece \n");
	}
	}
	
	while (fabs(x1-r1)>=e);
	
	
	return 0;
}
