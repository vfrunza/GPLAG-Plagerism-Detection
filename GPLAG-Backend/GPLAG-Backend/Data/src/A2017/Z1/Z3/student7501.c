#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define APPROX 0.1

int main() {
	

    double a, b, c, D, x1, x2, y1, y2;

	
    printf("Unesite koeficijente a, b i c: ");	
	scanf("%lf %lf %lf", &a, &b, &c);
	
    D = b*b -4*a*c;
    

	if (D<0) printf("Rjesenja su imaginarni brojevi.");
	else {
		
		x1 = (-b + sqrt(D))/(2*a);
    	y1 = x1+1;
    	
    	x2 = (-b - sqrt(D))/(2*a);
    	y2 = x2+1;
    	
		do
		{
		
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &y1);
			if (fabs(y1-x1)<EPSILON) printf("Tacno\n"); 
		    else if (fabs(y1-x1)>=0.1 && y1>x1) printf("Vece\n");
		    else if (fabs(x1-y1)>=0.1 && x1>y1) printf("Manje\n");
		    else if (fabs(y1-x1)<0.1 && y1<x1) printf("Priblizno manje\n");
		    else printf("Priblizno vece\n");
	
		} while (fabs(y1-x1)>=EPSILON);
	    
	    do
	     {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &y2);
			if (fabs(y2-x2)<EPSILON)printf("Tacno\n");
			else if (fabs(y2-x2)>=0.1 && y2>x2) printf("Vece\n");
		    else if (fabs(x2-y2)>=0.1 && x2>y2) printf("Manje\n");
		    else if (fabs(y2-x2)<0.1 && y2<x2) printf("Priblizno manje\n");
		    else printf("Priblizno vece\n");
			
	     } while(fabs(y2-x2)>=EPSILON);
	
		
		
	}


	return 0;
}
