#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define epsilon 0.1
int main()
{
    double a, b, c, x1, x2, t, D, e, f;
    printf("\nUnesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    
    D = b*b - 4*a*c; /* diskriminanta */
    
    if (D > 0) {
    t = sqrt(D);
    x1 = (-b + t)/(2*a);
    x2 = (-b - t)/(2*a);
    } 
    else if (fabs(D-0)<EPSILON) {
    x1 = -b/(2*a);
    x2 = -b/(2*a);
    } 
    else {
    printf ("Rjesenja su imaginarni brojevi.");
   return 0;
    }
    
  do{
      printf("Unesite rjesenje x1: ");
      scanf("%lf",&f);
      if(f>x1&&fabs(f-x1)>=epsilon)
      printf("Vece\n");
      
      if((f>x1&&fabs(f-x1)<epsilon)&&(fabs(x1-f)>=EPSILON))
      printf("Priblizno vece\n");
      
      if(f<x1&&fabs(f-x1)>=epsilon)
      printf("Manje\n");
      
      if((f<x1&&fabs(f-x1)<epsilon)&&(fabs(x1-f)>EPSILON))
      printf("Priblizno manje\n");
  }while(fabs(x1-f)>=EPSILON);
  printf("Tacno");
  
  
  
  
  
  do{
      printf("\nUnesite rjesenje x2: ");
      scanf("%lf",&e);
      if(e>x2&&fabs(e-x2)>=epsilon)
      printf("Vece");
      
      if((e>x2&&fabs(e-x2)<epsilon)&&(fabs(x2-e)>EPSILON))
      printf("Priblizno vece");
      
      if(e<x2&&fabs(e-x2)>=epsilon)
      printf("Manje");
      
      if((e<x2&&fabs(e-x2)<epsilon)&&(fabs(x2-e)>EPSILON))
      printf("Priblizno manje");
  }while(fabs(x2-e)>EPSILON);
  printf("Tacno\n");
  return 0;
 
}
