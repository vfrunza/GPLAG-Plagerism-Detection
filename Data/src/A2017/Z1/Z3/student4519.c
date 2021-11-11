#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	double a, b, c, t, D;
	double x1, x2, broj, razlika;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D = b*b - 4*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	if(fabs(D-0)<eps) t=0; 
		else t = sqrt(D);
	x1 = ((-1)*b - t)/(2*a);
	x2 = ((-1)*b + t)/(2*a);
	
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &broj);
	
		razlika=broj-x1;
		if(fabs(x1-broj)<eps) break;
		else if(razlika<0 && razlika>-0.1 )
		printf("Priblizno manje\n");
		else if(razlika>0 && razlika<0.1)
		printf("Priblizno vece\n");
		else if(broj<x1) printf("Manje\n");
		else if(broj>x1) printf("Vece\n");
		}while(1);		
	printf("Tacno\n");
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &broj);
		if(fabs(x2-broj)<eps) break;
		else if(razlika<0 && razlika>-0.1 )
		printf("Priblizno manje\n");
		else if(razlika>0 && razlika<0.1)
		printf("Priblizno vece\n");
		else if(broj<x2) printf("Manje\n");
		else if(broj>x2) printf("Vece\n");
		}while(1);		
	printf("Tacno");
	return 0;
}
