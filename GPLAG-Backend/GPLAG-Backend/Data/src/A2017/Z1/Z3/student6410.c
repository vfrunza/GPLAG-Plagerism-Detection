#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	double a,b,c,x1,x2,x11,x22,max,min;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	max=x1;
	min=x2;
	if(x1<min){ min=x1; max=x2;}
	if((b*b-4*a*c)<0)
	printf("Rjesenja su imaginarni brojevi.");
	else{
		do{ 
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x11);
		if(fabs(min-x11)<eps) 
			printf("Tacno\n");
		else if(fabs(min-x11)<0.1 && x11<min)
		printf("Priblizno manje\n");
		else if(fabs(min-x11)<0.1 && x11>min)
		printf("Priblizno vece\n");
		else if(x11<min)
		printf("Manje\n");
		else if(x11>min)
		printf("Vece\n");
		}while (fabs(min-x11)>=eps);
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x22);
		if(fabs(max-x22)<eps)
		printf("Tacno\n");
		else if(fabs(max-x22)<0.1 && x22<max)
		printf("Priblizno manje\n");
		else if(fabs(max-x22)<0.1 && x22>max)
		printf("Priblizno vece\n");
		else if(x22<max)
		printf("Manje\n");
		else if(x22>max)
		printf("Vece\n");
		}while(fabs(max-x22)>=eps);
		
		 
	}
	return 0;
}
