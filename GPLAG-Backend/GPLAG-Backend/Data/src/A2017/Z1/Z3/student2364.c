#include <stdio.h>
#include <math.h>
#define epsilon 0.001
#define razlika 0.1

int main() {
    double a,b,c,x1,x2,x1re,x2re,D,t;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    D=b*b-4.0*a*c;
    if(D<0) {
        printf("Rjesenja su imaginarni brojevi.");
    }  
     t=sqrt(D);
     x1re=(-b-t)/(2*a);
     x2re=(-b+t)/(2*a);
    
    if(D>=0) {
        do {
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1); 
            if(fabs(x1-x1re)<epsilon) {
                printf("Tacno\n");
                break;
            }
            if(x1>x1re && fabs(x1-x1re)<razlika) {
                printf("Priblizno vece\n");
            }
                
        if((x1<x1re) && fabs(x1re-x1)>=razlika) {
         printf("Manje\n");
         }
         
        if(x1>x1re && (fabs(x1-x1re)>=razlika)) {
         printf("Vece\n");
         }
         if((x1<x1re) && fabs(x1re-x1)<razlika){
             printf("Priblizno manje\n");
         }
         
        } while(1);
          
           
         
         do{
          printf("\nUnesite rjesenje x2: ");
          scanf("%lf",&x2);
          if(fabs(x2-x2re)<epsilon){
              printf("Tacno\n");
              break;
          }
          
          if((x2<x2re) && fabs(x2re-x2)>=razlika) {
              printf("Manje\n");
          }
          
          if(x2>x2re && (fabs(x2-x2re)>=razlika)) {
              printf("Vece\n");
          }
           if((x2>x2re) && fabs(x2re-x2)<razlika){
             printf("Priblizno vece\n");
         }
          if((x2<x2re) && fabs(x2re-x2)<razlika){
             printf("Priblizno manje\n");
         }
         
           
         }  while(1);
         
          
     }      
    
	
	return 0;
}
