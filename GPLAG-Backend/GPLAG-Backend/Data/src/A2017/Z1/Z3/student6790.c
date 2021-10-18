#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define RAZLIKA 0.1

int main() {
	double a,b,c,x1,x2,D,n,m;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=b*b-4*a*c;
	
	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	
	do {
		printf("Unesite rjesenje x1: "); scanf("%lf",&n);
		if(fabs(n-x1)<EPSILON) {
			printf("Tacno\n"); break;
		}
		else {
		x1=fabs(x1);
		n=fabs(n);
		if(fabs(n-x1)<=RAZLIKA && n<x1) printf("Priblizno vece\n");
		else if(fabs(n-x1)<=RAZLIKA && n>x1) printf("Priblizno manje\n");
		else {
			x1=fabs(x1);
			n=fabs(n);
			if(fabs(n-x1)>RAZLIKA && n>x1) printf("Vece\n");
			else if(fabs(n-x1)<RAZLIKA && n<x1) printf("Manje\n");
		}
		}

	} while(fabs(n-x1)>EPSILON);

	
	do{
		printf("Unesite rjesenje x2: "); scanf("%lf",&m);
		if(fabs(m-x2)<EPSILON) printf("Tacno\n");
		else if(fabs(m-x2)<RAZLIKA && m>x2) printf("Priblizno vece\n");
		else if(fabs(m-x2)>RAZLIKA && m>x2) printf("Vece\n");
		else if(fabs(m-x2)<RAZLIKA && m>x2) printf("Priblizno manje\n");
		else printf("Manje\n");


	} while(fabs(m-x2)>EPSILON);
	
	
	return 0;
}
