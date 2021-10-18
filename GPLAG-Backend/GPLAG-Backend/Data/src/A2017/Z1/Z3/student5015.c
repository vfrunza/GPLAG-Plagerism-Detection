#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define PRIBLIZNO 0.1
int main() {
	double a, b, c, x1, x2, x1U, x2U, t, D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4.0*a*c;
	if (D>0) {
		t=sqrt(D);
		x1=(-b+t)/(2*a);
		x2=(-b-t)/(2*a);
	}
	else if (fabs(D)<EPSILON) {
		x1=-b/(2*a);
		x2=x1;
	}
	else {
		printf ("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	do {
        printf ("Unesite rjesenje x1: ");
        scanf ("%lf", &x1U);
        if (fabs(x1U-x1)<EPSILON) break;
        if ((x1U<x1) && (fabs(x1U-x1)>=PRIBLIZNO)) printf ("Manje\n");
        if ((x1U>x1) && (fabs(x1U-x1)>=PRIBLIZNO)) printf ("Vece\n");
        if ((x1U-x1)>0 && (fabs(x1U-x1)<PRIBLIZNO)) printf ("Priblizno vece\n");
        if ((x1U-x1)<0 && (fabs(x1U-x1)<PRIBLIZNO)) printf ("Priblizno manje\n");
    }
    while (fabs(x1U-x1)>=EPSILON);
    printf ("Tacno\n");
    do {
        printf ("Unesite rjesenje x2: ");
        scanf ("%lf", &x2U);
        if (fabs(x2U-x2)<EPSILON) break;
        if ((x2U<x2) && (fabs(x2U-x2)>=PRIBLIZNO)) printf ("Manje\n");
        if ((x2U>x2) && (fabs(x2U-x2)>=PRIBLIZNO)) printf ("Vece\n");
        if ((x2U-x2)>0 && (fabs(x2U-x2)<PRIBLIZNO)) printf ("Priblizno vece\n");
        if ((x2U-x2)<0 && (fabs(x2U-x2)<PRIBLIZNO)) printf ("Priblizno manje\n");
    }
    while (fabs(x2U-x2)>=EPSILON);
    printf ("Tacno");
	return 0;
}
