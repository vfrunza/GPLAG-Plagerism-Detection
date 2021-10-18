#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	double a,b,c,D,x1,x2,pom,pom2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D=b*b-4*a*c;
	
	if(D<0) { printf("Rjesenja su imaginarni brojevi."); return 0; }
	
	x1=(-b - sqrt(D))/(2*a);
	x2=(-b + sqrt(D))/(2*a);

	if(x1>x2) {pom2=x1; x1=x2; x2=pom2; } /* moramo znati koji je manji a koji veci jer x1 mora uvijek biti manji... */
	
	for(;;){ /* beskoncna for petlja koja ide sve dok se uslov za tacno ne ispuni kada izlazimo iz petlje */
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &pom);
	if( fabs(pom-x1)<EPSILON ){printf("Tacno\n"); break;}
	else if(pom<x1 && pom-x1>-0.1){printf("Priblizno manje\n");}
	else if(pom>x1 && pom-x1<0.1){printf("Priblizno vece\n");}
	else if(pom<x1){printf("Manje\n");}
	else if(pom>x1){ printf("Vece\n");}	
	}
	
	for(;;){ 
	printf("Unesite rjesenje x2: ");
	scanf("%lf", &pom);
	if( fabs(pom-x2)<EPSILON ){printf("Tacno\n"); break;}
	else if(pom<x2 && pom-x2>-0.1){printf("Priblizno manje\n");}
	else if(pom>x2 && pom-x2<0.1){printf("Priblizno vece\n");}
	else if(pom<x2){printf("Manje\n");}
	else if(pom>x2){ printf("Vece\n");}	
	}
	return 0;
	}
	