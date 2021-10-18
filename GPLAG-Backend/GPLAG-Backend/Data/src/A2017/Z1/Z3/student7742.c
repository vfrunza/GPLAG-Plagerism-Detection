#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define epsilon 0.001
int main ()
{
    double a,b,c,D,x1,x2,rjesenje1,rjesenje2;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%f %f %f", &a,&b,&c);
    D=b*b-4*a*c;
     rjesenje1=(-b-sqrt(D))/(2*a);
     rjesenje2=(-b+sqrt(D))/(2*a);
    if(D<0) {
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    } 
          do{
              printf("Unesite rjesenje x1: ");
              scanf("%f", &x1);
            if(abs(rjesenje1-x1)<epsilon) {
              printf("Tacno");
              break;
            }
           else  if(abs((x2-rjesenje2)<0.1 && (x2<rjesenje2))) {
                printf("Priblizno manje");
            } else {
                printf("Manje");
            }
          }while(1); 
          /*
        do {
            printf("\nUnesite rjesenje x2: ");
            scanf("%f", &x2);
                if(x2<rjesenje2) {
                  printf("Manje");
              } else if(x2>rjesenje2) {
                  printf("Vece");
              }  else if(abs(x2-rjesenje2)<0.1) {
                  printf("Priblizno manje");
              } else if(abs(x2-rjesenje2)>0.1) {
                  printf("Priblizno vece");
              } else if(abs(rjesenje2-x2)<epsilon) {
                  printf("Tacno");
                  break;
                            
          }while(1);  
        */
    
    return 0;
}