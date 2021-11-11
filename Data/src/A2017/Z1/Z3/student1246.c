#include <stdio.h>
#include <math.h>

#define eps 0.001

int main() {
	
	double a, b, c, x1, x2, ux1, ux2;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	//Diskriminanta
	double D = pow(b, 2) - 4 * a * c;
	
	//Ima li rjesenja u skupu realnih br
	if(D < 0) {
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	
	//rjesenja x1 i x2
	x1 = (-b - sqrt(D)) / (2 * a);
	x2 = (-b + sqrt(D)) / (2 * a);
	
	//x1 je manje od x2, postavi tako
	if(x1 > x2){
		double t = x1;
		x1 = x2;
		x2 = t;
	}
	
	//Unos korisnickog x1
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &ux1);
		
		if(fabs(ux1 - x1) < eps){
			printf("Tacno\n");
			break;
		}
		
		if(ux1 > x1){
			if(fabs(ux1 - x1) < 0.1)
				printf("Priblizno vece\n");
			else
				printf("Vece\n");
		}
		else if(ux1 < x1){
			if(fabs(ux1 - x1) < 0.1)
				printf("Priblizno manje\n");
			else
				printf("Manje\n");
		}
		
	}while(1);
	
	//Unos korisnickog x2
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &ux2);
		
		if(fabs(ux2 - x2) < eps){
			printf("Tacno\n");
			break;
		}
		
		if(ux2 > x2){
			if(fabs(ux2 - x2) < 0.1)
				printf("Priblizno vece\n");
			else
				printf("Vece\n");
		}
		else if(ux2 < x2){
			if(fabs(ux2 - x2) < 0.1)
				printf("Priblizno manje\n");
			else
				printf("Manje\n");
		}
		
	}while(1);
	
	return 0;
}
