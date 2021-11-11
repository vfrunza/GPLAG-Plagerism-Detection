#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001
#define PRIBLIZNO 0.1
int main() {
	int a, b, c;
	double x1=0, x2=0, d=0, r1=0, r2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	d=pow(b,2)-4*a*c;
	x1=(-b-sqrt(d))/(2*a);
	x2=(-b+sqrt(d))/(2*a);
	if(d<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
	}
	if(d>=0){
	printf("Unesite rjesenje x1: ");
		scanf("%lf", &r1);
	do
	{ 
	if((r1 - x1)>=PRIBLIZNO && x1<r1)
	{
		printf("Vece\nUnesite rjesenje x1: ");
		scanf("%lf", &r1);
	} 
	
	if((x1 - r1)>=PRIBLIZNO && x1>r1)
	{
		printf("Manje\nUnesite rjesenje x1: ");
		scanf("%lf", &r1);
	} 
	if((r1 - x1)<PRIBLIZNO && r1>x1 && (r1 - x1)>=EPSILON)
	{
		printf("Priblizno vece\nUnesite rjesenje x1: ");
		scanf("%lf", &r1);
	} 
	if((x1 - r1)<PRIBLIZNO && r1<x1 && (x1 - r1)>=EPSILON)
	{
		printf("Priblizno manje\nUnesite rjesenje x1: ");
		scanf("%lf", &r1);
	}
	if((x1 - r1)<EPSILON && r1<=0 || (r1 - x1)<EPSILON && r1>=0)
	{printf("Tacno\n");break;}}
	while(d>=0);
	
	printf("Unesite rjesenje x2: ");
		scanf("%lf", &r2);
	do{ 
	if((r2 - x2)>=PRIBLIZNO && x2<r2)
	{
		printf("Vece\nUnesite rjesenje x2: ");
		scanf("%lf", &r2);
	}
	if((x2 - r2)>=PRIBLIZNO && x2>r2)
	{
		printf("Manje\nUnesite rjesenje x2: ");
		scanf("%lf", &r2);
	}
	if((r2 - x2)<PRIBLIZNO && r2>x2  && (r2 - x2)>=EPSILON)
	{
		printf("Priblizno vece\nUnesite rjesenje x2: ");
		scanf("%lf", &r2);
	}
	if((x2 - r2)<PRIBLIZNO && r2<x2 && (x2 - r2)>=EPSILON)
	{
		printf("Priblizno manje\nUnesite rjesenje x2: ");
		scanf("%lf", &r2);
	}
	if((x2 - r2)<EPSILON && r2<=0 || (r2 - x2)<EPSILON && r2>=0)
	{printf("Tacno\n");break;}}while(d>=0);
}

return 0;
}