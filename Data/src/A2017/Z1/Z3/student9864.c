#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.001
#define MI 0.1

int main()
{
	double a,b,c,D,x1,x2,X1,X2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=b*b-(4*a*c);
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		}

	else { if(a<0) {
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
			x2=(-b-sqrt(b*b-4*a*c))/(2*a);
			do {
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &X1);
				if(((X1-x1)<0 || (X1-x1)>0) && (fabs(x1-X1))<MI && (fabs(x1-X1))>=EPSILON && X1<x1 ) {
					printf("Priblizno manje\n");
				} else if(((X1-x1)<0 || (X1-x1)>0) && (fabs(x1-X1))<MI && (fabs(x1-X1))>=EPSILON && X1>x1 ) {
					printf("Priblizno vece\n");
				} else if((fabs(x1-X1))<=EPSILON) {
					printf("Tacno\n");
					break;
				} else if(X1<x1) {
					printf("Manje\n");
				} else if (X1>x1) {
					printf("Vece\n");
				}

			} while(X1<x1 || X1>x1);
			do {
				printf("\nUnesite rjesenje x2: ");
				scanf("%lf",&X2);
				if(((X2-x2)<0 || (X2-x2)>0) && (fabs(x2-X2))<MI && (fabs(x2-X2))>=EPSILON && X2<x2 ) {
					printf("Priblizno manje\n");
				} else if(((X2-x2)<0 || (X2-x2)>0) && (fabs(x2-X2))<MI && (fabs(x2-X2))>=EPSILON && X2>x2 ) {
					printf("Priblizno vece\n");
				} else if((fabs(x2-X2))<=EPSILON) {
					printf("Tacno\n");
					break;
				} else if(X2<x2) {
					printf("Manje\n");
				} else if (X2>x2) {
					printf("Vece\n");
				}

			} while(X2<x2 || X2>x2);
		}
	     else {
	     		x1=(-b-sqrt(b*b-4*a*c))/(2*a);
			x2=(-b+sqrt(b*b-4*a*c))/(2*a);

			do {
				printf("Unesite rjesenje x1: ");
				scanf("%lf",&X1);
				
				if(((X1-x1)<0 || (X1-x1)>0) && (fabs(x1-X1))<MI && (fabs(x1-X1))>=EPSILON && X1<x1 ) {
					printf("Priblizno manje\n");
				} else if(((X1-x1)<0 || (X1-x1)>0) && (fabs(x1-X1))<MI && (fabs(x1-X1))>=EPSILON && X1>x1 ) {
					printf("Priblizno vece\n");
				} else if((fabs(x1-X1))<=EPSILON) {
					printf("Tacno\n");
					break;
				} else if(X1<x1) {
					printf("Manje\n");
				} else if (X1>x1) {
					printf("Vece\n");
				}

			} while(X1<x1 || X1>x1);

			do {
				printf("\nUnesite rjesenje x2: ");
				scanf("%lf",&X2);
				 
				if(((X2-x2)<0 || (X2-x2)>0) && (fabs(x2-X2))<MI && (fabs(x2-X2))>=EPSILON && X2<x2 ) {
					printf("Priblizno manje\n");
				} else if(((X2-x2)<0 || (X2-x2)>0) && (fabs(x2-X2))<MI && (fabs(x2-X2))>=EPSILON && X2>x2 ) {
					printf("Priblizno vece");
				} else if((fabs(x2-X2))<=EPSILON) {
					printf("Tacno\n");
					break;
				} else if(X2<x2) {
					printf("Manje\n");
				} else if (X2>x2) {
					printf("Vece\n");
				}

			} while(X2<x2 || X2>x2);

		}
	}
	     return 0;
	}
