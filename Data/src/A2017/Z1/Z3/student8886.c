#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	
	double x1, x2, x11, x22, a, b, c, d;
	
	printf ("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	d=b*b-4*a*c;
	
		if (d<0)  
		{	printf("Rjesenja su imaginarni brojevi.");
			return 0;
		}


			 else { 
			x1=(-b+sqrt(d))/(2*a);
			x2=(-b-sqrt(d))/(2*a);
			 }
				 
			do{			
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x11);
			
			if (fabs(x11-x1)<eps)
				printf("Tacno\n");
			else if (x11>=x1-0.100 && x11<x1)
				printf("Priblizno manje\n");
			else if (x11<=x1+0.100 && x11>x1)
				printf("Priblizno vece\n");
			else if (x11<x1+0.100)
				printf("Manje\n");
			else if (x11>x1-0.100)
				printf("Vece\n");
			}	while (x11<x1-eps || x11>x1+eps);
	
				do
				{
					printf("Unesite rjesenje x2: ");
					scanf("%lf", &x22);
					
					if (fabs(x22-x2)<eps)
						printf("Tacno\n");
					else if (x22>x2-0.100 && x22<x2)
						printf("Priblizno manje\n");
					else if (x22<x2+0.100 && x22>x2)
						printf("Priblizno vece\n");
					else if (x22<x2+0.100)
						printf("Manje\n");
					else if (x22>x2-0.100)
						printf("Vece\n");
						
				}while(x22<x2-eps || x22>x2+eps);
	

	
	return 0;
}
