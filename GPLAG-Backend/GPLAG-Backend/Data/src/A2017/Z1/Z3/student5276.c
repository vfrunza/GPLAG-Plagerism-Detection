#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define E 0.1

int main() {
	double a, b, c, xp, xv;
	double D=0, x1=0, x2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	D=(pow(b,2)-4.0*a*c);
	x2=(-b+sqrt(pow(b,2)-4.0*a*c))/(2.*a);
    x1=(-b-sqrt(pow(b,2)-4.0*a*c))/(2.*a);
	if(0>D){ 
		printf("Rjesenja su imaginarni brojevi.");
return 1;}
//sigurno radi
    do { printf("Unesite rjesenje x1: ");
    scanf("%lf",&xp);//unos prvog pogadjanja
    
     if (xp-x1<=-E) //E=0.1
    	printf("Manje\n"); //da li je manje
    if (xp-x1>=E) 
    printf("Vece\n");//da li je vece
    
    if ((xp-x1>=EPSILON) && (xp-x1<E)) {
    	printf("Priblizno vece\n");
    } 
    else if((xp-x1>-E) && (xp-x1<=-EPSILON)) {
    	printf("Priblizno manje\n");
    }
   
    	
    } while ((fabs(xp-x1)>=EPSILON));
    if (fabs(xp-x1)<EPSILON)
    printf("Tacno\n");
    
    do { printf("Unesite rjesenje x2: ");
    scanf("%lf",&xv); //unos drugog pogadjanja
    
    if (xv-x2<=-E)
    	printf("Manje\n");
    if (xv-x2>=E) 
    printf("Vece\n");
    if ((xv-x2>=EPSILON) && (xv-x2<E)) {
    	printf("Priblizno vece\n");
    } 
    else if((xv-x2>-E) && (xv-x2<=-EPSILON)) {
    	printf("Priblizno manje\n");
    }
    
    
    	
    } while ((fabs(xv-x2)>=EPSILON));//bez beskonačne
    if (fabs(xv-x2)<EPSILON)
    printf("Tacno\n");
    
	return 0;
		
	}
