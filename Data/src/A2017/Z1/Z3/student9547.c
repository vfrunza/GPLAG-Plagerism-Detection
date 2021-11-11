#include <stdio.h>
#define EPSILON 0.001
#include<math.h>
int main() {
	double a,b,c,D=0;
	double g1=0;
	double g2=0;
	double x1=0;
	double x2=0;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a, &b, &c);
	D=pow(b,2)-4.0*a*c;
	if((D<0))
	{
		printf("Rjesenja su imaginarni brojevi.");
	
	return 0;
	
}
	x1=(-b+sqrt(pow(b,2)-4.0*a*c))/(2.*a);
	x2=(-b-sqrt(pow(b,2)-4.0*a*c))/(2.*a);
	do
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &g1);
		if((g1-x1>=EPSILON)&&(g1-x1<0.1))
		{
			printf("Priblizno vece\n");
		}
		else if((g1-x1<=-0.001)&&(g1-x1>-0.1))
		{
			printf("Priblizno manje\n");
		}
		if(g1-x1<=-0.1)
		printf("Manje\n");
		 if(g1-x1>=0.1)
		
			printf("Vece\n");
		}
		while(fabs(g1-x1)>=EPSILON);
		if(fabs(g1-x1)<EPSILON)
		{
		printf("Tacno\n");
		}
	
		
		do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &g2);
		if((g2-x2>=EPSILON)&&(g2-x2<0.1))
		{
			printf("Priblizno vece\n");
		}
		else if((g2-x2<=-0.001)&&(g2-x2>-0.1))
		{
			printf("Priblizno manje\n");
		}
		if(g2-x2<=-0.1)
		printf("Manje\n");
		 if(g2-x2>=0.1)
		
			printf("Vece\n");
			
		}
		while(fabs(g2-x2)>=EPSILON);
		 if(fabs(g2-x2)<EPSILON)
		
		
		
		printf("Tacno\n");
	
		
		return 0;
	}
