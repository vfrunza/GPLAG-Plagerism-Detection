#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	printf("Unesite koeficijente a, b i c: ");
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double D = 0;
	D = pow(b,2) - 4.0 * a * c;
	
	if (D<0)
		{
			printf("Rjesenja su imaginarni brojevi.");
			return 0;
		}
	
//------------------------------------------------------------------------------

	double x1 = 0,x2 = 0;
	x1 = (-b + sqrt(pow(b,2) - 4.0 * a * c))/(2.*a);
	x2 = (-b - sqrt(pow(b,2) - 4.0 * a * c))/(2.*a);
	
	
	double ux1=0, ux2 = 0;


		
		do
		{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&ux1);
		if ((ux1 - x1 >= EPSILON) && (ux1 - x1 < 0.1))
		{
			printf("Priblizno vece\n");
		}
		else if ((ux1 - x1 <= -0.001) && (ux1 - x1 > -0.1))
		{
			printf("Priblizno manje\n");
		}
			if (ux1 - x1 <= -0.1)
			printf("Manje\n");
			if (ux1 - x1 >= 0.1)
			printf("Vece\n");
			
		} while((fabs(ux1- x1) >= EPSILON));
		if (fabs(ux1- x1) < EPSILON)
		printf("Tacno\n");
		
		do
		{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&ux2);
		if ((ux2 - x2 >= EPSILON) && (ux2 - x2 < 0.1))
		{
			printf("Priblizno vece\n");
		}
		else if ((ux2 - x2 <= -0.001) && (ux2 - x2 > -0.1))
		{
			printf("Priblizno manje\n");
		}
			if (ux2 - x2 <= -0.1)
			printf("Manje\n");
			if (ux2 - x2 >= 0.1)
			printf("Vece\n");
			
		} while((fabs(ux2- x2) >= EPSILON));
		if (fabs(ux2- x2) < EPSILON)
		printf("Tacno\n");
	
	return 0;
}
