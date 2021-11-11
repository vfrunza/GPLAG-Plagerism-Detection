#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* x1-izracunato x, y1-uneseno x1, x2-izracunato, y2-uneseno x2 */

int main() {
	double a,b,c;
	double x1,y1;
	double x2,y2; 
	double D;
	double raz;
	double neg;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);


	D=b*b-4*a*c;
	if(D<0) { printf("Rjesenja su imaginarni brojevi."); return 0; }
	
	x1=(-b-sqrt(b*b-4*a*c))/(2*a); 
	x2=(-b+sqrt(b*b-4*a*c))/(2*a); 
	
	if(a<0)  {
		neg=x1;
		x1=x2;
		x2=neg;
	}
	

	
do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&y1);
		
		
		raz=y1-x1;
		if(y1<x1 && raz<=-0.1) printf("Manje\n");
		else if(y1<x1 && raz>-0.1 && (raz<=-0.001)) printf("Priblizno manje\n");
		else if(y1<x1 && raz>-0.001 || y1>x1 && raz<0.001 || y1==x1) printf("Tacno\n");
		else if(y1>x1 && raz>=0.001 && raz<0.1) printf("Priblizno vece\n");
		else printf("Vece\n");

	} while(raz<=-0.001 || raz>=0.001);

	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&y2);
		raz=y2-x2;
		if(y2<x2 && raz<=-0.1) printf("Manje\n");
		else if(y2<x2 && raz>-0.1 && (raz<=-0.001)) printf("Priblizno manje\n");
		else if(y2<x2 && raz>-0.001 || y2>x2 && raz<0.001 || y2==x2) printf("Tacno\n");
		else if(y2>x2 && raz>=0.001 && raz<0.1) printf("Priblizno vece\n");
		else printf("Vece\n");
		
	} while(raz<=-0.001 || raz>=0.001);

	return 0; }