
#include <stdio.h>
#include<math.h>
#define epsilon 0.001
int main() {
    double a,b,c,d;
    double x1,x2,x11,x22,pom;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    d= (b*b)-(4*a*c);
    
    if( d < 0){
        printf("Rjesenja su imaginarni brojevi.\n");
        return 0;
    }
 
    x11=(-b+sqrt(d))/(2*a);
   
    x22=(-b-sqrt(d))/(2*a);
  
 
    if(x11 > x22){
       pom=x11;
       x11=x22;
       x22=pom;
    }
    
    
    
     while(1==1)
    {
        printf("Unesite rjesenje x1: ");
        scanf("%lf",&x1);
     
    if(fabs(x11-x1) < epsilon) {
        printf("Tacno\n");
        break;
    }
     else if( fabs(x1- x11) > -0.1 && fabs(x1-x11) != 0 && fabs(x11-x1)<0.1 && fabs(x11-x1)>epsilon && x1<x11){
        printf("Priblizno manje\n");
      }
    else if(fabs(x1-x11)>=epsilon && fabs(x11-x1)> -0.1 && fabs(x11-x1)< 0.1 && fabs(x11-x1) !=0 && x1>x11 ){
        printf("Priblizno vece\n");
    }
     else if(fabs(x11-x1) > epsilon && x1<x11 ){
        printf("Manje\n");
     }
    else if(fabs(x11-x1) > epsilon  && x1>x11  ){
        printf("Vece\n");
    }
        
    }
      
    
 while(1==1){
     printf("Unesite rjesenje x2: ");
     scanf("%lf",&x2);
     
      if(fabs(x2-x22)<epsilon){
        printf("Tacno\n");
       break;
        }
      else if(fabs(x22-x2)>-0.1  && fabs(x22-x2) !=0 && fabs(x22-x2)<0.1 && fabs(x22-x2)>epsilon && x2<x22 ) {
        printf("Priblizno manje\n");
     }
    else if(fabs(x22-x2)>-0.1  &&  fabs(x22-x2) !=0 && fabs(x22-x2)<0.1 && fabs(x22-x2)>epsilon && x2>x22 && fabs(x2-x22)>epsilon){
        printf("Priblizno vece\n");
    }
    
      else if( x2< x22 && fabs(x2-x22)> epsilon){
        printf("Manje\n");
      }
    
    else if(x2 > x22 && fabs(x2-x22)> epsilon){
        printf("Vece\n");
        
    }
   
}
	return 0;
}

