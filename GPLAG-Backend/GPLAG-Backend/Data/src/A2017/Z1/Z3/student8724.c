#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001
int main() {
	double a, b, c, x1, x2, rj1, rj2, D;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	/*racunanje kvadrata diskriminante*/
	D=b*b-4*a*c;
	if (D<0) printf ("Rjesenja su imaginarni brojevi.");
	else {
		do
		{
			/*unos prvog rjesenja*/
			printf ("Unesite rjesenje x1: ");
			scanf ("%lf", &x1);
	   	    rj1=(-b+sqrt(D))/(2*a);
		    if (x1-rj1>=0.1) printf ("Vece\n");
		    else if (rj1-x1>=0.1) printf ("Manje\n");
		    else if ((rj1-x1)<0.1 && (rj1-x1)>=EPSILON) printf ("Priblizno manje\n");
		    else if ((x1-rj1)<0.1 && (x1-rj1)>=EPSILON) printf ("Priblizno vece\n");
		    else {
		    	printf ("Tacno\n");
		    	break;
		    }
	    } while (fabs (x1-rj1)>=EPSILON);
	    
	    do {
	    	/*unos drugog rjesenja*/
	    	printf ("Unesite rjesenje x2: ");
	    	scanf ("%lf", &x2);
	    	rj2=(-b-sqrt(D))/(2*a);
	    	if (x2-rj2>=0.1) printf ("Vece\n");
	    	else if (rj2-x2>=0.1) printf ("Manje\n");
	    	else if ((x2-rj2)<0.1 && (x2-rj2)>=EPSILON) printf ("Priblizno vece\n");
	    	else if ((rj2-x2)<0.1 && (rj2-x2)>=EPSILON)printf ("Priblizno manje\n");
	    	else  {
	    		printf ("Tacno\n");
	    	}
	    } while (fabs (x2-rj2)>=EPSILON);
	}

	return 0;
}
