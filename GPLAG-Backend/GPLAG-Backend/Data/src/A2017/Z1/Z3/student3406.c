#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	int a, b, c;
	double x1, x2, x, D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	D = b*b -4*a*c;
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else {
		D = (double)(b*b-4*a*c);
		D = sqrt(D);
		x1 = (-b + D)/(2*a);
		x2 = (-b - D)/(2*a);
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x);
			if(x>x1-EPSILON && x<x1+EPSILON) printf("Tacno\n");
			else if (x<=x1-0.1) printf("Manje\n");
			else if(x>x1-0.1 && x<x1-EPSILON) printf("Priblizno manje\n");
			else if(x>=x1+EPSILON && x<x1+0.1) printf("Priblizno vece\n");
			else printf("Vece\n");
		} while(x<=x1-EPSILON || x>=x1+EPSILON);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x);
			if(x>x2-EPSILON && x< x2+EPSILON) printf("Tacno\n");
			else if (x<=x2-0.1) printf("Manje\n");
			else if(x>x2-0.1 && x<x2-EPSILON) printf("Priblizno manje\n");
			else if(x>x2+EPSILON && x<x2+0.1) printf("Priblizno vece\n");
			else printf("Vece\n");
		} while(x<=x2-EPSILON || x>=x2+EPSILON);
	}
	
	return 0;
}
