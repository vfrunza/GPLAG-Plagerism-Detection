#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, x1, x2, D, rezultat, p;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=pow(b,2)-4*a*c;
	if (D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	x1=(-b-sqrt(D))/(2*a);
	x2=(-b+sqrt(D))/(2*a);
	if (x1>x2){
		p=x1;
		x1=x2;
		x2=p;
	}
	
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &rezultat);
		
		if (fabs(x1-rezultat)<EPSILON){
			printf("Tacno\n");
		}
		else if (x1>rezultat){
			if(x1-rezultat<0.1){
				printf("Priblizno manje\n");
			}
			else{
					printf("Manje\n");
			}
		}
		else if (x1<rezultat){
			if(rezultat-x1<0.1){
				printf("Priblizno vece\n");
			}
			else{
					printf("Vece\n");
			}
		}
		
	} while(fabs(rezultat-x1)>=EPSILON);
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &rezultat);
		
		if (fabs(x2-rezultat)<EPSILON){
			printf("Tacno\n");
		}
		else if (x2>rezultat){
			if(fabs(x2-rezultat)<0.1){
				printf("Priblizno manje\n");
			}
			else {
					printf("Manje\n");
			}
		}
		else if (x2<rezultat){
			if(fabs(rezultat-x2)<0.1){
				printf("Priblizno vece\n");
			}
			else{
					printf("Vece\n");
			}
		}
	} while(fabs(rezultat-x2)>=EPSILON);
	return 0;
}
