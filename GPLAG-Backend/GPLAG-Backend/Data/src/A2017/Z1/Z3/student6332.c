#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
    double a,b,c,D,R1,R2,pomocna=0,X1,X2;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a,&b,&c);
    D=b*b-(4*a*c);
    if(D<0){
            printf("Rjesenja su imaginarni brojevi.");
            return 0;
           }
            
    
    if(D==0) {
            R1=-b/(2*a);
            R2=R1;
            }
    else if(D>0){
            R1=-b+sqrt(D);
            R2=b+sqrt(D);
    }
  
    if(R2<R1){
              pomocna=R1;
              R1=R2;
              R2=pomocna;
              }
     
    
    do{
       printf("Unesite rjesenje x1: ");
       scanf("%lf",&X1);
       if(fabs(X1)+EPSILON==R1) {printf("Tacno\n");break;}
       if(fabs(fabs(X1)-fabs(R1)>0.0001 && fabs(fabs(X1)-fabs(R1))<=0.05))printf("Priblizno vece\n");
       else if (fabs(fabs(X1)-fabs(R1))>0.05 && fabs(fabs(X1)-fabs(R1))<0.1)printf("Priblizno manje\n");
       else if(fabs(X1)+EPSILON==R1) printf("Tacno\n");
       else if(X1>R1) printf("Vece\n");
       else if(X1<R1 ) printf("Manje\n");
       
       
       
       }while(X1!=R1);
       if(X1==R1) printf("Tacno\n");
      
       
    do{
       printf("Unesite rjesenje x2: ");
       scanf("%lf",&X2);
       if(fabs(X2)+EPSILON==R2){printf("Tacno\n");break;}
       if(fabs(fabs(X2)-fabs(R2))>0.0001 && fabs(fabs(X2)-fabs(R2))<=0.05)printf("Priblizno vece\n");
       else if (fabs(fabs(X2)-fabs(R2))>0.05 && fabs(fabs(X2)-fabs(R2))<0.1)printf("Priblizno manje\n");
       else if(fabs(X2)+EPSILON==R2) printf("Tacno\n");
       else if(X2>R2) printf("Vece\n");
       else if(X2<R2 ) printf("Manje\n");
      
       
       
       }while(X2!=R2);
       if(X2==R2)printf("Tacno\n");
       
     return 0;
}
    
            


       
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
