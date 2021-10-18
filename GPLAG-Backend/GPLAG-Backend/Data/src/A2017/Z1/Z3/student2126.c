#include <stdio.h>
#include <math.h>
#define epsilon 0.001


int main() {
double a, b, c, x1, x2, a1, a2, d;

printf ("Unesite koeficijente a, b i c: ");
scanf ("%lf%lf%lf", &a, &b, &c);
d = (b*b) - (4*a*c);
if (d < 0) {
    printf ("Rjesenja su imaginarni brojevi.");
    return 0;
}

a1=(-b + sqrt(d))/(2*a);
a2=(-b - sqrt(d))/(2*a);
 

do {
    
    printf ("Unesite rjesenje x1: ");
    scanf ("%lf", &x1);
    if (x1 <= a1) {
        if (fabs(a1-x1)<0.1) {
             if (fabs(a1-x1)<epsilon) { printf ("Tacno"); break; }
             else printf ("Priblizno manje\n"); 
            
        }
        else printf ("Manje\n");
    }
    else if (x1 > a1) {
        
        if (fabs(a1-x1)<0.1) {
             if (fabs(a1-x1)<epsilon) printf ("Tacno");
             else printf ("Priblizno vece\n");
        }
        else printf ("Vece\n");
    }
     
    
  
} while (fabs(a1-x1)>=epsilon);	


do {
    
    printf ("\nUnesite rjesenje x2: ");
    scanf ("%lf", &x2);
    if (x2 <= a2) {
        if (fabs(a2-x2)<0.1) {
           if (fabs(a2-x2)<epsilon) { printf ("Tacno"); break; }
           else printf ("Priblizno manje");
        }
        else printf ("Manje");
    }
    else if (x2 > a2) {
        
        if (fabs(a2-x2)<0.1) {
         if (fabs(a2-x2)<epsilon) printf ("Tacno");
         else printf ("Priblizno vece");
        }
        else printf ("Vece");
    }
     
        
} while (fabs(a2-x2)>=epsilon);	
	
	
	return 0;
}
