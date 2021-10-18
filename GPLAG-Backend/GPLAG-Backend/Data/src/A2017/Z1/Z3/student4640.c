#include <stdio.h>
#include <math.h>
#define EPSILON1 0.001
#define EPSILON2 0.1

int main() {
    double a,b,c,D,tr1,tr2,x1,x2;
    int tacno=0, tacno2=0;
    printf ("Unesite koeficijente a, b i c: ");
    scanf ("%lf %lf %lf", &a, &b, &c);
    
    D=b*b - 4*a*c;
    
    if (D<0) { printf ("Rjesenja su imaginarni brojevi.");
    return 0;
}
    else 
    
        tr1=(-b-sqrt(D))/(2*a);
        while (tacno==0) {
            printf ("Unesite rjesenje x1: ");
            scanf ("%lf", &x1);
            if (fabs(x1-tr1)<EPSILON1) {
            printf ("Tacno\n");
            tacno=1; 
            }
            else if (fabs(x1-tr1)<EPSILON2 && fabs(x1-tr1)>EPSILON1)
            printf ("Priblizno manje \n");
            else if (fabs(x1-tr1)<EPSILON2)
            printf ("Priblizno vece \n");
            else if ((x1-tr1)<EPSILON2)
            printf ("Manje\n");
            else printf ("Vece\n");
    
        }   
    
        tr2=(-b+sqrt(D))/(2*a);
        
        while (tacno2==0) {
            printf ("Unesite rjesenje x2: ");
            scanf ("%lf", &x2);
            if (fabs(x2-tr2)<EPSILON1) { printf ("Tacno\n");
            tacno2=1;
            
        }
     else if (fabs(x2-tr2)<EPSILON2 && fabs(x2-tr2)>EPSILON1)
    printf ("Priblizno manje \n");
    else if (fabs(x2-tr2)<EPSILON2)
    printf ("Priblizno vece \n");
    else if ((x2-tr2)<EPSILON2)
    printf ("Manje\n");
    else printf ("Vece\n");
     }
    return 0;
}
    