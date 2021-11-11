#include <stdio.h>
#include <math.h>
#define e 0.001
#define e2 0.1

int main() {
	
double a, b, c, x1, x2, X1, X2, D, P;

printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf",&a,&b,&c);

if(a==0)
return 0;

D=(b*b)-(4*a*c);

x1=(-b+sqrt(D))/(2*a);
x2=(-b-sqrt(D))/(2*a);

if (D<0)
{printf("Rjesenja su imaginarni brojevi.");
return 0;}


do{
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&X1);
	if(fabs(X1-x1)<e)
	printf("Tacno\n");
	else if ((X1<x1) && fabs(X1-x1)<e2 )
	printf("Priblizno manje\n");
	else if((X1>x1) && fabs(X1-x1)<e2)
	printf("Priblizno vece\n");
	else if(X1<x1)
	printf ("Manje\n");
	else if(X1>x1)
	printf("Vece\n");
	}
while(fabs(X1-x1)>=e);
	
	
do{
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&X2);
	if(fabs(X2-x2)<e)
	printf("Tacno\n");
	else if ((X2<x2) && fabs(X2-x2)<e2 )
	printf("Priblizno manje\n");
	else if((X2>x2) && fabs(X2-x2)<e2)
	printf("Priblizno vece\n");
	else if(X2<x2)
	printf ("Manje\n");
	else if(X2>x2)
	printf("Vece\n");}
while(fabs(X2-x2)>=e);
	
	

return 0;}

