#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
    
    double a, b, c, D, t, x1, x2, x1t, x2t;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D=b*b-4.0*a*c;

    
    if (D<0) { printf("Rjesenja su imaginarni brojevi.");
    return 0;
    } else {
        
      t=sqrt(D);
      x1t=(-b+t)/(2*a);
      x2t=(-b-t)/(2*a);
        
    do{
      printf("Unesite rjesenje x1: ");
      scanf("%lf", &x1);
      
      
        if (fabs(x1-x1t)<eps) {
            printf("Tacno\n");
            break;
        }
        
        else if(fabs(x1-x1t)<0.1 && x1<x1t) printf("Priblizno manje\n");
        else if(fabs(x1-x1t)<0.1 && x1>x1t) printf("Priblizno vece\n");
        else if(fabs(x1-x1t)>eps && x1<x1t) printf("Manje\n");
        else if(fabs(x1-x1t)>eps && x1>x1t) printf("Vece\n");
    } while(1);
    
    do{
    printf("Unesite rjesenje x2: ");
    scanf("%lf", &x2);
    
    if (fabs(x2-x2t)<eps){ 
        printf("Tacno\n");
        break;
    }
     else if(fabs(x2-x2t)<0.1 && x2<x2t) printf("Priblizno manje\n");
    else if(fabs(x2-x2t)<0.1 && x2>x2t) printf("Priblizno vece\n");
    else if(fabs(x2-x2t)>eps && x2<x2t) printf("Manje\n");
    else if(fabs(x2-x2t)>eps && x2>x2t) printf("Vece\n");
    

    }while (1);
    }
    return 0;
}
    
    
 
      