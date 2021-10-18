#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define RAZLIKA 0.1
int main()
{
	double a,b,c,x1,x2,x1tacno=0,x2tacno=0,x1pokusaj,x2pokusaj;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if((b*b-4*a*c)<0)
		{
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
		}
	if(a>0)
		{
		x1=((-b - sqrt(b*b-4*a*c))/(2*a));
		}
	if(a>0 && b>sqrt(b*b-4*a*c)|| a<0 && b<sqrt(b*b-4*a*c)||sqrt(b*b-4*a*c)==0)
		{
		x1=((-b + sqrt(b*b-4*a*c))/(2*a));	
		}
	do 
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1pokusaj);
		if(fabs(x1pokusaj-x1)<EPSILON)
			{
			printf("Tacno\n");
			x1tacno=1;}
		if(fabs(x1pokusaj-x1)>=RAZLIKA && fabs(x1pokusaj-x1)>=EPSILON && x1pokusaj<x1)
			{
			printf("Manje\n");
			}
		if(fabs(x1pokusaj-x1)>=RAZLIKA && x1pokusaj>x1)
			{
			printf("Vece\n");
			}
		if(fabs(x1pokusaj-x1)<RAZLIKA && fabs(x1pokusaj-x1)>=EPSILON && x1pokusaj<x1)
			{
			printf("Priblizno manje\n");
			}
		if(fabs(x1pokusaj-x1)<RAZLIKA && fabs(x1pokusaj-x1)>=EPSILON && x1pokusaj>x1)
			{
			printf("Priblizno vece\n");
			}
		}
	while(x1tacno!=1);
	
	if(a<0)
	{
	x2=((-b - sqrt(b*b-4*a*c))/(2*a));	
	}
	if(a<0 && b>sqrt(b*b-4*a*c)|| a>0 && b<sqrt(b*b-4*a*c)||sqrt(b*b-4*a*c)==0)
		{
		x2=((-b + sqrt(b*b-4*a*c))/(2*a));	
		}
	if(fabs(x1pokusaj-x1)<EPSILON)	
		do 
		{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2pokusaj);
		if(fabs(x2pokusaj-x2)<EPSILON)
			{
			printf("Tacno\n");
			x2tacno=1;
			}
		if(fabs(x2pokusaj-x2)>=RAZLIKA && fabs(x2pokusaj-x2)>=EPSILON && x2pokusaj<x2)
			{
			printf("Manje\n");
			}
		if(fabs(x2pokusaj-x2)>=RAZLIKA && x2pokusaj>x2)
			{
			printf("Vece\n");
			}
		if(fabs(x2pokusaj-x2)<RAZLIKA && fabs(x2pokusaj-x2)>=EPSILON && x2pokusaj<x2)
			{
			printf("Priblizno manje\n");
			}
		if(fabs(x2pokusaj-x2)<RAZLIKA && fabs(x2pokusaj-x2)>=EPSILON && x2pokusaj>x2)
			{
			printf("Priblizno vece\n");
			}
		}
		while(x2tacno!=1);
	
}