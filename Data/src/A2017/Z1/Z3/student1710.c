#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	
	 
	double x1, x2, DP, x11, x22, a, b, c;
	
	//Unos varijabli
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	//Definiciono podrucje
	DP=pow(b,2)-4*a*c;
	
	//Rjesenja jednacine
	x1=(((-b)-sqrt(pow(b,2)-4*a*c))/(2*a));
	x2=(((-b)+sqrt(pow(b,2)-4*a*c))/(2*a));
	
	//Za imaginarne brojeve
	if (DP<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	if (fabs(DP)<=EPSILON){
		x1=(-b)/(2*a);
		x2=x1;
	}
	
	if(a<0){
	x1=(((-b)+sqrt(pow(b,2)-4*a*c))/(2*a));
	x2=(((-b)-sqrt(pow(b,2)-4*a*c))/(2*a));
	}
	
	
	
	//Provjera prvog rjesenja
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x11);
		
		if (fabs(x1-x11)<EPSILON) {
			printf("Tacno\n");
		}
		
		else if(x11>x1 && fabs(x1-x11)<0.1 && fabs(x1-x11)>=EPSILON) {
			
			printf("Priblizno vece\n");
		}
		else if(x11>x1){
			printf("Vece\n");
		}
	
		else if (x11<x1 && fabs(x1-x11)<0.1 && fabs(x1-x11)>=EPSILON) {
			printf("Priblizno manje\n");
		}
		else if(x11<x1){
			printf("Manje\n");
		}
		
		else if (fabs(x1-x11)<=EPSILON) {
			printf("Tacno\n");
		}
	}
	while (fabs(x1-x11)>=EPSILON);
	
	//Provjera drugog rjesenja
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x22);
		
		if (fabs(x2-x22)<EPSILON) {
			printf("Tacno\n");
		}
		
		else if (x22>x2 && fabs(x2-x22)<0.1 && fabs(x2-x22)>=EPSILON) {
			
			printf("Priblizno vece\n");
		}
		else if(x22>x2){
			printf("Vece\n");
		}
	
		else if (x22<x2 && fabs(x2-x22)<0.1 && fabs(x2-x22)>=EPSILON) {
			printf("Priblizno manje\n");
		}
		else if(x22<x2){
			printf("Manje\n");
		}
		
	}
	while (fabs(x2-x22)>=EPSILON);
	return 0;
}
