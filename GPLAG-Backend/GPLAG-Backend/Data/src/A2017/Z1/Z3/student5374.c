#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	double a,b,c;
	double d,rx1,rx2;
	double x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	
	if(d>=0)
	{
	
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	do
{
	printf("Unesite rjesenje x1: ");scanf("%lf",&rx1);
	if(fabs(rx1-x1)<e)printf("Tacno\n");
	else if(fabs(rx1-x1)>=0.1 && rx1>x1)printf("Vece\n");
	else if(fabs(x1-rx1)>=0.1 && x1>rx1)printf("Manje\n");
	else if(fabs(rx1-x1)<0.1 && rx1<x1)printf("Priblizno manje\n");
	else printf("Priblizno vece\n");
}while(fabs(rx1-x1)>=e);

do
{
	printf("Unesite rjesenje x2: ");scanf("%lf",&rx2);
	if(fabs(rx2-x2)<e)printf("Tacno\n");
	else if(fabs(rx2-x2)>=0.1 && rx2>x2)printf("Vece\n");
	else if(fabs(x2-rx2)>=0.1 && x2>rx2)printf("Manje\n");
	else if(fabs(rx2-x2)<0.1 && rx2<x2)printf("Priblizno manje\n");
	else printf("Priblizno vece\n");
}while(fabs(rx2-x2)>=e);
	

}else printf("Rjesenja su imaginarni brojevi. ");
	
	return 0;
}
