#include <stdio.h>
#include <math.h>
#define EPS 0.001


int main() {
	double a, b, c, x1, x2, D, korijen, kx1, kx2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	 /*diskriminanta*/
	D = b*b - 4*a*c;
	
	if (D < 0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	if (fabs(D) <= EPS){
		x1=(-b)/(2*a);
		x2=x1;
	}
	
	if( D>0 ) 		{
		x1=(((-b)+sqrt(b*b - 4*a*c))/(2*a));
		x2=(((-b)-sqrt(b*b - 4*a*c))/(2*a));
	}
	


	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &kx1);
		
		if (fabs(x1-kx1)<EPS) {
			printf("Tacno\n");
		}
		
		else if(kx1>x1 && fabs(x1-kx1)<0.1 && fabs(x1-kx1)>=EPS) {
			
			printf("Priblizno vece\n");
		}
		else if(kx1>x1){
			printf("Vece\n");
		}
	
		else if (kx1<x1 && fabs(x1-kx1)<0.1 && fabs(x1-kx1)>=EPS) {
			printf("Priblizno manje\n");
		}
		else if(kx1<x1){
			printf("Manje\n");
		}
		
		else if (fabs(x1-kx1)<=EPS) {
			printf("Tacno\n");
		}
	}
	while (fabs(x1-kx1)>=EPS);
	
	/*provjera drugog rjesenja*/
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &kx2);
		
		if (fabs(x2-kx2)<EPS) {
			printf("Tacno\n");
		}
		
		else if (kx2>x2 && fabs(x2-kx2)<0.1 && fabs(x2-kx2)>=EPS) {
			
			printf("Priblizno vece\n");
		}
		else if(kx2>x2){
			printf("Vece\n");
		}
	
		else if (kx2<x2 && fabs(x2-kx2)<0.1 && fabs(x2-kx2)>=EPS) {
			printf("Priblizno manje\n");
		}
		else if(kx2<x2){
			printf("Manje\n");
		}
		
	}
	while (fabs(x2-kx2)>=EPS);
	return 0;
}

	
