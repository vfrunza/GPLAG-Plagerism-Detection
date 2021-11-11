#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	double a, b, c, x1, x2, rj1, rj2, d; 
	printf("Unesite koeficijente a, b i c: "); 
	scanf("%lf", &a); 
	scanf("%lf", &b); 
	scanf("%lf", &c); 
	d = (b*b)-(4*a*c); 
	if(d<0) {
		printf("Rjesenja su imaginarni brojevi."); 
		return 0; 
	}
	else {
		x1 = (-b)+d/(2*a); 
		x2 = (-b)-d/(2*a);
		for(;;) {
			printf("Unesite rjesenje x1: "); 
			scanf("%lf", &rj1);
			
			if(rj1>x1) 
			printf("Vece\n");
			else if(rj1<x1)
			printf("Manje\n"); 
			else if(rj1 - x1 < 0.1) 
			printf("Priblizno manje"); 
			else if(rj1 - x1 > 0.1)
			printf("Priblizno vece"); 
			else if(rj1-x1 < epsilon) 
			printf("Tacno"); break;
		
			}
			else if(rj1 == x1) { printf("Tacno"); } 
		
		}
		for(;;) {
			printf("\nUnesite rjesenje x2: "); 
			scanf("%lf", &rj2); 
			
			if(rj2-x2>epsilon) 
			printf("Vece\n"); 
			else if(x2-rj2>epsilon) 
			printf("Manje\n");  
			else if(rj2 - x2 < 0.1) 
			printf("Priblizno manje"); 
			else if(rj2 - x2 > 0.1) 
			printf("Priblizno vece");
			else if(rj2-x2 < epsilon) 
			printf("Tacno"); break; 
			}
			
		}
	}
	
	return 0;
}
