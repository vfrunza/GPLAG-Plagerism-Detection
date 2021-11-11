#include <stdio.h>
#include <math.h>
#define P 0.001 
#define S 0.1

int main() 
{
	double a, b, c, x1, x2, d, e, f;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if(b*b-4*a*c<0)
	{
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
	}
    if(fabs(a)<=0)
    {
	printf("Jednacine nije kvadratna.");
	return 0;
    }
	x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	
	if(x1>x2)
	{
		f=x1;
		x1=x2;
		x2=f;
	}

	do
	{
		
		printf("Unesite rjesenje x1: ");
		
		scanf("%lf", &d);
		
		if(fabs(d-x1)<P)
		
		goto drugo_Rjesenje;
		
	    if((d-x1>-1*S)&&(d-x1<0))
		printf("Priblizno manje\n");
		
		else if(d<x1)
		printf("Manje\n");
		
		if((d-x1<S)&&(d-x1>0))
		printf("Priblizno vece\n");
		
		else if(d>x1)
		printf("Vece\n");
	
	}while(fabs(d-x1)>=P);
	
	drugo_Rjesenje:
	printf("Tacno\n");
	
	do
	{
		
		printf("Unesite rjesenje x2: ");
		
		scanf("%lf", &e);
		
		if(fabs(e-x2)<P)
		
		goto Kraj;
		
		if((e-x2>-1*S)&&(e-x2<0))
		printf("Priblizno manje\n");
		
		else if(e<x2)
		printf("Manje\n");
		
		if((e-x2<S)&&(e-x2>0))
		printf("Priblizno vece\n");
		
		else if(e>x2)
		printf("Vece\n");
	
	}while(fabs(e-x2)>=P);
	
	Kraj:
	printf("Tacno\n");
	
	return 0;
	
}
