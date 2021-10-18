#include <stdio.h>
#include <math.h>
#define e 0.001

int main()
{
	double a,b,c,D;
	double x1,x2;
	double novox1;
	double rj1,rj2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	D=sqrt(D);
	x1=(-b+D)/(2*a);
	x2=(-b-D)/(2*a);
	if(x1>x2) {
		novox1=x1;
		x1=x2;
		x2=novox1;
	}
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&rj1);
		if(fabs(rj1-x1)<e) printf("Tacno\n");
		else if(fabs(x1-rj1)<0.1 && x1<rj1) printf("Priblizno vece\n");
		else if(fabs(x1-rj1)<0.1 && x1>rj1) printf("Priblizno manje\n");
		else if(rj1<x1) printf("Manje\n");
		else if(rj1>x1) printf("Vece\n");
	} while (fabs(rj1-x1)>=e);
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&rj2);
		if(fabs(rj2-x2)<e) printf("Tacno\n");
		else if(fabs(x2-rj2)<0.1 && x2<rj2) printf("Priblizno vece\n");
		else if(fabs(x2-rj2)<0.1 && x2>rj2) printf("Priblizno manje\n");
		else if(rj2<x2) printf("Manje\n");
		else if(rj2>x2) printf("Vece\n");
	} while (fabs(rj2-x2)>=e);
	return 0;
}
