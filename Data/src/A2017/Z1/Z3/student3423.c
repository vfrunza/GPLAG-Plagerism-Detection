#include <stdio.h>
#include <math.h>
#define E 0.001
#define E1 0.1

int main() {
	
	double a,b,c;
	double D;
	double x2,x1,x;
	double r1,r2;
	
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (b*b-4*a*c+E<0){
	    printf("Rjesenja su imaginarni brojevi.");
	    return 0;
	} else {
	
	D=sqrt(b*b-4*a*c);
	x1=(-b-D)/(2*a);
	x2=(-b+D)/(2*a);
	    
	    if (x2<x1){
	        x=x1;
	        x1=x2;
	        x2=x;
	    }
	    
    do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &r1);
        if (fabs(r1-x1)<E) printf("Tacno\n");
        else if (fabs(r1-x1)<E1 && x1>r1) printf("Priblizno manje\n");
        else if (fabs(r1-x1)<E1 && x1<r1) printf("Priblizno vece\n");
        else if (r1<x1) printf("Manje\n");
        else if (r1>x1) printf("Vece\n");
    } while (fabs(r1-x1)>=E);
    
    do{
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &r2);
        if (fabs(r2-x2)<E) printf("Tacno\n");
        else if (fabs(r2-x2)<E1 && x2>r2) printf("Priblizno manje\n");
        else if (fabs(r2-x2)<E1 && x2<r2) printf("Priblizno vece\n");
        else if (r2<x2) printf("Manje\n");
        else if (r2>x2) printf("Vece\n");
    } while (fabs(r2-x2)>=E);
    
	}
	
	return 0;
}
