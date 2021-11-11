#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main ()
{

    float a,b,c, D, x1, x2, t, rj1, rj2;

    printf ("Unesite koeficijente a, b i c: ");
    scanf ("%f %f %f", &a, &b, &c);

    D=b*b-4.0*a*c;

    if (D<0) {
        printf ("Rjesenja su imaginarni brojevi");

        return 0;

    }
     t = sqrt (D);
	 rj1=(-b+t)/(2*a);
	 rj2=(-b-t)/(2*a);
    
    printf ("Unesite rjesenje x1");
    scanf ("%f", &x1);
    
    if (fabs(x1-rj1)<EPSILON ) {
        printf ("Tacno");
    }
    
    else if (fabs(x1-rj1)>EPSILON) {
        printf ("Vece");
    }
    else if (fabs(rj1-x1)>EPSILON) {
        printf ("Manje");
    }
    else if (fabs(x1-rj1)>0.1) {
        printf ("Priblizno vece");
    }
    else if (fabs(rj1-x1)>0.1) {
        printf ("Priblizno manje");
    }



    return 0;



}