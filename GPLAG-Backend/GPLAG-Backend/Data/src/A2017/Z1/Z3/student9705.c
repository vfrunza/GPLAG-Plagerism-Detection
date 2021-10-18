#include <stdio.h>
#include <math.h>
#define e 0.001
int main() 
{
	double theD,a,b,c,x1,x2,unos,temp;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	theD=b*b-4*a*c;
	if(theD<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
	}
	else
	{
		x1=(-b+sqrt(theD))/(2*a);
		x2=(-b-sqrt(theD))/(2*a);
		
		if(x1>x2)
		{
		temp=x1;
		x1=x2;
		x2=temp;
			
		}
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&unos);
			if(fabs(unos-x1)<e) printf("Tacno\n");
			else if(fabs(unos-x1)<0.1 && unos<x1) printf("Priblizno manje\n");
			else if(fabs(unos-x1)<0.1 && unos>x1) printf("Priblizno vece\n");
			else if(unos<x1) printf("Manje\n");
			else printf("Vece\n");
		}while(fabs(unos-x1)>=e);
		do
		{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&unos);
			if(fabs(unos-x2)<e) printf("Tacno\n");
			else if(fabs(unos-x2)<0.1 && unos<x2) printf("Priblizno manje\n");
			else if(fabs(unos-x2)<0.1 && unos>x2) printf("Priblizno vece\n");
			else if(unos<x2) printf("Manje\n");
			else printf("Vece\n");
		}while(fabs(unos-x2)>=e);
	}
	return 0;
}
