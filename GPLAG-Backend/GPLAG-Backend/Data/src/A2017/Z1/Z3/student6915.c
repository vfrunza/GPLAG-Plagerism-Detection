#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a, b, c, D, KD, x1, x2, kx1, kx2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	D=b*b-4*a*c;

	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
	else if(D>=0){
		KD = sqrt(D);
		x1=(-b-KD)/(2*a);
		x2=(-b+KD)/(2*a);
		double temp;
		if(x1>x2) {
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &kx1);
			if(fabs(x1-kx1)<EPSILON){
				printf("Tacno\n");
			} else if(((x1-kx1)>-0.1) && ((x1-kx1)<0)){
				printf("Priblizno vece\n");
			} else if(((x1-kx1)<0.1) && ((x1-kx1)>0)){
				printf("Priblizno manje\n");
			} else if((kx1>x1) && (fabs(x1-kx1)>EPSILON) && (fabs(x1-kx1)>0.1)){
				printf("Vece\n");
			} else printf("Manje\n");
		} while(fabs(x1-kx1)>EPSILON);
		
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &kx2);
			if(fabs(x2-kx2)<EPSILON){
				printf("Tacno\n");
			} else if(((x2-kx2)>-0.1) && ((x2-kx2)<0)){
				printf("Priblizno vece\n");
			} else if(((x2-kx2)<0.1) && ((x2-kx2)>0)){
				printf("Priblizno manje\n");
			} else if((kx2>x2) && (fabs(x2-kx2)>EPSILON) && (fabs(x2-kx2)>0.1)){
				printf("Vece\n");
			} else printf("Manje\n");
		} while(fabs(x2-kx2)>EPSILON);
	}
	return 0;
}
