#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
    
    int a,b,c;
    float r1,r2,x1,x2,D;
    
    printf("Unesite koeficijente a, b i c: ");
    scanf("%d %d %d",&a,&b,&c);
    
    if(b*b-4*a*c<0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;}
    
    D=sqrt(b*b-4*a*c);
    r1=(-b+D)/(2*a);
    r2=(-b-D)/(2*a);
    
   
    
    printf("Unesite rjesenje x1: ");
    scanf("%f",&x1);
    
 while(fabs(x1-r1)>EPSILON){
       
if(x1>r1 && (fabs(fabs(r1)-fabs(x1))>0.1 ||fabs(r1)-fabs(x1)==0) || (fabs(r1)+x1<0.01 && fabs(r1+x1)>0.1 && x1<0 && fabs(r1)<0.001 && fabs(x1)>0.11 && fabs(x1)<0.09))printf("Vece\n");
      else if(x1<r1 &&(fabs(fabs(x1)-fabs(r1))-0.1>=0.0001) ) printf("Manje\n");
      else if(fabs(r1)-fabs(x1)<0.1 && fabs(r1)-fabs(x1)>0 && fabs(r1)-fabs(x1)-0.1>EPSILON || r1-x1<0.001 )printf("Priblizno vece\n");
      else if(fabs(x1)-fabs(x1)<=0.1 && fabs(x1)>0.11)printf("Priblizno manje\n");
       else printf("Manje\n");
       
        printf("Unesite rjesenje x1: ");
        scanf("%f",&x1);
    }
    
    printf("Tacno\n");
    
       printf("Unesite rjesenje x2: ");
    scanf("%f",&x2);
    
 while(fabs(x2-r2)>EPSILON){
       
if(x2>r2 && (fabs(fabs(r2)-fabs(x2))>0.1 ||fabs(r2)-fabs(x2)==0))printf("Vece\n");
      else if(x2<r2 &&(fabs(fabs(x2)-fabs(r2))>0.11) ) printf("Manje\n");
      else if(fabs(r2)-fabs(x2)<0.1 && fabs(r2)-fabs(x2)>0 && fabs(r2)-fabs(x2)-0.1>EPSILON || r2-x2<0.001 )printf("Priblizno vece\n");
      else if(fabs(x2)-fabs(x2)<=0.1 && fabs(x2)>0.11)printf("Priblizno manje\n");
       else printf("Manje\n");
       
        printf("Unesite rjesenje x2: ");
        scanf("%f",&x2);
    }
    
    printf("Tacno\n");

    return 0;
}