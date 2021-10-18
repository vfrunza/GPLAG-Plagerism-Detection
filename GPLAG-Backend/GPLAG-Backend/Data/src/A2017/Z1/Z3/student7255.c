#include <stdio.h>
#include <math.h>

static const double eps=0.001;
#define PI 3.14159265;
int main()
{
    double a,b,c;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a, &b, &c);
   double disk=b*b-4*a*c;
   if(disk<0){
       printf("Rjesenja su imaginarni brojevi.");
   }
   else{
       disk=sqrt(disk);
    double x2=(0-b-disk)/(2*a);
       double x1=(0-b+disk)/(2*a);
       int nijePogodjenPrvi=1;
       do{
           printf("Unesite rjesenje x1: ");
           double x1p;
           scanf("%lf",&x1p);
           if(fabs(x1-x1p)<eps){
               printf("Tacno");
               nijePogodjenPrvi=0;
           }
           else {
               //rjesenje je vece od pretpostavljenog
               if(x1>x1p){
                   if((x1-x1p)<0.1){
                    printf("Priblizno manje");
                   }
                    else printf("Manje");
               }
               //manje
               else{
                   if((x1p-x1)<0.1){
                    printf("Priblizno vece");
                   }
                    else printf("Vece"); 
               }
           }
           printf("\n");
       }while(nijePogodjenPrvi==1);
       //isto za drugi
        int nijePogodjenDrugi=1;
       do{
           double x2p;
           printf("Unesite rjesenje x2: ");
           scanf("%lf",&x2p);
           if(fabs(x2-x2p)<eps){
               printf("Tacno");
               nijePogodjenDrugi=0;
           }
           else {
               //rjesenje je vece od pretpostavljenog
               if(x2>x2p){
                   if((x2-x2p)<0.1){
                    printf("Priblizno manje");
                   }
                    else printf("Manje");
               }
               //manje
               else{
                   if((x2p-x2)<0.1){
                    printf("Priblizno vece");
                   }
                    else printf("Vece"); 
               }
           }
           printf("\n");
           
       }while(nijePogodjenDrugi==1);
       
       
       
   }
 

    return 0;
}