#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.001
int main() {
	double a,b,c,x1,x2,D,x1_new,x2_new,temp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else
	{
		x1=(-b+sqrt(D))/(2*a);
		x2=(-b-sqrt(D))/(2*a);
		if(x1>x2){
			temp=x2;
			x2=x1;
			x1=temp;
		}
		do 
		{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1_new);
		if ( fabs(x1_new - x1)<e)
		{
			printf("Tacno\n");
			break;
		}
		else if(x1_new > x1 && fabs(x1_new - x1) < 0.1)
		{
			printf("Priblizno vece\n");
		}
		else if(x1_new < x1 && fabs(x1_new - x1)< 0.1)
		{
			printf("Priblizno manje\n");
		}	
		else if(x1_new > x1)
		{
			printf("Vece\n");
		}
		else if(x1_new < x1)
		{
			printf("Manje\n");
		}
		}while(1);
		
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x2_new);
		if ( fabs(x2_new - x2)<e)
		{
			printf("Tacno\n");
			break;
		}
		else if(x2_new > x2 && fabs(x2_new - x2) < 0.1)
		{
			printf("Priblizno vece\n");
		}
		else if(x2_new < x2 && fabs(x2_new - x2)< 0.1)
		{
			printf("Priblizno manje\n");
		}	
		else if(x2_new > x2)
		{
			printf("Vece\n");
		}
		else if(x2_new < x2)
		{
			printf("Manje\n");
		}
		}while(1);
		
	}
	return 0;
}
