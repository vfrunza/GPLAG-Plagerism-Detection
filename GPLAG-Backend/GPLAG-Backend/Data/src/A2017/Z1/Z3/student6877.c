#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	
	double a, b, c, x1=0, x2=0, x11=0, x22=0, D=0;
	
	
	printf("Unesite koeficijente a, b i c: ");
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	
	D=pow(b,2)- 4.0*a*c; /*Racunanje diskriminante*/
	x1=(-b+sqrt(pow(b,2)- 4.0*a*c))/(2.*a);
	x2=(-b-sqrt(pow(b,2)- 4.0*a*c))/(2.*a);
	
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	do
	{
		printf("Unesite rjesenje x1:");
		scanf("%lf", &x11);
		if((x11-x1>=EPSILON) && (x11-x1 < 0.1))
		{
		printf(" Priblizno vece\n");
		}
		else if(x11-x1<=-0.001 && x11-x1 > -0.1)
		{
		printf(" Priblizno manje\n");
		}
		 if(x11-x1>=0.1)
		printf(" Vece\n");
		 if(x11-x1<=-0.1)
		printf(" Manje\n");
		
			
	}while(fabs(x11-x1)>=EPSILON);
	if(fabs(x11-x1)<EPSILON)
	printf(" Tacno\n");
	
	
	do
	{
		printf("Unesite rjesenje x2:");
		scanf("%lf", &x22);
		if((x22-x2>=EPSILON) && (x22-x2 < 0.1))
		{
		printf(" Priblizno vece\n");
		}
		else if(x22-x2<=-0.001 && x22-x2 > -0.1)
		{
		printf(" Priblizno manje\n");
		}
		 if(x22-x2>=0.1)
		printf(" Vece\n");
		 if(x22-x2<=-0.1)
		printf(" Manje\n");
		
			
	}while(fabs(x22-x2)>=EPSILON);
	if(fabs(x22-x2)<EPSILON)
	printf(" Tacno\n");
	
	return 0;
}
