#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int a,b,c;
	double x1,x2,temp,x11;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if(((b*b)-(4*a*c))<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else
	{
		x1=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
		x2=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
	}
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
	}
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%f",&x11);
		if((x11-x1)<0.1)
		{
			printf("Priblizno vece");
		}
		else if((x11-x1)>-0.1)
		{
			printf("Priblizno manje");
		}
		else if((x11-x1)>0.1)
		{
			printf("Manje");
		}
		else 
		{
			printf("Vece");
		}
	}while(x11!=x1);
	printf("Tacno");
	return 0;
}
