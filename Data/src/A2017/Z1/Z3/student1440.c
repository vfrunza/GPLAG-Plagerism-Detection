#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a,b,c,x1,x2,px1,px2,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
		x1=(-b-sqrt(D))/(2*a);
		x2=(-b+sqrt(D))/(2*a);
	if(x2<x1) {
		x1=x2;
		x2=(-b-sqrt(D))/(2*a);
	}
	if(D=0){ 
		x1=-b/(2*a);
		x2=-b/(2*a);
	}

	for(;;) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&px1);
	if(fabs(px1-x1)<EPSILON) {
		printf("Tacno\n");
		break;
	}
	else if(px1>x1 && fabs(px1-x1)<0.1) printf("Priblizno vece\n");
	else if(px1<x1 && fabs(x1-px1)<0.1) printf("Priblizno manje\n");
	else if(px1<x1) printf("Manje\n");
	else if(px1>x1) printf("Vece\n");
	}
		for(;;) {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&px2);
	if(fabs(px2-x2)<EPSILON) {
		printf("Tacno\n");
		break;
	}
	else if(px2>x2 && (px2-x2)<0.1) printf("Priblizno vece\n");
	else if(px2<x2 && (x2-px2)<0.1) printf("Priblizno manje\n");
    else if(px2<x2) printf("Manje\n");
	else if(px2>x2) printf("Vece\n");
	}
	return 0;
}