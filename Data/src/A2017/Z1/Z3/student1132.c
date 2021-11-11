#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 0.001


int main() {
	double a, b, c, x1, x2, rj1, rj2, odnos1, odnos2, det, manjerj, vecerj;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	det=pow(b,2)-4*a*c;
	if (det<0)
		printf("Rjesenja su imaginarni brojevi.");
	else {
		rj1=((-1)*b-sqrt(det))/(2*a);
		rj2=((-1)*b+sqrt(det))/(2*a);
		
		if (rj1>=rj2) {
			vecerj=rj1;
			manjerj=rj2;
		}
		else {
			manjerj=rj1;
			vecerj=rj2;
		}
		
		do {
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &x1);
			
			odnos1=fabs(x1-manjerj);
			
			if (odnos1>=0.1 && x1>manjerj)
				printf("Vece\n");
			else if (odnos1>=epsilon && x1>manjerj)
				printf("Priblizno vece\n");
			else if (odnos1>=0.1 && x1<manjerj)
				printf("Manje\n");
			else if (odnos1>=epsilon && x1<manjerj)
				printf("Priblizno manje\n");
			else 
				printf("Tacno\n");
		} while (odnos1>=epsilon);
		
		do {
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &x2);
			
			odnos2=fabs(x2-vecerj);
			
			if (odnos2>=0.1 && x2>vecerj)
				printf("Vece\n");
			else if (odnos2>=epsilon && x2>vecerj)
				printf("Priblizno vece\n");
			else if (odnos2>=0.1 && x2<vecerj)
				printf("Manje\n");
			else if (odnos2>=epsilon && x2<vecerj)
				printf("Priblizno manje\n");
			else 
				printf("Tacno");
		} while (odnos2>=epsilon);
	}
	return 0;
}
