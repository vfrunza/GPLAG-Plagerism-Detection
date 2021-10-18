#include <stdio.h>
#include <math.h>
#define e 0.001
int main() 
{
	int a,b,c;
	double D,x1,x2,r1,r2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=pow(b,2)-(4*a*c);
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if (D<0)
	{
	printf("Rjesenja su imaginarni brojevi.");
	}
	else
	{
	    do
	    {
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&r1);
		    if (fabs(x1-r1)<=e) 
		    {
		   	printf("Tacno\n");
		   	}
			else
			{   
				if(r1<x1)
				{
					if(fabs(x1-r1+e)<0.1)
					printf("Priblizno manje\n");
					else
					printf("Manje\n");
				}
				else
				{
					if(fabs(x1-r1+e)<0.1)
					printf("Priblizno vece\n");
					else
					printf("Vece\n");
				
				}
			}
		
		} while(fabs(x1-r1)>e);
		
		
		do
	    {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&r2);
		    if (fabs(x2-r2)<=e) 
		    {
		   	printf("Tacno\n");
		   	}
			else
			{   
				if(r2<x2)
				{
					if(fabs(x2-r2+e)<0.1)
					printf("Priblizno manje\n");
					else
					printf("Manje\n");
				}
				else
				{
					if(fabs(x2-r2+e)<0.1)
					printf("Priblizno vece\n");
					else
					printf("Vece\n");
				
				}
			}
		
		} while(fabs(x2-r2)>e);
		
		
		
		
		
		
		
		
	}

	return 0;
}
