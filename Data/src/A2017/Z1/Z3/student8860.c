#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, d, x1, x2, min, max, random, z; 
	int t=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	d=b*b-4*a*c;
	if(d<0)
	{
			printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	else
	{
			x1=(-b+sqrt(d))/(2*a);
			x2=(-b-sqrt(d))/(2*a);
	}
	if(x1<=x2)
	{
			min=x1;
			max=x2;
	}
	else if(x1>x2)
	{
			min=x2;
			max=x1;
	}
	do
	{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &random);
			if(fabs(random-min)<EPSILON)
			{
					printf("Tacno\n");
					t=1;
	}
	else if((random<min) && fabs(random-min)<0.1 && t==0)
	{
			printf("Priblizno manje\n");
			t=0;
	}
	else if((random>min) && fabs(random-min)<0.1 && t==0)
	{
			printf("Priblizno vece\n");
			t=0;
	}
	else if((random<min) && fabs(random-min)>=0.1 && t==0)
	{
			printf("Manje\n");
			t=0;
	}
	else if((random>min) && fabs(random-min)>=0.1 && t==0)
	{
			printf("Vece\n");
			t=0;
	}
	} while(t==0);
	do
	{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &z);
			if(fabs(z-max)<EPSILON)
			{
					printf("Tacno\n");
					t=1;
				return 1;
			}
			else if(z<max && fabs(z-max)<0.1)
			{
				printf("Priblizno manje\n");
				t=0;
			}
			else if(z>max && fabs(z-max)<0.1)
			{
				printf("Priblizno vece\n");
				t=0;
			}
			else if(z<max && fabs(z-max)>=0.1)
			{
				printf("Manje\n");
				t=0;
			}
			else if(z>max && fabs(z-max)>=0.1)
			{
				printf("Vece\n");
				t=0;
			}
	} while(t==0);
	return 0;
}
