#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main()
{

    double x1,x2,a,b,c,d,prvi,drugi;

    printf ("Unesite koeficijente a, b i c: ");
    scanf ("%lf%lf%lf", &a,&b,&c);

    d= (b*b -4*a*c);
    x1= ( -b + sqrt(d)) / (2*a);
    x2= ( -b - sqrt(d)) / (2*a);

    if (d<0) {
        printf ("Rjesenja su imaginarni brojevi.");
        return 0;
    }

    do {
        printf  ("Unesite rjesenje x1: ");
        scanf ("%lf", &prvi);
        if (fabs(prvi-x1)<EPSILON) {
            printf ("Tacno\n");
        } else if (fabs(prvi-x1)<0.1 && prvi<x1) {
            printf ("Priblizno manje\n");
        } else if (fabs(prvi-x1)<0.1 && prvi>x1) {
            printf ("Priblizno vece\n");
        } else if (prvi > x1) {
            printf ("Vece\n");
        } else if (prvi < x1) {
            printf ("Manje\n");
        }

    } while (fabs(prvi-x1)>=EPSILON);

    do {
        printf  ("Unesite rjesenje x2: ");
        scanf ("%lf", &drugi);
        if (fabs(drugi-x2)<EPSILON) {
            printf ("Tacno\n");
        } else if (fabs(drugi-x2)<0.1 && drugi<x2) {
            printf ("Priblizno manje\n");
        } else if (fabs(drugi-x2)<0.1 && drugi>x2) {
            printf ("Priblizno vece\n");
        } else if (drugi > x2) {
            printf ("Vece\n");
        } else if (drugi < x2) {
            printf ("Manje\n");
        }

    } while (fabs(drugi-x2)>=EPSILON);

    return 0;
}
