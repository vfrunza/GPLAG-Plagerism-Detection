#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double a, b, c, x1, x2, D, p, p2,x;
	int i=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	
	D=(b*b)-(4.0*a*c);
	if (D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	
	x1=(b*(-1.0)-sqrt(D))/(2.0*a);
	x2=(b*(-1.0)+sqrt(D))/(2.0*a);
	
	if (x1>x2)
	{
		x=x1;
		x1=x2;
		x2=x;
	}
	
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&p);
		if (fabs(p-x1)<e)
		{
			printf("Tacno");
			i=1;
		}else
		if (p<x1)
		{
			if (x1-p<0.1)
			printf("Priblizno manje");else
		printf("Manje");
		}
		else
		{
			if (p-x1<0.1)
			printf("Priblizno vece");else
		printf("Vece");
		}
		printf("\n");
	}
	while(i==0);
	
	i=0;
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&p2);
		if (fabs(p2-x2)<e)
		{
			printf("Tacno");
			i=1;
		}else
		if (p2<x2)
		{
			if (x2-p2<0.1)
			printf("Priblizno manje");else
		printf("Manje");
		}
		else
		{
			if (p2-x2<0.1)
			printf("Priblizno vece");else
		printf("Vece");
		}
		printf("\n");
	}
	while(i==0);
	
	return 0;
}
