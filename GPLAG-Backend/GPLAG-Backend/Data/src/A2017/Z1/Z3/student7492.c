#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main()
{
        /*Unosenje koeficijenata*/
        double a,b,c,x1,x2,D,x1K,x2K,x1R,x2R;
        printf("Unesite koeficijente a, b i c: ");
        scanf("%lf %lf %lf",&a,&b,&c);
        D=pow(b,2)-4*a*c;
        x1R=(-b-sqrt(D))/(2*a);
        x2R=(-b+sqrt(D))/(2*a);
        
        /*Koje je rjesenje vece?*/
        if(x1R>=x2R)
        {
                x1=x2R;
                x2=x1R;
        }
        else if(x1R<=x2R)
        {
                x1=x1R;
                x2=x2R;
        }
                
        /*Trazenje x1 i x2*/
        if(D>0 || D==0 )
        {
                do{
                        printf("Unesite rjesenje x1: ");
                        scanf("%lf",&x1K);
                        if(x1K-x1<0.1 && x1K-x1>=epsilon) { printf("Priblizno vece\n"); }
                        else if(x1K-x1>-0.1 && x1K-x1<=-epsilon) { printf("Priblizno manje\n"); }
                        else if(x1K-x1>=0.1) { printf("Vece\n"); }
                        else if(x1K-x1<=-0.1) { printf("Manje\n"); }
                }while(x1K-x1<-epsilon || x1K-x1>epsilon);
                printf("Tacno\n");
                
                do
                {
                        printf("Unesite rjesenje x2: ");
                        scanf("%lf",&x2K);
                        if(x2K-x2<0.1 && x2K-x2>=epsilon) { printf("Priblizno vece\n"); }
                        else if(x2K-x2>-0.1 && x2K-x2<=-epsilon) { printf("Priblizno manje\n"); }
                        else if(x2K-x2>=0.1) { printf("Vece\n"); }
                        else if(x2K-x2<=-0.1) { printf("Manje\n"); }
                }while(x2K-x2<-epsilon || x2K-x2>epsilon);
                printf("Tacno\n");
        }
        else
        {
                printf("Rjesenja su imaginarni brojevi.");
        }
return 0;
}
 