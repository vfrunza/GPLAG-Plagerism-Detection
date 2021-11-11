#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
   double a , b , c;
   double  x1, x2;
   double D = 0;
   double  pomocna, unijeto;
   printf("Unesite koeficijente a, b i c: ");
   scanf("%lf %lf %lf", &a, &b, &c);
 
 D = pow(b, 2)- 4*a*c;
   
   if(D < 0)
      {
      printf("Rjesenja su imaginarni brojevi.");
      return 0;
   }
  
   
   x1 = ( -b - sqrt(D)) / (2*a);
   x2 = ( -b + sqrt(D)) / (2*a);
   
   
   while(1) {
   
 printf("Unesite rjesenje x1: ");
 scanf("%lf", &unijeto);
    
    if (x1>x2)
   {
       pomocna = x1;
       x1 = x2;
       x2 = pomocna;
   }
   
    if (fabs(unijeto - x1)< EPSILON) 
    {
    printf("Tacno\n");
   break;
  
     } 
     
    else if (unijeto>x1 && fabs(unijeto - x1)< 0.1)
       printf("Priblizno vece\n");
    
    else if (unijeto<x1 && fabs(unijeto - x1)< 0.1)
      printf("Priblizno manje\n");
   
    else if (unijeto>x1)
      printf("Vece\n");
   
    else if (unijeto<x1) 
      printf("Manje\n");
   }  
   
   while(1)  {
   
 printf("Unesite rjesenje x2: ");
 scanf("%lf", &unijeto);
 
 if (x1>x2)
   {
       pomocna = x1;
       x1 = x2;
       x2 = pomocna;
   }
 
    if (fabs(unijeto - x2)< EPSILON) 
    {
    printf("Tacno\n");
    break;
    } 
    
    else if (unijeto>x2 && fabs(unijeto - x2)< 0.1) 
       printf("Priblizno vece\n");
    
    else if (unijeto<x2 && fabs(unijeto - x2)< 0.1) 
      printf("Priblizno manje\n");
   
    else if (unijeto>x2)
      printf("Vece\n");
   
    else if (unijeto<x2) 
      printf("Manje\n");
   } 
    return 0 ;
}