#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c,D,x1,x2,xa,xb;
	
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	D=(b*b)-(4*a*c);
	
	if (D<0) {
	printf("Rjesenja su imaginarni brojevi.");
	}
	if(D>=0) {
	xa=(-b-sqrt(D))/(2*a);
	xb=(-b+sqrt(D))/(2*a);
		
	if(xa>xb) {
		double tmp=xa;
		xa=xb;
		xb=tmp;
	}
	
	for(;;) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		
		if(fabs(x1-xa)<EPSILON) {
			printf("Tacno\n");
			break;
		}
		else if(fabs(x1-xa)<0.1 && x1>xa) {
			printf("Priblizno vece\n");
		}
		else if(fabs(x1-xa)<0.1 && x1<xa) {
			printf("Priblizno manje\n");
		}
		else if(x1>xa) {
			printf("Vece\n");
		} 
		else if(x1<xa) {
			printf("Manje\n");
		}
		
		
	}
	
	
		for(;;) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		
		if(fabs(x2-xb)<EPSILON) {
			printf("Tacno\n");
			break;
		}
		else if(fabs(x2-xb)<0.1 && x2>xb) {
			printf("Priblizno vece\n");
		}
		else if(fabs(x2-xb)<0.1 && x2<xb) {
			printf("Priblizno manje\n");
		}
		else if(x2>xb) {
			printf("Vece\n");
		} 
		else if(x2<xb) {
			printf("Manje\n");
		}
		
		
	}
	}
	return 0;
}
