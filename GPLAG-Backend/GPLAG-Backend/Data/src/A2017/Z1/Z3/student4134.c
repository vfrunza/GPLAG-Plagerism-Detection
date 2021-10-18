#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
    double a, b, c, x1, x2, D, x,z;
    
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(fabs(a)<e) printf("Lineana jednacina\n");
    else {
        D = b * b - 4 * a * c;
        if(D<0) printf("Rjesenja su imaginarni brojevi.\n");
        
        else {
            
            x1=(-b-sqrt(D))/(2*a);
            x2=(-b+sqrt(D))/(2*a);
            if(x2<x1){
                z=x1;
                x1=x2;
                x2=z;
            }
          
            
            do{
        
            
                printf("Unesite rjesenje x1: ");
                scanf("%lf",&x);
                
                if(fabs(x-x1)<e){ printf("Tacno\n");
                break;}
                
                if(x<x1){
                    if(fabs(x-x1)<0.1) printf("Priblizno manje\n");
                    else printf("Manje\n");
                } else {
                 if(fabs(x-x1)<0.1) printf("Priblizno vece\n");
                 else printf("Vece\n"); }
            } while(1);
            do{
        
                
                printf("Unesite rjesenje x2: ");
                scanf("%lf",&x);
                
                if(fabs(x-x2)<=e){ printf("Tacno\n");
                break;}
                
                if(x<x2){
                    if(fabs(x-x2)<0.1) printf("Priblizno manje\n");
                    else printf("Manje\n");
                } else {
                 if(fabs(x-x2)<0.1) printf("Priblizno vece\n");
                 else printf("Vece\n"); }
            } while(1);
        } 
    }
    return 0;
}


        