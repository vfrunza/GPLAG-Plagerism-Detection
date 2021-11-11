#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double x1,x2,d,a,b,c,X1,X2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-(4*a*c);
	if(d<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&X1);
		if(fabs(X1-x1)<EPSILON){
			printf("Tacno\n");
			break;
		}
		if(X1<x1 && fabs(X1-x1)>=0.1) printf("Manje\n");
		else if(fabs(X1-x1)<0.1  && X1-x1<EPSILON) printf("Priblizno manje\n");
		else if(fabs(X1)>x1 && X1-x1>=0.1) printf("Vece\n");
		else printf("Priblizno vece\n");
	}while(fabs(X1-x1)>=EPSILON);
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&X2);
		if(fabs(X2-x2)<EPSILON){
			printf("Tacno");
			return 0;
		}
		if(X2<x2 && fabs(X2-x2)>=0.1) printf("Manje\n");
		else if(fabs(X2-x2)<0.1 && X2-x2<EPSILON) printf("Priblizno manje\n");
		else if(fabs(X2)>x2 && X2-x2>=0.1) printf("Vece\n");
		else printf("Priblizno vece\n");
	}while(fabs(X2-x2)>=EPSILON);
	return 0;
}
