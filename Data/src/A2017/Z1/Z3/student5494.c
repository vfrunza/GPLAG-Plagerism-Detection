#include <stdio.h>
#include <math.h>
#define E 0.001
int main() {
double a,b,c,x1,x2,d,x11,x21,x12,x22;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf",&a,&b,&c);
if(a!=0){
d=(b*b-4*a*c);
if(d<0){
printf("Rjesenja su imaginarni brojevi.");
return 0;
}
else if(d>=0){
x11=((-b)+sqrt(d))/(2*a);
x21=((-b)-sqrt(d))/(2*a);
if(x11>x21){
x22=x21;
x12=x11;
}
else{
x22=x21;
x12=x11;
}
do{
printf("Unesite rjesenje x1: ");
scanf("%lf",&x1);
if((x12<x1)&&(x1-x12>=0.1)){
printf("Vece\n");
}
else if((x1-x12<0.1)&&(x1-x12>=E)){
printf("Priblizno vece\n");
}
else if((x12>x1)&&(x12-x1>=0.1)){
printf("Manje\n");
}
else if((x12-x1<0.1)&&(x12-x1>=E)){
printf("Priblizno manje\n");
}
}
while(fabs(x12-x1)>=E);
printf("Tacno\n");
do{
printf("Unesite rjesenje x2: ");
scanf("%lf",&x2);
if(x22<x2 && x2-x22>=0.1){
printf("Vece\n");
}
else if(x2-x22<0.1 && x2-x22>=E){
printf("Priblizno vece\n");
}
else if(x22>x2 && x22-x2>=0.1){
printf("Manje\n");
}
else if(x22-x2<0.1 && x22-x2>=E){
printf("Priblizno manje\n");
}
}
while(fabs(x22-x2)>=E);
printf("Tacno\n");
}
}
return 0;
}
