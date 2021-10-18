#include <stdio.h>
#include <math.h>
#define EPSILON 0.001


int main() {

	double a = 0;
	double b = 0;
	double c = 0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	double D = b*b-4*a*c;
	
	if (D<0)
		{
			printf("Rjesenja su imaginarni brojevi.");
			return 0;
		}
		
	
	double x1 = (-b-sqrt(D))/(2*a);
	double x2 = (-b+sqrt(D))/(2*a);
		
	if (x1>x2)
	{
		double pomocna = x1;
		x1 = x2;
		x2 = pomocna;
	}
	
	int n = 1;
	double unos_x1;
	
	while(n == 1)
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &unos_x1);
			
			if (fabs(x1-unos_x1)<EPSILON)
				{
					printf("Tacno\n");
					break;
				}
				
			if (fabs(x1-unos_x1)<0.1 && x1<unos_x1)
				printf("Priblizno vece\n");
				
			else if (fabs(x1-unos_x1)<0.1 && x1>unos_x1)
				printf("Priblizno manje\n");
				
			else if (x1<unos_x1)
				printf("Vece\n");
				
			else if (x1>unos_x1)
				printf("Manje\n");
			
		}
		
		double unos_x2;
		while(n == 1)
		{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &unos_x2);
			
			if (fabs(x2-unos_x2)<EPSILON)
				{
					printf("Tacno\n");
					break;
				}
				
			if (fabs(x2-unos_x2)<0.1 && x2<unos_x2)
				printf("Priblizno vece\n");
				
			else if (fabs(x2-unos_x2)<0.1 && x2>unos_x2)
				printf("Priblizno manje\n");
				
			else if (x2<unos_x2)
				printf("Vece\n");
				
			else if (x2>unos_x2)
				printf("Manje\n");
			
		}





	return 0;
}
