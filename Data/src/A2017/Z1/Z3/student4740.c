#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
	double a,b,c;
	double rj1,rj2,x1,x2,x,y,D;
	int brojac1=0,brojac2=0;
	
	/* unos i provjera vrijednosti */
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0) { printf ("Rjesenja su imaginarni brojevi."); 
		return 1;   }
		
	/* izracunavanje i redanje rjesenja po velicini, unos korisnikovih rjesenja */
	x=(-b+sqrt(D))/(2*a);
	y=(-b-sqrt(D))/(2*a);
	if (x<y) {x1=x; x2=y;}
	else if (y<x) {x1=y; x2=x;}
	else if (fabs(x-y)<epsilon) {x1=x; x2=y;}
	
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &rj1);
		if (fabs(rj1-x1)<epsilon){
			printf("Tacno\n"); brojac1=1; }
			else if (fabs(rj1-x1)<0.1 && rj1>x1)
				printf ("Priblizno vece\n");
				else if(fabs(rj1-x1)<0.1 && rj1<x1)
					printf ("Priblizno manje\n");	
					else if (rj1>x1) 
						printf("Vece\n"); 
						else if (x1>rj1) 
							printf("Manje\n"); 
	} while (brojac1!=1);
	
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &rj2);
		if (fabs(rj2-x2)<epsilon){
			printf("Tacno"); brojac2=1; }
			else if (fabs(rj2-x2)<0.1 && rj2>x2)
				printf ("Priblizno vece\n");
				else if(fabs(rj2-x2)<0.1 && rj2<x2)
					printf ("Priblizno manje\n");	
					else if (rj2>x2) 
						printf("Vece\n"); 
						else if (x2>rj2) 
							printf("Manje\n"); 
			} while (brojac2!=1);
	
	return 0;
}
