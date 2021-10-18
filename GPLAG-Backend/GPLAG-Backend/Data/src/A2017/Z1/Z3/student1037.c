#include <stdio.h>
#include <math.h>
#define E .001

int main() {
    double a, b, c, D, x1, x2, pokusaj=0;
    int tacno1, tacno2;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    D=(b*b)-(4*a*c);
    if(D<0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    else if(D>=0)
    {
        
        x1=(-b+sqrt(D))/(2.*a);
        x2=(-b-sqrt(D))/(2.*a);
    }
    tacno1=0;
    while(tacno1==0){
        
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &pokusaj);
        if(fabs(x1-pokusaj)<E){
            printf("Tacno\n");
            tacno1=1;
        }
        else if(fabs(x1-pokusaj)<0.1 && x1<pokusaj)
            printf("Priblizno vece\n");
        else if(fabs(pokusaj-x1)<0.1 && x1>pokusaj)
            printf("Priblizno manje\n");
        else if(x1<pokusaj)
            printf("Vece\n");
        else
            printf("Manje\n");
    }
     tacno2 = 0;
    while(tacno2==0){
        
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &pokusaj);
        if(fabs(x2-pokusaj)<E){
            printf("Tacno\n");
            tacno2=1;
        }
        else if(fabs(x2-pokusaj)<0.1 && x2>pokusaj)
            printf("Priblizno manje\n");
        else if(fabs(pokusaj-x2)<0.1 && x2<pokusaj)
            printf("Priblizno vece\n");
        else if(x2<pokusaj)
            printf("Vece\n");
        else
            printf("Manje\n");
    }
    return 0;
}