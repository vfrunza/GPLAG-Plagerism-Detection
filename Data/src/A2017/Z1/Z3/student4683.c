#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main()
{
    double k1, k2, k3, x1, x2, y1, y2, D;

    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &k1, &k2, &k3);
    D=(k2*k2)-(4*k1*k3);
    if(D<0) {
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    if(k1>0) {
    y1=((-1*k2-sqrt(k2*k2-4*k1*k3))/(2*k1));
    y2=((-1*k2+sqrt(k2*k2-4*k1*k3))/(2*k1)); }
    else { 
    y2=((-1*k2-sqrt(k2*k2-4*k1*k3))/(2*k1));
    y1=((-1*k2+sqrt(k2*k2-4*k1*k3))/(2*k1)); } 
    
    printf("Unesite rjesenje x1: ");
    scanf("%lf", &x1);

do {    while (fabs(y1-x1)>=0.1 && y1>x1)
        { printf("Manje\n");
            printf("Unesite rjesenje x1: "); 
            scanf("%lf", &x1); }

    while (fabs(x1-y1)>=0.1 && x1>y1)
        { printf("Vece\n");
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1); }
        
    while ((x1-y1)<0.1 && fabs(x1-y1)>=EPSILON && x1>y1)
        { printf("Priblizno vece\n");
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1); }
        
    while ((y1-x1)<0.1 && fabs(y1-x1)>=EPSILON && y1>x1) 
        { printf("Priblizno manje\n");
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1); } } while (fabs(y1-x1)>EPSILON);
        
    if (fabs(y1-x1)<EPSILON);
     printf("Tacno\n");

    printf("Unesite rjesenje x2: ");
    scanf("%lf", &x2);

    do{    while (fabs(x2-y2)>=0.1 && x2>y2)
        { printf("Vece\n");
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x2); }
        

        while (fabs(y2-x2)>=0.1 && y2>x2) 
        { printf("Manje\n");
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x2); }
            
        
        while ((x2-y2)<0.1 && fabs(x2-y2)>=EPSILON && x2>y2)
        { printf("Priblizno vece\n");
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x2); }
        
        
         while ((y2-x2)<0.1 && fabs(y2-x2)>=EPSILON && y2>x2) 
         { printf("Priblizno manje\n");
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x2); } } while (fabs(y2-x2)>EPSILON);
    

    if (fabs(y2-x2)<EPSILON)
    printf("Tacno\n");
    return 0;
}
