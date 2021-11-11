#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define EPSILONN 0.1

int main() {
	double a,b,c,p1,p2;
	double D,rj1,rj2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	D=(b*b)-(4*a*c);
	rj1=(-b+D)/(2*a);
	rj2=(-b-D)/(2*a);
	if (D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	} else {
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &p1);
			
			if (fabs(p1-rj1)<EPSILON) {
				printf("Tacno");
				break;
			}
			else if (p1-rj1>EPSILON) {
				if (p1>rj1 && fabs(p1-rj1)<EPSILONN) {
					printf("Priblizno vece\n");
				} else if (fabs(rj1-p1)>EPSILON) {
					printf("Vece\n");
				}
			} else { 
					if(p1<rj1 && fabs(p1-rj1)<EPSILONN) {
					printf("Priblizno manje\n");
					} else if (fabs(p1-rj1)>EPSILON) {
						printf("Manje\n");
				}
			}
				
		} while (fabs(rj1-p1)>EPSILON);

	do {
		printf("\nUnesite rjesenje x2: ");
		scanf("%lf", &p2);
			if (fabs(p2-rj2)<EPSILON) {
				printf("Tacno");
				break;
			}
	
			else if (p2-rj2>EPSILON) {
			if (p2>rj2 && fabs(p2-rj2)<EPSILONN) {
				printf("Prliblizno vece");
			} else if (fabs(p2-rj2)>EPSILON) {
				printf("Vece");
			} 
		} else {
			if(p2>rj2 && fabs(p2-rj2)<EPSILONN) {
				printf("Prliblizno manje");
			}else if (fabs(p2-rj2)>EPSILON) {
				printf("Manje");
			} 
		}
	} while (fabs(p2-rj2)>EPSILON);
	}
	return 0;
}
