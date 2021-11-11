#include <stdio.h>
#include <math.h>

int main() 
{
    int n, cl1, cl2, razlika, koef=1, rezultat=0;
    printf ("Unesite broj: ");
    scanf ("%d", &n);
    if (n<0) n=fabs(n);
   
    if (n<10 && n>=0) {printf ("0");}
    
    else{
     while (n>=10){
         cl1=n%10;
         cl2=(n/10)%10;
         razlika=fabs(cl1-cl2);
         rezultat+=razlika*koef;
         koef*=10;
         n=n/10;
     } 
     printf("%d", rezultat);
    }
    
     return 0;
     
}
  
    
    
    
    