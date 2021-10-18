#include <stdio.h>
#define EPSILON 0.001
#include <math.h>

int main() {
	double a,b,c,x1,x2,u1,u2;
	int done=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if((b*b - 4*a*c)<0) { printf("Rjesenja su imaginarni brojevi.");
	return 0;
}
else {
	x1=-b + sqrt(b*b - 4*a*c)/2*a;
	x2=-b - sqrt(b*b -4*a*c)/2*a;
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &u1);
		while(done!=0) {
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
	
	if(fabs(u1-x1)<EPSILON|| EPSILON-fabs(u1-x1)<EPSILON)   {
	printf ("Tacno"); }
	else if(fabs(u1-x1)>EPSILON) printf("Vece"); 
	else printf("Manje"); 
}
	
	printf("\nUnesite rjesenje x2: ");
	scanf("lf", &u2);
	while(done!=0) {
	printf("\nUnesite rjesenje x2: ");
	scanf("%lf", &u2);
	if(fabs(u2-x2)<EPSILON|| EPSILON-fabs(u2-x2)<EPSILON) {
	printf("Tacno"); }
	else if(fabs(u2-x2)>EPSILON) printf("Vece"); 
		else printf("Manje");
}

	return 0;
} }
