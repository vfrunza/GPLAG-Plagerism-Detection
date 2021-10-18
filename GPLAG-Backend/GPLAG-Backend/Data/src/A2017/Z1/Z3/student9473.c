#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a,b,c,d,x1,x2,x11,x22,d1;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	d=b*b-4*a*c;
	if (d<0) printf("Rjesenja su imaginarni brojevi.");
	else {
		d1=sqrt(d);
		x1=(-b+d1)/(2*a);
		x2=(-b-d1)/(2*a);
		
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x11);
			
		    if (fabs(x11-x1)<EPSILON)printf("Tacno\n");
		
			else if(fabs(x11-x1)<0.1 && (x11-x1)<0) printf("Priblizno manje\n");
			else if(fabs(x11-x1)<0.1 && (x11-x1)>0) printf("Priblizno vece\n");
		    else if(x11>x1 && fabs(x11-x1)>EPSILON) printf("Vece\n");
		    else if(x11<x1 && fabs(x11-x1)>EPSILON) printf("Manje\n");
			
		} while(fabs(x11-x1)>=EPSILON);
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x22);
			
	        if(fabs(x22-x2)<EPSILON) printf("Tacno");	
			
			else if(fabs(x22-x2)<0.1 && (x22-x2)<0) printf("Priblizno manje\n");
			else if(fabs(x22-x2)<0.1 && (x22-x2)>0) printf("Priblizno vece\n");
		    else if (x22>x2 && fabs(x22-x2)>EPSILON) printf ("Vece\n");
		    else if(x22<x2 && fabs(x22-x2)>EPSILON) printf("Manje\n");
		} while(fabs(x22-x2)>=EPSILON);
		
	}
	return 0;
}
