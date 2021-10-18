#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
    int i;
double a,b,c,D,x1,x2,unos,ph;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a, &b, &c);
D=pow(b,2)-4*a*c;
x1=(-b-sqrt(D))/(2*a);
x2=(-b+sqrt(D))/(2*a);
if(x1>x2) {
    ph=x1;
    x1 = x2;
    x2=ph;
} 
if(D<0){
    printf("Rjesenja su imaginarni brojevi.");
} else {
    for(i=0;;i++) {
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &unos);
        if(unos-x1>=0.1) {
            printf("Vece\n");
        } else if(unos-x1<=-0.1){
            printf("Manje\n");
        } else if(unos-x1>-epsilon && unos-x1<epsilon) {
            printf("Tacno\n");
            break;
        } else if(unos-x1>-0.1 && unos -x1<=-epsilon) {
            printf("Priblizno manje\n");
        } else if(unos-x1>=epsilon && unos - x1 < 0.1) {
            printf("Priblizno vece\n");
        }
    }
    for(i=0;;i++) {
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &unos);
        if(unos-x2>=0.1) {
            printf("Vece\n");
        } else if(unos-x2<=-0.1){
            printf("Manje\n");
        } else if(unos-x2>-epsilon && unos-x2<epsilon) {
            printf("Tacno\n");
            break;
        } else if(unos-x2>-0.1 && unos -x2<=-epsilon) {
            printf("Priblizno manje\n");
        } else if(unos-x2>=epsilon && unos - x2 < 0.1) {
            printf("Priblizno vece\n");
        }
    }
    
}

	return 0;
}
