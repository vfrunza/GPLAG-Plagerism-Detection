#include <stdio.h>
#include <math.h>
#define e 0.001

int main() 
{
   double a,b,c,x1,x2,xk1,xk2,D;
   
   printf("Unesite koeficijente a, b i c: ");
   scanf("%lf %lf %lf", &a,&b,&c);
   
	D=(b*b-4*a*c);
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else
	{
	x1 = (-b + sqrt(b*b-4*a*c)) / (2*a);
	x2 = (-b - sqrt(b*b-4*a*c)) / (2*a);
	
	if(x1>x2)
	{
		x1 = (-b - sqrt(b*b-4*a*c)) / (2*a);
		x2 = (-b + sqrt(b*b-4*a*c)) / (2*a);
	}
	
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&xk1);
		if(fabs(xk1-x1)<e) printf("Tacno\n");
		else if(fabs(xk1-x1)<0.1 && xk1>x1) printf("Priblizno vece\n");
		else if(fabs(xk1-x1)<0.1 && xk1<x1) printf("Priblizno manje\n");
		else if(xk1>x1) printf("Vece\n");
		else printf("Manje\n");
	}while(fabs(xk1-x1)>=e);
	
	
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&xk2);
		if(fabs(xk2-x2)<e) printf("Tacno\n");
		else if(fabs(xk2-x2)<0.1 && xk2>x2) printf("Priblizno vece\n");
		else if(fabs(xk2-x2)<0.1 && xk2<x2) printf("Priblizno manje\n");
		else if(xk2>x2) printf("Vece\n");
		else printf("Manje\n");
	}while(fabs(xk2-x2)>=e);
	
	}
	
	return 0;
}
