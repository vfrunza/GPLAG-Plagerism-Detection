#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
    int a,b,c;
    double D,x1,x2,x11,x22,t;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%d %d %d", &a, &b, &c);
    D=b*b-4*a*c;
    if(D<0){printf("Rjesenja su imaginarni brojevi.");
    return 0;}
       t=sqrt(D);
        x22=(-b-(t))/(2*a);
        x11=(-b+(t))/(2*a);
     
        do{
    
printf("Unesite rjesenje x1: ");
scanf("%lf", &x1);
if(fabs(x1-x11)<EPSILON )
{ printf("Tacno\n");
break;}
    else if(((x1-x11)<0.001 && (x11-x1)<0.1)){
        printf("Priblizno manje\n");
    }
    else if((x1-x11)<0.1 && (x1-x11)>=0.0001){
        printf("Priblizno vece\n");
    }
else if(x1<=0) {
    if((x11-x1)>=0.1 )
    {printf("Manje\n");
}else if((x11-x1)<=0.1)printf("Vece\n");}
    else if(x1>=0){
    if((x11-x1)<=0.1 ){
        printf("Vece\n");}}
        else if(x1<=0){
        if((x11-x1)>=0.1 )
    {printf("Manje\n");
}}
    else if((x1)>=0 ) {
    if((x11-x1)>=0.1 )
    {printf("Manje\n");
}}
else if(x1<=0){
if(x1-x11<=0.1)
{printf("Vece\n");
}
        
    
}   }
while(1==1);

do{
    printf("Unesite rjesenje x2: ");
    scanf("%lf" , &x2);
    if(fabs(x2-x22)<EPSILON) {
        printf("Tacno");break;}
            else if((x2-x22)<=0.001 && (x22-x2)<0.1){
        printf("Priblizno manje\n");
    }
    else if((x2-x22)>=0.0001 && (x2-x22)<0.1){
        printf("Priblizno vece\n");
    }
    else if(x2>=0 ) {
    if((x22-x2)>=0.1 )
    {printf("Manje\n");
}else if((x22-x2)<=0.1)
printf("Vece\n");}
    else if(x2>=0){
    if((x22-x2)<=0.1 ){
        printf("Vece\n");}}
        else if(x2<0){
        if((x22-x2)>=0.1 )
    {printf("Manje\n");
} else if(x2<0){
      if((x22-x2)<=0.1 ){
        printf("Vece\n");
}}
    else if(x2>=0 ) {
    if((x22-x2)>=0.1 )
    {printf("Manje\n");
}}else if(x2<=0){
if(x22-x2<=0.1)printf("Vece\n");
   
}}}
while(1==1);
	return 0;
}
