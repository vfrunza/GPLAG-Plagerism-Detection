#include <stdio.h>
#include <math.h>

#define eps 0.001 

int main() {
	int a, b, c;
	double x1, x2, d=0, temp, korisnickiX1, korisnickiX2;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%d %d %d", &a, &b, &c);
	if (a == 0) return 0; 


	temp = (pow(b,2)  - 4 * a * c);
	if (temp < 0) {
		printf ("Rjesenja su imaginarni brojevi.\n");
		return 0;
	}
	d = sqrt(temp);
//	printf ("%g", temp);
	x1 = (b*(-1) + d) / (2*a);
//	printf ("%g", x1);
	x2 = (b*(-1) - d) / (2*a);
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf ("%lf", &korisnickiX1);


	if(fabs (korisnickiX1 - x1)<eps){
		
	 printf("Tacno\n");
	 break; 
	}
	
	if(korisnickiX1<x1){
		if(fabs(korisnickiX1-x1)<0.1) printf("Priblizno manje\n");
		else printf("Manje\n");
	}
	if(korisnickiX1>x1){
		if(fabs(korisnickiX1-x1)>=eps && (fabs(korisnickiX1-x1)<0.1)) printf("Priblizno vece\n");
		else printf("Vece\n");
	}
		
	} while (fabs(korisnickiX1 - x1) >= eps);
	
	do {
		printf ("Unesite rjesenje x2: ");
		scanf ("%lf", &korisnickiX2);
		if (fabs(korisnickiX2 - x2) <= eps) {
			printf ("Tacno\n");
			break;
		}
		 if (korisnickiX2 < x2) {
		 	if(fabs(korisnickiX2-x2)<0.1) printf ("Priblizno manje\n");
		else printf ("Manje\n");
	}
	if(korisnickiX2>x2){
		if((fabs(korisnickiX2-x2) >= eps) && (fabs(korisnickiX2-x2)<0.1)) printf("Priblizno vece\n");
		else printf("Vece\n");
	}
	}
	while (fabs(korisnickiX2 - x2) >= eps);
	return 0;
}
