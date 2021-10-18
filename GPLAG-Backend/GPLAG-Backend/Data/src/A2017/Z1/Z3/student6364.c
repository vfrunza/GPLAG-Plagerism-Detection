#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, x1, x1t, x2, x2t, D, r1, r2;
    double e=0.001;
    
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D=(b*b)-4*a*c;
    
    if(D < 0){
        printf("Rjesenja su imaginarni brojevi.");
    return 0;
    } else {
        x1t=(-b+(sqrt(D)))/(2*a);
        
        do {
                printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1);
            
            r1=x1-x1t;
            if(r1<0) r1= r1* (-1);
            if(r1<e) 
            {
                printf("Tacno \n");
                    break;
              
            
                 } else {
                            if(r1<=0.1){
                            if(x1<x1t) printf("Priblizno manje\n");
                                    else printf("Priblizno vece\n");
                    }
                    else if(x1t<x1) printf("Vece\n");
                    else if(x1<x1t) printf("Manje\n");
                    }
         }while(r1>e);
        

    
        x2t=(-b-(sqrt(D)))/(2*a);
        
       do {
           printf("\nUnesite rjesenje x2: ");
       scanf("%lf", &x2);
       
        r2=x2t-x2;
        if(r2<0) r2*= -1;
            if(r2<e)  {
                printf("Tacno"); 
                break;
                } else {
                     if(r2<=0.1) {
                    if(x2<x2t) printf("Priblizno manje\n");
                    else printf("Priblizno vece\n");
                        }
                     else if(x2t<x2) printf("Vece\n");
                     else if(x2<x2t) printf("Manje\n"); 
       
            }        
        }while(r2>e);
        
    }
    
    return 0;
}