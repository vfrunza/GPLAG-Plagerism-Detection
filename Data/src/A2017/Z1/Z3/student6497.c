#include <stdio.h>
#include <math.h>
#define E 0.001
#define P 0.1

int main() {
	/* Unos */
	double a, b, c, p;
	int t;
	do{
		printf("Unesite koeficijente a, b i c: ");
		scanf("%lf %lf %lf", &a, &b, &c);
	} while (a==0);
	/* Racunamo determinantu da vidimo da li su rjesenja imaginarna ili realna */
	double D;
	D=b*b-4*a*c;
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else{
		double x1, x2, x1a, x2a;
			x1a=(-b-sqrt(D))/(2*a);
			x2a=(-b+sqrt(D))/(2*a);
			if(x1a<=x2a){
				x1=x1a;
				x2=x2a;
			}
			else{
				x1=x2a;
				x2=x1a;
			}
		/* Korisnik pogada x1 */
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf", &p);
			if(fabs(x1-p)<E){
				printf("Tacno\n");
				t=1;
			}
			else if(fabs(x1-p)<P){
				if(p<x1) printf("Priblizno manje\n");
				else printf("Priblizno vece\n");
				t=0;
			}
			else{
				if(p<x1) printf("Manje\n");
				else printf("Vece\n");
				t=0;
			}
		} while(t!=1);
		/* Korisnik pogada x2 */
		do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf", &p);
			if(fabs(x2-p)<E){
				printf("Tacno\n");
				t=1;
			}
			else if(fabs(x2-p)<P){
				if(p>x2) printf("Priblizno vece\n");
				else printf("Priblizno manje\n");
				t=0;
			}
			else{
				if(p>x2) printf("Vece\n");
				else printf("Manje\n");
				t=0;
			}
		} while(t!=1);
	}
	return 0;
}
