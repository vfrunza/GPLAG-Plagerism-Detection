#include <stdio.h>
#include <math.h>
#define E .001

int main() {
    double a, b, c, D, x1, x2, POKUSAJ=0;
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
        scanf("%lf", &POKUSAJ);
        if(fabs(x1-POKUSAJ)<E){
            printf("Tacno\n");
            tacno1=1;
        }
        else if(fabs(x1-POKUSAJ)<0.1 && x1<POKUSAJ)
            printf("Priblizno vece\n");
        else if(fabs(POKUSAJ-x1)<0.1 && x1>POKUSAJ)
            printf("Priblizno manje\n");
        else if(x1<POKUSAJ)
            printf("Vece\n");
        else
            printf("Manje\n");
    }
     tacno2 = 0;
    while(tacno2==0){
        
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &POKUSAJ);
        if(fabs(x2-POKUSAJ)<E){
            printf("Tacno\n");
            tacno2=1;
        }
        else if(fabs(x2-POKUSAJ)<0.1 && x2>POKUSAJ)
            printf("Priblizno manje\n");
        else if(fabs(POKUSAJ-x2)<0.1 && x2<POKUSAJ)
            printf("Priblizno vece\n");
        else if(x2<POKUSAJ)
            printf("Vece\n");
        else
            printf("Manje\n");
    }
    return 0;
}
	