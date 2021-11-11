#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main ()
{
    double a, b, c, D, x1, x2, x11, x22, D1 ;
    
    printf("Unesite koeficijente a, b i c: ") ;
    scanf("%lf %lf %lf",&a, &b, &c) ;  
    
    D=b*b-4*a*c ;
    D1=sqrt(D) ;
    x22=(-b-D1)/(2*a) ;
    x11=(-b+D1)/(2*a) ;
   
    if(D<0) {
   printf ("Rjesenja su imaginarni brojevi.");}
   
   else
   {
   
     do {
      printf ("Unesite rjesenje x1: ");
      scanf ("%lf", &x1);
      if (fabs(x1-x11)<epsilon){
       printf ("Tacno\n");}
          else if (x1<x11 && fabs(x1-x11)>=0.1){
        printf ("Manje\n");}
       else if (x1>x11 && (fabs(x1-x11)>=0.1)){
        printf ("Vece\n");}
         else if (x1<x11 && fabs(x1-x11)<0.1){
         printf ("Priblizno manje\n");}
         else if (x1>x11 && (fabs(x1-x11)<0.1)){
          printf ("Priblizno vece\n");}
       
        
        else return 0;
        
     } while (fabs(x1-x11)>=epsilon);
     
        do {
      printf ("Unesite rjesenje x2: ");
      scanf ("%lf", &x2);
      if (fabs(x2-x22)<epsilon){
       printf ("Tacno\n");}
       else if (x2<x22 && fabs(x2-x22)>=0.1){
        printf ("Manje\n");}
       else if (x2>x22 && (fabs(x2-x22)>=0.1)){
        printf ("Vece\n");}
          else if (x2<x22 && fabs(x2-x22)<0.1){
         printf ("Priblizno manje\n");}
         else if (x2>x22 && (fabs(x2-x22)<0.1)){
          printf ("Priblizno vece\n");}
      
        
        else return 0;
        
     } while (fabs(x2-x22)>=epsilon);
     
      
   } 

    return 0;

}
