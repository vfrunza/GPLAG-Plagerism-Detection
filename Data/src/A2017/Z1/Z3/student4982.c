#include <stdio.h>
#include <math.h>

#define e1 0.001
#define e2 0.1

int main() {
	double a,b,c,x1,x2,i,j;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

if((b*b-4*a*c)<0) { 
	printf("Rjesenja su imaginarni brojevi.");
	return 1; }

 x1 = (b*(-1) + sqrt(b*b-4*a*c))/(2*a);
 x2 = (b*(-1) - sqrt(b*b-4*a*c))/(2*a);
 
 // printf("%g \n", x1);
	
 // printf("%g \n", x2);

while(1){
  printf("Unesite rjesenje x1: ");
	scanf("%lf", &i);
	if(i == x1) {
		printf("Tacno");
		break;
	} else if (fabs(x1-i)<e1) {
		printf("Tacno\n"); break;
	} else if (i>x1 && fabs(i-x1)<e2) {
		printf("Priblizno vece\n");
	} else if (i<x1 && fabs(i-x1)<e2) {
	    printf("Priblizno manje\n");
	} else if (i > x1) {
		printf("Vece\n");
	} else if (i < x1) {
		printf("Manje\n");
	}
	} printf("\n");
while(1){
  printf("Unesite rjesenje x2: ");
	scanf("%lf", &j);
	if(j == x2) {
		printf("Tacno");
		break;
	} else if (fabs(x2-j)<e1) {
		printf("Tacno\n"); break;
	} else if (j>x2 && fabs(j-x2)<e2) {
		printf("Priblizno vece\n");
	} else if (j<x2 && fabs(j-x2)<e2) {
	    printf("Priblizno manje\n");
	} else if (j > x2) {
		printf("Vece\n");
	} else if (j < x2) {
		printf("Manje\n");
	} 
	} printf("\n");
	return 0;
}

	





	
