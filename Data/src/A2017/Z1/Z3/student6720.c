#include <stdio.h>
#include <math.h>
#define eps 0.001

int main(){
    double a, b, c, x1, x2, x1t, x2t, temp;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    x1=(-b-sqrt(b*b-(4.0*a*c)))/(2*a);
    x2=(-b+sqrt(b*b-(4.0*a*c)))/(2*a);
    if(x1>x2){
        temp=x1;
        x1=x2;
        x2=temp;
    }
    if((b*b-(4*a*c))<0){ 
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &x1t);
        if(fabs(x1t-x1)<eps){
            printf("Tacno\n");
            break;
        }
        else if((x1-x1t)>eps && (x1-x1t)<0.1) printf("Priblizno manje\n");
        else if((x1-x1t)<eps && (x1-x1t)>-0.1) printf("Priblizno vece\n");
        else if((x1t-x1)<eps) printf("Manje\n");
        else if((x1t-x1)>eps) printf("Vece\n");
        
    }while(fabs(x1-x1t)>=eps);
    do{
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &x2t);
        if(fabs(x2t-x2)<eps){ 
            printf("Tacno\n");
            break;
        }
        else if((x2-x2t)>eps && (x2-x2t)<0.1) printf("Priblizno manje\n");
        else if((x2-x2t)<eps && (x2-x2t)>-0.1) printf("Priblizno vece\n");
        else if((x2t-x2)<eps) printf("Manje\n");
        else if((x2t-x2>eps)) printf("Vece\n");
    }while(fabs(x2-x2t)>=eps);
    
    return 0;
    
}