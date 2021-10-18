#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001
#define ALFA 0.1

int main() {
	double a, b, c, D, X1, X2, x1, x2, t;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf", &a, &b, &c);
	D=b*b-(4.0*a*c);
	t=sqrt(D);

	
	if (D<0) {
		printf ("Rjesenja su imaginarni brojevi.");
	} else {
		if (a>0) {
				X1 = (-b-t)/(2*a);
				X2 = (-b+t)/(2*a);
	    
	     do {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x1);
		if (((x1-X1)<0 || (x1-X1)>0) && (fabs(x1-X1))<ALFA && (fabs(x1-X1))>=EPSILON && x1<X1) {
			printf ("Priblizno manje\n");
		} else if (((x1-X1)<0 || (x1-X1)>0) && (fabs(x1-X1))<ALFA && (fabs(x1-X1))>=EPSILON && x1>X1) {
			printf ("Priblizno vece\n");
		} else if ((fabs(X1-x1))<EPSILON) {
			printf ("Tacno");
			break;
		} else if (x1<X1) {
			printf ("Manje\n");
		} else if (x1>X1) {
			printf ("Vece\n");
		}
		
	} while (x1<X1 || x1>X1);
	
	do {
		printf ("\nUnesite rjesenje x2: ");
		scanf ("%lf", &x2);
		if (((x2-X2)<0 || (x2-X2)>0) && (fabs(x2-X2))<ALFA && (fabs(x2-X2))>=EPSILON && x2<X2) {
			printf ("Priblizno manje");
		} else if (((x2-X2)<0 || (x2-X2)>0) && (fabs(x2-X2))<ALFA && (fabs(x2-X2))>=EPSILON && x2>X2 ) {
			printf ("Priblizno vece");
		} else if ((fabs(X2-x2))<EPSILON) {
		printf ("Tacno");
		break; 
		} else if (x2<X2) {
			printf ("Manje");
		} else if (x2>X2) {
			printf ("Vece");
		} 
		
	} while (x2<X2 || x2>X2);
	
	} else {
		X1 = (-b+t)/(2*a);
				X2 = (-b-t)/(2*a);
	    
	     do {
		printf ("Unesite rjesenje x1: ");
		scanf ("%lf", &x1);
		if (((x1-X1)<0 || (x1-X1)>0) && (fabs(x1-X1))<ALFA && (fabs(x1-X1))>=EPSILON && x1<X1) {
			printf ("Priblizno manje\n");
		} else if (((x1-X1)<0 || (x1-X1)>0) && (fabs(x1-X1))<ALFA && (fabs(x1-X1))>=EPSILON && x1>X1) {
			printf ("Priblizno vece\n");
		} else if ((fabs(X1-x1))<EPSILON) {
			printf ("Tacno");
			break;
		} else if (x1<X1) {
			printf ("Manje\n");
		} else if (x1>X1) {
			printf ("Vece\n");
		}
		
	} while (x1<X1 || x1>X1);
	
	do {
		printf ("\nUnesite rjesenje x2: ");
		scanf ("%lf", &x2);
		if (((x2-X2)<0 || (x2-X2)>0) && (fabs(x2-X2))<ALFA && (fabs(x2-X2))>=EPSILON && x2<X2) {
			printf ("Priblizno manje");
		} else if (((x2-X2)<0 || (x2-X2)>0) && (fabs(x2-X2))<ALFA && (fabs(x2-X2))>=EPSILON && x2>X2 ) {
			printf ("Priblizno vece");
		} else if ((fabs(X2-x2))<EPSILON) {
		printf ("Tacno");
		break; 
		} else if (x2<X2) {
			printf ("Manje");
		} else if (x2>X2) {
			printf ("Vece");
		} 
		
	} while (x2<X2 || x2>X2);
		
	}
	

	}

	return 0;
}
