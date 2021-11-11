#include <stdio.h>
#include <math.h>
int main() {
	int a,b,c,tacno1=0,tacno2=0;
	double x1=0,x2=0,D=0,x1u,x2u=0,razlika=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1u);
		razlika=x1u-x1;
		razlika=fabs(razlika);
		if(razlika<=0.0001)
		{
			printf("Tacno\n");
			tacno1=1;
		}
		else if(x1>x1u)
		{
			if(razlika<0.1)
			{
				printf("Priblizno manje\n");
			}
			else printf("Manje\n");
		}
		else if(x1<x1u)
		{
			if(razlika<0.1)
			{
				printf("Priblizno vece\n");
			}
			else printf("Vece\n");
		}
	}
	while(tacno1!=1);
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2u);
		razlika=x2u-x2;
		razlika=fabs(razlika);
		if(razlika<=0.0001)
		{
			printf("Tacno\n");
			tacno2=1;
		}
		else if(x2>x2u)
		{
			if(razlika<0.1)
			{
				printf("Priblizno manje\n");
			}
			else printf("Manje\n");
		}
		else if(x2<x2u)
		{
			if(razlika<0.1) 
			{
				printf("Priblizno vece\n");
			}
			else printf("Vece\n");
		}
	}
	while(tacno2!=1);
	return 0;
}
