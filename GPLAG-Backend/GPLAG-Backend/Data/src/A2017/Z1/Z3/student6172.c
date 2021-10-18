#include <stdio.h>
#define EPSILON 0.001
#define EPM 0.1
#include <math.h>
int main() {
    double a,b,c,x1,x2,D,tx1,tx2;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    D=b*b-4*a*c;
    tx1=(-b-sqrt(D))/(2*a);//x1 treba da bude manje rjesenje
    tx2=(-b+sqrt(D))/(2*a);
    if(tx2<tx1){
        tx1=tx2;
        tx2=(-b-sqrt(D))/(2*a);
    }
    if(D<0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    
    unosx1:
    printf("Unesite rjesenje x1: ");
    scanf("%lf",&x1);
    
    do{
        if(fabs(tx1-x1)<EPSILON){
            printf("Tacno\n");
            break;
        }
        else if(fabs(x1-tx1)>=EPSILON && fabs(x1-tx1)<EPM ) {
            if(x1-tx1>0)
            printf("Priblizno vece\n");
            else printf("Priblizno manje\n");
        }
        else if(x1<tx1)
        printf("Manje\n");
        else if(x1>tx1)
        printf("Vece\n");
    
        
        goto unosx1;
    }while(fabs(tx1-x1)>=EPSILON);
    
    
    unosx2:
    printf("Unesite rjesenje x2: ");
    scanf("%lf",&x2);
     
     do{
        if(fabs(x2-tx2)<EPSILON){
            
        printf("Tacno\n");
        break;
        }
        else if(fabs(x2-tx2)>=EPSILON && fabs(x2-tx2)<EPM ) {
            if(x2-tx2>0)
            printf("Priblizno vece\n");
            else printf("Priblizno manje\n");
        }
        else if(x2<tx2)
        printf("Manje\n");
        else if(x2>tx2)
        printf("Vece\n");
    
        
        goto unosx2;
    }while(fabs(tx2-x2)>=EPSILON);
    
	return 0;
}
