#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
    double a,b,c;
    double D;
    double n; 
    double x1,x2;
    
     printf("Unesite koeficijente a, b i c: ");
        scanf("%lf %lf %lf", &a, &b, &c); 
    
        D=b*b-4*a*c;
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
        
    if(D<0){
    printf("Rjesenja su imaginarni brojevi.");
    return 0;
    }
    
    do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &n);
        if (fabs(n-x1)<eps) printf("Tacno\n");
        else if ((n-x1)>=0.1) printf("Vece\n");
        else if ((x1-n)>=0.1) printf("Manje\n");
        else if (fabs(n-x1)<0.1 && n>x1) printf("Priblizno vece\n");
        else printf("Priblizno manje\n");
    }
    while (fabs(n-x1)>=eps);
    
    do{
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &n);
        if (fabs(n-x2)<eps) printf("Tacno\n");
        else if ((n-x2)>=0.1) printf("Vece\n");
        else if ((x2-n)>=0.1) printf("Manje\n");
        else if (fabs(n-x2)<0.1 && n>x2) printf("Priblizno vece\n");
        else printf("Priblizno manje\n");
    }
    while (fabs(n-x2)>=eps);
    
	return 0;
}

