#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.001
#define E2 0.1

void zamjena(double *a, double *b)
{
    double c;
    c=*b;
    *b =*a;
    *a=c;
}

int main()
{

    double a,b,c,x1,x2,D;
    double q,p;
    int t=0;

    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);

    D=(b*b)-(4*a*c);
    x1=((-b)-sqrt(D))/(2*a);
    x2=((-b)+sqrt(D))/(2*a);

    if(x1>x2)
        zamjena(&x1,&x2);

    if(D<0) {
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }

    do {

        printf("Unesite rjesenje x1: ");
        scanf("%lf",&q);

        if(fabs(q-x1)<E) {
            printf("Tacno\n");
            t=1;
        }

        else if(q<x1 && fabs(q-x1)<E2)
            printf("Priblizno manje\n");

        else if(q>x1 && fabs(q-x1)<E2)
            printf("Priblizno vece\n");

        else if(q<x1)
            printf("Manje\n");

        else if(q>x1)
            printf("Vece\n");

    } while(t!=1);

    t=0;

    do {

        printf("Unesite rjesenje x2: ");
        scanf("%lf",&p);

        if(fabs(p-x2)<E) {
            printf("Tacno\n");
            t=1;
        }

        else if(p<x2 && fabs(p-x2)<E2)
            printf("Priblizno manje\n");

        else if(p>x2 && fabs(p-x2)<E2)
            printf("Priblizno vece\n");

        else if(p<x2)
            printf("Manje\n");

        else if(p>x2)
            printf("Vece\n");

    } while(t!=1);

    return 0;
}
