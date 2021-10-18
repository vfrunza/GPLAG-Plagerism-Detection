#include <stdio.h>
#include <math.h>
#define E 0.001
#define E1 0.1

int main() {
	double a,b,c,x1,x2,D,rj1,rj2,z;
	printf ("Unesite koeficijente a, b i c: ");
	scanf ("%lf %lf %lf",&a,&b,&c);
	D=(b*b-4*a*c);
	if (D<0) {
	printf ("Rjesenja su imaginarni brojevi.");
	return 0; }
	x1=((-b+sqrt(D))/(2*a));
	x2=((-b-sqrt(D))/(2*a));
	if (x1>x2) {
	x1=z;
	z=x2;}
	
	do {
	printf ("Unesite rjesenje x1: ");
	scanf("%lf",&rj1); 
	if (fabs(rj1-x1)<E)  
	printf ("Tacno\n");
	else if ((rj1<x1) && fabs(rj1-x1)<E1)  
	printf ("Priblizno manje\n"); 
	else if ((rj1>x1) && fabs(rj1-x1)<E1) 
	printf ("Priblizno vece\n");
	else if (rj1<x1) 
	printf ("Manje\n"); 
	else if (rj1>x1)  
	printf ("Vece\n");}
	while (fabs(rj1-x1)>=E || fabs(rj1-x1)<=-E);

		do {
	printf ("Unesite rjesenje x2: ");
	scanf("%lf",&rj2); 
	if (fabs(rj2-x2)<E)  
	printf ("Tacno\n");
	else if ((rj2<x2) && fabs(rj2-x2)<E1)  
	printf ("Priblizno manje\n"); 
	else if ((rj2>x2) && fabs(rj2-x2)<E1) 
	printf ("Priblizno vece\n");
	else if (rj2<x2) 
	printf ("Manje\n"); 
	else if (rj2>x2)  
	printf ("Vece\n");}
	while (fabs(rj2-x2)>=E || fabs(rj2-x2)<=-E);
	
	return 0;
}
