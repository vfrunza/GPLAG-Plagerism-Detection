#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define epsilon1 0.1

int main() {
	
	
	double a,b,c, x1=0, x2=0, D, t, n, m;

	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if(a<epsilon) {
		return 0;
	}
	D=b*b-(4.0*a*c);
	
	if(D<0) {
		t=sqrt(-D);
		printf("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	if(D>0) {
		t=sqrt(D);
		x1=(-b-t)/(2*a);
		x2=(-b+t)/(2*a);
	}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &n);
		if((n-x1)<epsilon) {
			printf("Tacno\n");
			break;
		}
		else if((n-x1)>=0.00) {
			printf("Vece\n");
		}
		else if((n-x1)<0.00) {
			printf("Manje\n");
		}
		else if(fabs(n-x1)<epsilon1 && (n-x1)>0) {
			printf("Priblizno manje\n");
			
		}
		else if(fabs(n-x1)>epsilon1 && (n-x1)>0) {
			printf("Priblizno vece\n");
		}
	} 	while((n-x1)>=epsilon);
		
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &m);
		
		if((m-x2)<epsilon) {
			printf("Tacno\n");
			break;
		}
		else if((m-x2)>=0.00) {
			printf("Vece\n");
		}
		else if((m-x2)<0.00) {
			printf("Manje\n");
		}
		else if(fabs(m-x2)<epsilon1 && (m-x2)>0) {
			printf("Priblizno manje\n");
		}
		else if(fabs(m-x2)>epsilon1 && (m-x2)>0) {
			printf("Prilizno vece\n");
		}
		
	} 	while((m-x2)>=epsilon);
	
	
	return 0;
}
