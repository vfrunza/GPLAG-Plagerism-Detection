#include <stdio.h>
#define EPSILON 0.001
#include <math.h>
int main() {
	double a,b,c, x_1, x_2, x1, x2,rj1,rj2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	double D=b*b-4*a*c;
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else{
		rj1=(-b-sqrt(D))/(2*a);
		rj2=(-b+sqrt(D))/(2*a);
		
		if(rj1>=rj2){
			x_1=rj2;
			x_2=rj1;
		}
		else{
			x_1=rj1;
			x_2=rj2;
		}
		do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if(fabs(x1-x_1)<EPSILON) printf("Tacno\n");
		else if(x1<x_1 && fabs(x_1-x1)<0.1) printf("Priblizno manje\n");
		else if(x1>x_1 && fabs(x1-x_1)<0.1) printf("Priblizno vece\n");
		else if(x1<x_1) printf("Manje\n");
		else if(x1>x_1) printf("Vece\n");
		} while(fabs(x1-x_1)>=EPSILON);
		do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if(fabs(x2-x_2)<EPSILON) printf("Tacno\n");
		else if(x2<x_2 && fabs(x_2-x2)<0.1) printf("Priblizno manje\n");
		else if(x2>x_2 && fabs(x2-x_2)<0.1) printf("Priblizno vece\n");
		else if(x2<x_2) printf("Manje\n");
		else if(x2>x_2) printf("Vece\n");
		} while(fabs(x2-x_2)>=EPSILON);
		
		
	}
	return 0;
}
