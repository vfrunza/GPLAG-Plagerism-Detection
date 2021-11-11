#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	double a,b,c,D,x1,x2,R1,R2,x11,x22;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=pow(b,2)-4*a*c;
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	x11=(-b+sqrt(D))/(2*a);
	x22=(-b-sqrt(D))/(2*a);
	if(x11<x22) 
	{
		x1=x11;
		x2=x22;
	}
	else{
		x1=x22;
		x2=x11;
	}
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&R1);
		if(R1<(x1+e) && R1>(x1-e)) printf("Tacno\n");
		else if(fabs(R1-x1)<0.1 && R1<x1)printf("Priblizno manje\n") ;
		else if(R1<x1) printf("Manje\n");
		else if(fabs(R1-x1)<0.1 && R1>x1)printf("Priblizno vece\n") ;
		else printf("Vece\n");
		
	} while(R1<=(x1-e) || R1>=(x1+e));
	
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&R2);
		if(R2<(x2+e) && R2>(x2-e)) printf("Tacno\n");
		else if(fabs(R2-x2)<0.1 && R2<x2)printf("Priblizno manje\n") ;
		else if(R2<x2) printf("Manje\n");
		else if(fabs(R2-x2)<0.1 && R2>x2)printf("Priblizno vece\n") ;
		else printf("Vece\n");
	} while(R2<=(x2-e) || R2>=(x2+e));
	
	return 0;
}
