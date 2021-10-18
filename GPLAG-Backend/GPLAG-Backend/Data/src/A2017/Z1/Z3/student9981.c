#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define epsilon1 0.1

int main() {
	double a,b,c,x1,x2,D,x3,x4;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=(b*b)-(4*a*c);
	if (a<0)
	{
	    x3=(-b-sqrt(D)) / (2*a);
	    x4=(-b+sqrt(D)) / (2*a);
	
	}
	else 
	{
		x4=(-b-sqrt(D)) / (2*a);
	    x3=(-b+sqrt(D)) / (2*a);
	}
	if (D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
	}
	else
	{
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
		
	

			
		
		
	
	if(fabs(x1-x4)<epsilon)
	{
		printf("Tacno\n");
	
	}
	else if((x1<x4) && (fabs(x1-x4)>=epsilon1))
	{
		printf("Manje\n");
		
	}
	else if ((x1>x4) && (fabs(x1-x4)>=epsilon1))
	{
		printf("Vece\n");
	}
	else if((x1<x4) && (fabs(x1-x4)<epsilon1))
	{
		printf("Priblizno manje\n");
	}
	else if((x1>x4) && (fabs(x1-x4)<epsilon1))
	{
		printf("Priblizno vece\n");
	}
		}
	while(fabs(x1-x4)>=epsilon);
	do
	{
	printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			
		
	
	if(fabs(x2-x3)<epsilon)
	{
		printf("Tacno\n");
	
	}
	else if((x2<x3) && (fabs(x2-x3)>=epsilon1))
	{
		printf("Manje\n");
		
	}
	else if((x2>x3) && (fabs(x2-x3)>=epsilon1))
	{
		printf("Vece\n");
	}
	else if((x2>x3) && (fabs(x2-x3)<epsilon1))
	{
		printf("Priblizno vece\n");
	}	
	else if ((x2<x3) && (fabs(x2-x3)<epsilon1))
	{
		printf("Priblizno manje\n");
	}
	}
	while(fabs(x2-x3)>=epsilon);
	}
		
	
	
		return 0;
}
