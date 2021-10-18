#include <stdio.h>
#include <math.h>
#define ep 0.001
#define ep1 0.1

int main() {
	
	double a,b,c,x1,x2,x3,x4,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=(b*b)-(4*a*c);
	if (a<0)
	{
		x3=(-b-sqrt(D)) / (2*a);
		x4=(-b+sqrt(D)) / (2*a);
	}
	else
	{
		x3=(-b+sqrt(D)) / (2*a);
		x4=(-b-sqrt(D)) / (2*a);
		
	}
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
	}
	else
	{
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			
			if(fabs(x1-x4)<ep)
			{
				printf("Tacno\n");
			}
			else if((x1<x4) && (fabs(x1-x4)>=ep1))
			{
				printf("Manje\n");
			}
			else if((x1>x4) && (fabs(x1-x4)>=ep1))
			{
				printf("Vece\n");
			}
			else if((x1<x4) && (fabs(x1-x4)<ep1))
			{
				printf("Priblizno manje\n");
			}
			else if((x1>x4) && (fabs(x1-x4)<ep1))
			{
				printf("Priblizno vece\n");
			}
	
			
	}
	while(fabs(x1-x4)>=ep);
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2);
		
		if(fabs(x2-x3)<ep)
		{
			printf("Tacno\n");
		}
		else if((x2<x3) && (fabs(x2-x3)>=ep1))
		{
			printf("Manje\n");
		}
		else if((x2>x3) && (fabs(x2-x3)>ep1))
		{
			printf("Vece\n");
		}
		else if((x2>x3) && (fabs(x2-x3)<ep1))
		{
			printf("Priblizno vece\n");
		}
		else if((x2<x3) && (fabs(x2-x3)<ep1))
		{
			printf("Priblizno manje\n");
		}
	}
	while(fabs(x2-x3)>=ep);
	}

	
	
	return 0;
}
