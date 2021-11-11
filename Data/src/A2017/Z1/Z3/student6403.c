#include <stdio.h>
#include <math.h>

int main () {
    
float a,b,c;
double diskriminanta,x1,x2;
double x1rez,x2rez;



    printf ("Unesite koeficijente a, b i c: ");
    scanf("%f %f %f",&a,&b,&c);
 
diskriminanta = pow(b,2)-(4*a*c);

x1= (-b+(sqrt(diskriminanta)))/(2*a);
x2= (-b-(sqrt(diskriminanta)))/(2*a);


if (diskriminanta<0) {
    printf ("Rjesenja su imaginarni brojevi.");
}
else {
    
do {
    printf("Unesite rjesenje x1: ");
    scanf("%lf",&x1rez);
    
if (fabs(x1rez - x1)<0.001) {
    printf("Tacno\n");
    x1=x1rez;
}
    
    else if (x1rez<x1) {

if (fabs(x1rez-x1)<0.1) {
    printf("Priblizno manje\n");}
    else{
    printf("Manje\n");}
}

    else if (x1rez>x1) {

if (fabs(x1rez-x1)<0.1) {
    printf("Priblizno vece\n");}
    else{
    printf("Vece\n");}

}

}while ((x1!=x1rez));



do {
    printf("Unesite rjesenje x2: ");
    scanf("%lf",&x2rez);
    
    
if (fabs(x2rez - x2)<0.001) {
    printf("Tacno");
     x2=x2rez;
  
}
    else if (x2rez<x2) {
   
if (fabs(x2rez-x2)<0.1) {
    printf("Priblizno manje\n");}
    else{
    printf("Manje\n");}
}

    else if (x2rez>x2) {
   
if (fabs(x2rez-x2)<0.1) {
    printf("Priblizno vece\n");}
    else{
    printf("Vece\n");}

}
} while ((x2!=x2rez));

}

return 0;    

}

