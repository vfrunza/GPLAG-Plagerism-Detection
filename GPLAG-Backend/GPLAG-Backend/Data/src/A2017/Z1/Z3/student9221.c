#include <stdio.h>
#include <math.h>
int main(){
    double epsilon=0.001;
    double a;
    double b;
    double c;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    double d;
    d=b*b-4*a*c;
    if (d<0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    d=sqrt(d);
    double x1;
    double x2;
    x1=(-b+d)/(2*a);
    x2=(-b-d)/(2*a);
    double pomocni;
    if(x1>x2){
        pomocni=x1;
        x1=x2;
        x2=pomocni;
    }
    double unos1;
    double unos2;
    do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf",&unos1);
        if(fabs(unos1-x1)<epsilon){
            printf("Tacno\n");
            break;
        }
        if(fabs(unos1-x1)<0.1 && unos1>x1){
            printf("Priblizno vece\n");
            continue;
        }
        if ( fabs(x1-unos1)<0.1 && x1>unos1){
            printf("Priblizno manje\n");
            continue;
        }
        if(unos1>x1){
            printf("Vece\n");
            continue;
        }
        if(unos1<x1){
            printf("Manje\n");
            continue;
        }
    } while(1);
    do{
        printf("Unesite rjesenje x2: ");
        scanf("%lf",&unos2);
        if(fabs(unos2-x2)<epsilon){
            printf("Tacno\n");
            break;
        }
        if(fabs(unos2-x2)<0.1 && x2<unos2){
            printf("Priblizno vece\n");
            continue;
        }
        if(fabs(unos2-x2)<0.1 && x2>unos2){
            printf("Priblizno manje\n");
            continue;
        }
        if(unos2>x2){
            printf("Vece\n");
            continue;
        }
        if(unos2<x2){
            printf("Manje\n");
            continue;
        }
    }while(1);
    return 0;
}