#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.001

int main() {
	int a,b,c;
	double d,x1,x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	if(b*b-4*a*c<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else
	d=b*b-4*a*c;
	x1=(-b+sqrt(d))/(2.*a);
	x2=(-b-sqrt(d))/(2.*a);
	if(x2<x1){
		double pom=x1;
		x1=x2;
		x2=pom;
	}
	while(1){
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&d);
		if(fabs(x1-d)<eps){
			printf("Tacno\n");
			break;
		}
		else if(fabs(x1-d)<0.1 && d<x1)
		printf("Priblizno manje\n");
		else if(fabs(x1-d)<0.1 && d>x1)
		printf("Priblizno vece\n");
		else if(x1>d)
		printf("Manje\n");
		else
		printf("Vece\n");
	}
	while(1){
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&d);
		if(fabs(x2-d)<eps){
			printf("Tacno\n");
			break;
		}
		else if(fabs(x2-d)<0.1 && d<x2)
		printf("Priblizno manje\n");
		else if(fabs(x2-d)<0.1 && d>x2)
		printf("Priblizno vece\n");
		else if(x2>d)
		printf("Manje\n");
		else
		printf("Vece\n");
	}
	return 0;
}
