#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define eps2 0.1
int main() {
	double a, b, c, D, x1, x2, X1, X2, pom;
	printf("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	
	D=(b*b-4*a*c);
if (D<0){ 
		printf ("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	X1=((-b+sqrt(D))/(2*a));
	X2=((-b-sqrt(D))/(2*a));
	if (X1>X2) { pom=X1;
	X1=X2;
	X2=pom;
	}
	do { 
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x1); 
		 
		if (fabs(X1-x1)<EPSILON){
			printf ("Tacno\n"); break;
		}
		if (x1<X1) { if (fabs(x1-X1)<eps2)printf ("Priblizno manje\n");
		else printf ("Manje\n"); }
		else if (x1>X1) { if (fabs(x1-X1)<eps2) printf ("Priblizno vece\n");
		else printf ("Vece\n");}
	} while (1);
    
    do { 
    	printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &x2);
	 if (fabs(X2-x2)<EPSILON){
	 	printf ("Tacno \n"); break; 
	 }
	 if (x2<X2){ if (fabs(x2-X2)<eps2) printf ("Priblizno manje\n");
	 else printf ("Manje\n");}
	 else if (x2>X2){ if (fabs(x2-X2)<eps2) printf ("Priblizno vece\n");
	 else printf ("Vece\n");
		}
	} while (1);
	return 0;
}
