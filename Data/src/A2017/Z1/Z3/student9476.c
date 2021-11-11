#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	
	double a,b,c;
	double d,ux1,ux2;
	double x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	
	if(d>=0)
	{
	x1=(-b+sqrt(d))/(2*a);
	ux1=x1+1;
	
	x2=(-b-sqrt(d))/(2*a);
	ux2=x2+1;
	 do 
	{
		printf("Unesite rjesenje x1: ");scanf("%lf",&ux1);
		if(fabs(ux1-x1)<e) printf("Tacno\n");
		else if(fabs(ux1-x1)>=0.1 && ux1>x1) printf("Vece\n");
		else if(fabs(x1-ux1)>=0.1 && x1>ux1)printf("Manje\n");
		else if(fabs(ux1-x1)<0.1 && ux1<x1) printf("Priblizno manje\n");
		else printf("Priblizno vece\n");
	}while(fabs(ux1-x1)>=e);
		
	do 
	{
		printf("Unesite rjesenje x2: ");scanf("%lf",&ux2);
		if(fabs(ux2-x2)<e) printf("Tacno\n");
		else if(fabs(ux2-x2)>=0.1 && ux2>x2) printf("Vece\n");
		else if(fabs(x2-ux2)>=0.1 && x2>ux2)printf("Manje\n");
		else if(fabs(ux2-x2)<0.1 && ux2<x2) printf("Priblizno manje\n");
		else printf("Priblizno vece\n");
	}while(fabs(ux2-x2)>=e);
	}else printf("Rjesenja su imaginarni brojevi.");
	return 0;
}
