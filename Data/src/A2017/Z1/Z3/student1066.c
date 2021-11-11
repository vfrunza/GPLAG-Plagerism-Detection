#include <stdio.h>
#include <math.h>
int main() {
	int a,b,c,br=0;
	float d;
	float x1,x2,x,z;
	double eps=0.001;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	d=(b*b)-(4*a*c);
	if(d<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	if(x1>x2)
	{
		x=x1;
		x1=x2;
		x2=x;
	}
	while(br==0)
	{
		printf("Unesite rjesenje x1: ");
		scanf("%f",&z);
		if(fabs(x1-z)<eps)
		{
			printf("Tacno \n");
			break;
		}
		if(fabs(x1-z)<0.10 && z<x1)
		{
			printf("Priblizno manje \n");
		}
		else if(fabs(x1-z)<0.10 && z>x1)
		{
			printf("Priblizno vece \n");
		}
		else if(z<x1)
		{
			printf("Manje \n");
		}
		else if(z>x1)
		{
			printf("Vece \n");
		}
	}
	while(br==0)
	{
		printf("Unesite rjesenje x2: ");
		scanf("%f",&z);
		if(fabs(x2-z)<eps)
		{
			printf("Tacno");
			break;
		}
		if(fabs(x2-z)<0.10 && z<x2)
		{
			printf("Priblizno manje \n");
		}
		else if(fabs(x2-z)<0.10 && z>x2)
		{
			printf("Priblizno vece \n");
		}
		else if(z<x2)
		{
			printf("Manje \n");
		}
		else if(z>x2)
		{
			printf("Vece \n");
		}
	}
	return 0;
}
