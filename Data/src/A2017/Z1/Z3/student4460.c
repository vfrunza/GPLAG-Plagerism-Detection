#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
 double x1, x2, a,b,c,D,r1, r2, t, p;

printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a, &b, &c);
D=(b*b-4*a*c);

if(D<0){
    printf("Rjesenja su imaginarni brojevi.");
    
}
else{
    
    t=sqrt(D);
    x2=((-b-t)/(2*a));
    x1=((-b+ t)/(2*a));
    if(x1>x2){
    p=x1;
    x1=x2;
    x2=p;
    }
    
        
    do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &r1);
        
        
    if((fabs(r1-x1)<=EPSILON)){
        printf("Tacno\n");
        break;
        
    }
    if(((r1-x1)>-1*(0.1))&& (r1-x1)<0)
    printf("Priblizno manje\n");
    else if(r1<x1){
        printf("Manje\n");
    }
     
    if(((r1-x1)<0.1) && (r1-x1)>0)
    printf("Priblizno vece\n");
    else if(r1>x1){ 
        printf("Vece\n");
   }
    }
    while((fabs(r1-x1)>=EPSILON));
do{
     printf("Unesite rjesenje x2: ");
        scanf("%lf", &r2);
    if((fabs(r2-x2))<=EPSILON){
        printf("Tacno\n");
        break;
    }
    if(((r2-x2)>-1*(0.1))&& (r2-x2)<0){
    printf("Priblizno manje\n");
    }
    
    else if(r2<x2){
        printf("Manje\n");
    }
   
    if((fabs(r2-x2)<=0.1) && (r2-x2)>0)
    printf("Priblizno vece\n");
    else if(r2>x2){
        printf("Vece\n");
    }
    
}
while(fabs(r2-x2)>=EPSILON);

}
	return 0;
}
