#include <stdio.h>
#include <math.h>

#define epsilon 0.001
int main()
{
    double a,b,c,x1,x1f,D,x2,x2f;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);

    D=b*b-4*a*c;
    x1f=((-b-sqrt(D))/(2*a));
    x2f=((-b+sqrt(D))/(2*a));
    
    if(x1f > x2f) {
        double temp = x2f;
        x2f = x1f;
        x1f = temp;
    }

    if (D<0) {
        printf("Rjesenja su imaginarni brojevi.");
        return 1;
    }

    printf("Unesite rjesenje x1: ");
    scanf("%lf",&x1);

    do {
        if(fabs(x1-x1f) >= 0.1 && x1<x1f) {
            printf("Manje\n");
        } else if (fabs(x1-x1f) >= 0.1 && x1>x1f)  {
            printf("Vece\n");
        } else if(fabs(x1-x1f) < 0.1 && x1 < x1f && fabs(x1-x1f)>=epsilon) {
            printf("Priblizno manje\n");
        } else if(fabs(x1-x1f) < 0.1 && x1 > x1f && fabs(x1-x1f)>=epsilon)
            printf("Priblizno vece\n");

        if(fabs(x1-x1f)>=epsilon) {
            printf("Unesite rjesenje x1: ");
            scanf("%lf",&x1);
        }

    } while(fabs(x1-x1f)>=epsilon);

    if(fabs(x1-x1f)<epsilon) {
        printf("Tacno\n");
    }

    printf("Unesite rjesenje x2: ");
    scanf("%lf",&x2);

    do {
        if(fabs(x2-x2f) >= 0.1 && x2 < x2f) {
            printf("Manje\n");
        } else if(fabs(x2-x2f) >= 0.1 && x2 > x2f) {
            printf("Vece\n");
        } else if(fabs(x2-x2f) < 0.1 && x2 < x2f && fabs(x2-x2f)>=epsilon) {
            printf("Priblizno manje\n");
        } else if(fabs(x2-x2f) < 0.1 && x2 > x2f && fabs(x2-x2f)>=epsilon) {
            printf("Priblizno vece\n");
        }

        if(fabs(x2-x2f)>=epsilon) {
            printf("Unesite rjesenje x2: ");
            scanf("%lf",&x2);
        }

    } while(fabs(x2-x2f)>=epsilon);

    if(fabs(x2-x2f)<epsilon) {
        printf("Tacno\n");
    }


    return 0;
}
