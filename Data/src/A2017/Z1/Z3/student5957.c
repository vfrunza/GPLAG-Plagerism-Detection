#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
	double a=0,b=0,c=0,D=0,x1=0,x2=0,x1_unos=0,x2_unos=0,t=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
		D=b*b-4.0*a*c;
		if(D<0) {
			x1=0;
			x2=0;
			printf("Rjesenja su imaginarni brojevi.");
			return 0;
		} else if(D>0) {
			t=sqrt(D);
			x1=(-b+t)/(2*a);
	
			x2=(-b-t)/(2*a);
			
		} else if(D==0) {
			x1=(-b)/(2*a);
			x2=x1;
		}
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1_unos);
			if (x1_unos<x1 && (x1_unos+(0.1))<=x1) {
				printf("Manje\n");
			} else if (x1_unos>x1 && (x1_unos-(0.1))>=x1) {
				
				printf("Vece\n");
				
		} else if(x1_unos<x1 && (x1_unos-x1)<(0.1) && fabs(x1_unos-x1)>=epsilon) {
				printf("Priblizno manje\n");
			} else if( x1_unos>x1 && (x1_unos-x1)<(0.1) && fabs(x1_unos-x1)>=epsilon) {
				printf("Priblizno vece\n");
			}
			else if (fabs(x1_unos-x1)<epsilon)
				printf("Tacno\n");
		
			
		} while (x1_unos!=x1 && ((x1_unos+epsilon)<=x1 || (x1_unos-epsilon)>=x1));
		
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x2_unos);
			
			if (x2_unos<x2 && (x2_unos+(0.1)<=x2)) {
				printf("Manje\n"); 
				
			} else if (x2_unos>x2 && (x2_unos-(0.1))>=x2) {
				printf("Vece\n"); 
				
			} else if(x2_unos<x2 && (x2_unos-x2)<(0.1) && fabs(x2_unos-x2)>=epsilon) {
				printf("Priblizno manje\n");
			} else if(x2_unos>x2 && (x2_unos-x2)<(0.1) && fabs(x2_unos-x2)>=epsilon) {
				printf("Priblizno vece\n");
			}
			else if ((fabs(x2_unos-x2)<epsilon)) {
				printf("Tacno\n");
			
			
			}
	
			
		} while (x2_unos!=x2 && ((x2_unos+epsilon)<=x2 || (x2_unos-epsilon)>=x2 ));
			
	
		return 0;
}