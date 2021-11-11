#include <stdio.h>
#include <math.h>
#define EPSILON1 0.001
#define EPSILON2 0.1

int main() {
	double a, b, c, x1, x2, r1, r2, d, smjena;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	d=(b*b - 4*a*c);
	if(d<0) {
		printf("Rjesenja su imaginarni brojevi.");
	} else {
		r1=(0 - b - sqrt(d))/(2*a);
		r2=(0 - b + sqrt(d))/(2*a);
		if(r1>r2){
			smjena=r1;
			r1=r2;
			r2=smjena;
			
		}
		if(a>(-EPSILON1) && a<EPSILON1){
			r1=(-c)/b;
			r2=r1;
		}
		if(d>(-EPSILON1) && d<EPSILON1){
			r1=(-b)/(2*a);
			r2=r1;
		}
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
			if(fabs(x1-r1)<EPSILON1){
				printf("Tacno\n");
				break;
			} else {
				if(x1>r1 && (fabs(x1-r1)<EPSILON2)){
					printf("Priblizno vece\n");
				} 
				if(x1<r1 && (fabs(x1-r1)<EPSILON2)){
					printf("Priblizno manje\n");
				}
				if(x1>r1 && (fabs(x1-r1)>=EPSILON2)){
					printf("Vece\n");
				}
				if(x1<r1 && (fabs(x1-r1)>=EPSILON2)){
					printf("Manje\n");
				}
			}
		} while(fabs(x1-r1)>=EPSILON1);
			do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			if(fabs(x2-r2)<EPSILON1){
				printf("Tacno\n");
				break;
			} else {
				if(x2>r2 && (fabs(x2-r2)<EPSILON2)){
					printf("Priblizno vece\n");
				} 
				if(x2<r2 && (fabs(x2-r2)<EPSILON2)){
					printf("Priblizno manje\n");
				}
				if(x2>r2 && (fabs(x2-r2)>=EPSILON2)){
					printf("Vece\n");
				}
				if(x2<r2 && (fabs(x2-r2)>=EPSILON2)){
					printf("Manje\n");
				}
			}
		} while(fabs(x2-r2)>=EPSILON1);
	}
	return 0;
}
