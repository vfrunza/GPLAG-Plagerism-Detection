#include <stdio.h>
#include <math.h>
#define eps1 0.001
#define eps2 0.1
#include<stdlib.h>
int main() {
	float a, b, c;
	float x1,x2,x1_t,x2_t;
	float D;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a, &b, &c);
	
	D = b*b-4*a*c;
	
	if(D < 0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1_t = (-b + sqrt(D))/(2*a);
	x2_t = (-b - sqrt(D))/(2*a);
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%f", &x1);
		
		if(fabs(x1-x1_t) <= eps1) {
			printf("Tacno\n");
			break;
		}
		if(x1 > x1_t){
			if (fabs(x1 - x1_t) <= eps2) printf("Priblizno vece\n");
			else printf("Vece\n");
		}
		else if(x1 < x1_t && fabs(x1 - x1_t) >= eps2) printf("Manje\n");
		else if(x1 < x1_t && fabs(x1 - x1_t) <= eps2) printf("Priblizno manje\n");
	} while (fabs(x1 - x1_t) > eps1);
	
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%f", &x2);
		
		if(fabs(x2 - x2_t) <= eps1) {
			printf("Tacno\n");
			break;
		}
		else{
			
		if (x2 > x2_t){
		if (fabs(x2 - x2_t) < eps2){ 
		printf("Priblizno vece\n");
		}
		else { 
		printf("Vece\n");
		}
		}
		else if (x2 < x2_t && fabs(x2 - x2_t) >= eps2) printf("Manje\n");
		else if (x2 < x2_t && fabs(x2 - x2_t) <= eps2) printf("Priblizno manje\n");
		}
	} while(fabs(x2 - x2_t) > eps1);
			
	return 0;
}
