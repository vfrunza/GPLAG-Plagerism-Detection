#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	/*printf("Zadaća 1, Zadatak 3");*/
	double a, b, c, D, x1, x2, p, q, m, n;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	D=b*b-4*a*c;
	p=(-b-sqrt(D))/(2*a);
	q=(-b+sqrt(D))/(2*a);
	if (p<=q)
	{	x1=p;
		x2=q;
	} else
	{
	x1=q;
	x2=p;
	}
	
	if (D<0) {printf("Rjesenja su imaginarni brojevi.");}
	else {
		
		do {
			printf ("Unesite rjesenje x1: ");
			scanf("%lf", &m);
				if (fabs(x1-m)<EPSILON)
				{printf("Tacno\n");
				break;}
				
			if(fabs(x1-m)<0.1)
			
			{ 	
				
				if(m>x1) printf("Priblizno vece\n");
				else printf("Priblizno manje\n");
				
			} 
				else if (fabs(x1-m)>0.1)
			{	
				if (m>x1) printf("Vece\n");
				else printf("Manje\n");}
			
			} 	while (!(fabs(x1-m)<EPSILON));
    	   		
      
     
		do
		{
			printf("\nUnesite rjesenje x2: ");
			scanf("%lf", &n);
				
				if (fabs(x2-n)<EPSILON) {printf("Tacno\n");
				break;}
			
				if (fabs(x2-n)<0.1)
			{
			
				if (n>x2) {printf("Priblizno vece\n");}
				else {printf("Priblizno manje\n");}
			
				
			}
			
			 	else if(fabs(x2-n)>0.1)
			 	
			{	
				if (n>x2) printf("Vece\n");
				else printf("Manje\n");}
				
			
		} while (!(fabs(x2-n)<EPSILON));
	    
		
		}
		return 0;
}
