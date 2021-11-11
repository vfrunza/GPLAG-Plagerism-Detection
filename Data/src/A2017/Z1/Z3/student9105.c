#include <stdio.h>
#define EPSILON 0.001
#define RAZLIKA 0.1
#include <math.h>

int main() {
    double a,b,c,x1,x1p,x2,x2p,tacnox1=0,tacnox2=0;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(b*b-4*a*c<0)
    {
    printf("Rjesenja su imaginarni brojevi.");
    return 1;
    }
    if(a>0)
    x1=(-b-sqrt(b*b-4*a*c))/(2*a);
    if(a>0 && b>sqrt(b*b-4*a*c) || a<0 && b<sqrt(b*b-4*a*c) || sqrt(b*b-4*a*c)==0)
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    do{
    printf("Unesite rjesenje x1: ");
    scanf("%lf", &x1p);
    if(fabs(x1p- x1)<EPSILON)
    {
    printf("Tacno\n");
    tacnox1=1;
    }
    if(fabs(x1p-x1)>=RAZLIKA && fabs(x1p-x1)>=EPSILON && x1p<x1)
    printf("Manje\n");
    if(fabs(x1p-x1)>=RAZLIKA && x1p>x1)
    printf("Vece\n");
    if(fabs(x1p-x1)<RAZLIKA && fabs(x1p-x1)>=EPSILON && x1p<x1)
    printf("Priblizno manje\n");
    if(fabs(x1p-x1)<RAZLIKA && fabs(x1p-x1)>=EPSILON && x1p>x1)
    printf("Priblizno vece\n");
    }
    while(tacnox1!=1);
    
    if(a<0 && b>sqrt(b*b-4*a*c) || a>0 && b<sqrt(b*b-4*a*c) || sqrt(b*b-4*a*c)==0)
    x2=(-b+sqrt(b*b-4*a*c))/(2*a);
    if(a<0)
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    if(fabs(x1p-x1)<EPSILON)
    {
    do{
    printf("Unesite rjesenje x2: ");
    scanf("%lf", &x2p);
    if(fabs(x2p-x2)<EPSILON)
    {
    printf("Tacno\n");
    tacnox2=1;
    }
    if(fabs(x2p-x2)>=RAZLIKA && fabs(x2p-x2)>=EPSILON && x2p<x2)
    printf("Manje\n");
    if(fabs(x2p-x2)>=RAZLIKA && x2p>x2)
    printf("Vece\n");
    if(fabs(x2p-x2)<RAZLIKA && fabs(x2p-x2)>=EPSILON && x2p<x2)
    printf("Priblizno manje\n");
    if(fabs(x2p-x2)<RAZLIKA && fabs(x2p-x2)>=EPSILON && x2p>x2)
    printf("Priblizno vece\n");
    }
    while(tacnox2!=1);
    }
    return 0; 
}
 