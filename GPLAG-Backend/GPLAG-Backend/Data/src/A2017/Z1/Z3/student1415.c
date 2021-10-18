#include <stdio.h>
#include <math.h>
#define E 0.001
#define F 0.1

int main() {
    
    double a, b, c, D, x1, x2, R1, R2, K;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    D=(b*b)-(4*a*c);

    if(D<0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    
    if(a==0){
        x1=-1*c/b;
        x2=x1;
    }
    else if(b==0){
        x1=-1*sqrt((-1*c)/a);
        x2=sqrt((-1*c)/a);
    }
    else if(c==0 && b ==0){
        x1=0;
        x2=x1;
    }   
    else{
    K= sqrt(D);
    x1=((-1)*b-K)/(2*a);
    x2=((-1)*b+K)/(2*a);
    }
    
    
    do {
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &R1);
        
        if(fabs(R1-x1)<E){
            printf("Tacno\n");
            break;
        }
        
        else {
        if(fabs(R1-x1)<F && fabs(R1-x1)>=E){
            printf("Priblizno ");
            if((R1>x1 && R1>=0 && x1>=0)||(R1>x1 && R1<=0 && x1<=0)||( R1>=0 && x1<=0)){
                printf("vece\n");
            }
            else {printf("manje\n");}
        }
        
        else if(((R1-x1)>0 && R1>=0 && x1>=0)||(R1>x1 && R1<=0 && x1<=0)||( R1>=0 && x1<=0)){
            printf("Vece\n");
        }
        
        else{
            printf("Manje\n");
        }
      }
      
    }
        while(fabs(R1-x1)>=E);
    
    do {
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &R2);
        
        if(fabs(R2-x2)<E){
            printf("Tacno\n");
            break;
        }
        
        else {
        if(fabs(R2-x2)<F && fabs (R2-x2)>=E){
            printf("Priblizno ");
            if((R2>x2 && R2>=0 && x2>=0)||(R2>x2 && R2<=0 && x2<=0)||( R2>=0 && x2<=0)){
                printf("vece\n");
            }
            else {printf("manje\n");}
        }
        
        else if((R2>x2 && R2>=0 && x2>=0)||(R2>x2 && R2<=0 && x2<=0)||( R2>=0 && x2<=0)){
            printf("Vece\n");
        }
        
        else{
            printf("Manje\n");
        }
      }
      
    }
        while(fabs(R2-x2)>=E);
    
    return 0;    
}