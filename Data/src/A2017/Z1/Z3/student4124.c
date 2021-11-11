#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Alfa 0.1
#define EPSILON 0.001

int main() {
	double a, b, c, x1, x2, x11, x22, D, x, y, k;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-(4.0*a*c);
	k=sqrt(D);
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
	} else{
		if(a>0){
			x11=(-b+k)/(2*a);
			x22=(-b-k)/(2*a);
			do{
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1);
				if(((x1-x11)<0 || (x1-x11)>0) && (fabs(x1-x11))<Alfa && (fabs(x1-x11))>=EPSILON && x1<x11) {
					printf("Priblizno manje\n");
				} else if(((x1-x11)<0 || (x1-x11)>0) && (fabs(x1-x11))<Alfa && (fabs(x1-x11))>=EPSILON && (x1>x11)){
					printf("Priblizno vece\n");
				} else if((fabs(x11-x1))<EPSILON){
					printf("Tacno");
					break;
				} else if(x1<x11) {
					printf("Manje\n");
				} else if(x1>x11){
					printf("Vece\n");
				}
			} while(x1<x11 || x1>x11);
			do{
				printf("\nUnesite rjesenje x2: ");
				scanf("%lf", &x2);
				if(((x2-x22)<0 || (x2-x22)>0) && (fabs(x2-x22))<Alfa && (fabs(x2-x22))>=EPSILON && x2<x22) {
					printf("Priblizno manje\n");
				} else if(((x2-x22)<0 || (x2-x22)>0) && (fabs(x2-x22))<Alfa && (fabs(x2-x22))>=EPSILON && (x2>x22)){
					printf("Priblizno vece\n");
				} else if((fabs(x22-x2))<EPSILON){
					printf("Tacno");
					break;
				} else if(x2<x22) {
					printf("Manje\n");
				} else if(x2>x22){
					printf("Vece\n");
				}
			} while(x2<x22 || x2>x22);
		} else{
			x11=(-b+k)/(2*a);
			x22=(-b-k)/(2*a);
			do{
				printf("Unesite rjesenje x1: ");
				scanf("%lf", &x1);
				if(((x1-x11)<0 || (x1-x11)>0) && (fabs(x1-x11))<Alfa && (fabs(x1-x11))>=EPSILON && x1<x11) {
					printf("Priblizno manje\n");
				} else if(((x1-x11)<0 || (x1-x11)>0) && (fabs(x1-x11))<Alfa && (fabs(x1-x11))>=EPSILON && (x1>x11)){
					printf("Priblizno vece\n");
				} else if((fabs(x11-x1))<EPSILON){
					printf("Tacno");
					break;
				} else if(x1<x11) {
					printf("Manje\n");
				} else if(x1>x11){
					printf("Vece\n");
				}
			} while(x1<x11 || x1>x11);
			do{
				printf("\nUnesite rjesenje x2: ");
				scanf("%lf", &x2);
				if(((x2-x22)<0 || (x2-x22)>0) && (fabs(x2-x22))<Alfa && (fabs(x2-x22))>=EPSILON && x2<x22) {
					printf("Priblizno manje\n");
				} else if(((x2-x22)<0 || (x2-x22)>0) && (fabs(x2-x22))<Alfa && (fabs(x2-x22))>=EPSILON && (x2>x22)){
					printf("Priblizno vece\n");
				} else if((fabs(x22-x2))<EPSILON){
					printf("Tacno");
					break;
				} else if(x2<x22) {
					printf("Manje\n");
				} else if(x2>x22){
					printf("Vece\n");
				}
			} while(x2<x22 || x2>x22);
		}
	}
	return 0;
}