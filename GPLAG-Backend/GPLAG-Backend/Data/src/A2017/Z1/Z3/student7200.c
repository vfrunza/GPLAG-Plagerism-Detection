#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	
	double a, b, c, x1=0, x2=0, D=0, n1=0, n2=0,t1=0,t2=0;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4*a*c;
	if(D < 0) {
		printf ("Rjesenja su imaginarni brojevi.");
	}
	else {
		for (; ;) {
			
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf", &n1);
			x1 = ( (-b - sqrt(D)) / (2*a));
			
			if (fabs(n1-x1)<e) {
				printf ("Tacno\n");
				n1=t1;
				break;
			} else if (n1<t1) {
				printf ("Manje\n");
				
			} else if (n1>t1) {
				printf ("Vece\n");
			   
			} else if (fabs(n1-x1)<0.1) {
				printf ("Priblizno manje\n");
			
			} else if (fabs(n1-x1)>0.1) {
				printf ("Priblizno vece\n");
			
			}
		}
		
		for (; ;) {
			
			printf ("Unesite rjesenje x2: ");
			scanf ("%lf", &n2);
			x2 = ( (-b + sqrt(D)) / (2*a));  
			
			if (fabs(n2-x2)<e) {
				printf ("Tacno\n");
				n2=t2;
				break;
			} if (fabs(n2-x2)<0.1) {
				printf ("Priblizno manje\n");
				
			} else if (fabs(n2-x2)>0.1) {
				printf ("Priblizno vece\n");
				
			} if (n2<t2) {
				printf ("Manje\n");
				
			} else if (n2>t2) {
				printf ("Vece\n");
			}
		}
	}
	return 0;
}
