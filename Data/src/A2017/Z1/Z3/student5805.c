#include <stdio.h>
#include <math.h>
#define e 0.001
int main()
{
  int a,b,c, D;
  double x1,x2,s,k;
  printf("Unesite koeficijente a, b i c: ");
  scanf("%d %d %d", &a, &b, &c);
  D = b*b - 4*a*c; 
     x1 = (-b + sqrt(D))/(2*a);
     x2 = (-b - sqrt(D))/(2*a);
     if(D>=0) {
     for(;;) {
     printf("Unesite rjesenje x1: ");
     scanf("%lf", &s);
     if(fabs(s-x1)<e){ 
         printf("Tacno\n");
            for(;;) {
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &k);
                if(fabs(k-x2)<e){ printf("Tacno"); break;
                }
                 if((x2-k)<0.1 && k<x2) {
                printf("Priblizno manje\n"); continue;
                }
                 if((k-x2)<0.1 && k>x2) {
                printf("Priblizno vece\n"); continue;
                }
                if(k<x2) {
                printf("Manje\n"); continue;
                }
                if(k>x2) { 
                printf("Vece\n"); continue;
                }
            }
        break;
     }
     else if(((x1-s)<0.1) && s<x1) {
         printf("Priblizno manje\n"); continue;
     }
      if(((s-x1)<0.1) && s>x1) {
         printf("Priblizno vece\n"); continue;
     }
     else if(s<x1) {
         printf("Manje\n"); continue;
     }
     if(s>x1) { 
         printf("Vece\n"); continue;
     }
     } 
     }
     else printf("Rjesenja su imaginarni brojevi.");
     
  return 0;
}
