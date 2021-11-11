#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define e 0.001
int main()
{

    double a,b,c,D,x,y,x1,x2,t;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a,&b,&c);
    D=(b*b)-(4.0)*(a)*(c);
    bool kraj1=false,kraj2=false;
    if (D<0) {
        printf("Rjesenja su imaginarni brojevi.");
        return 1;
    }

        t=sqrt(D);
        x=((-b)-(t))/(2*a);
        if(b==0)
        x=-x;
        y=((-b)+(t))/(2*a);
        if(b==0)
        y=-y;
        if(x>0)
            x=fabs(((-b)-(t))/(2*a));
        if(y>0)
            y=fabs(((-b)+(t))/(2*a));
            


        do
        {
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x1);
            if(x>(x1-e) && x<(x1+e))
              {  printf("Tacno\n");
            kraj1=true;}

             if(fabs(x1-x)<0.1 && fabs(x1-x)>=e && x1<x) printf("Priblizno manje\n");
              if(fabs(x1-x)<0.1 && fabs(x1-x)>=e && x1>x) printf("Priblizno vece\n");
             if(x1<=x-0.1 && x1<x) printf("Manje\n");
             if(x1>=x+0.1 && x1>x) printf("Vece\n");

        }while(kraj1!=true);


        do
         {
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x2);
            if(y>(x2-e) && y<(x2+e))
           {     printf("Tacno\n");
           kraj2=true;
           }
           if(fabs(x2-y)<0.1 && fabs(x2-y)>=e && x2<y) printf("Priblizno manje\n");
            if(fabs(x2-y)<0.1 && fabs(x2-y)>=e && x2>y) printf("Priblizno vece\n");
             if(x2<=y-0.1 && x2<y ) printf("Manje\n");
             if(x2>=y+0.1 && x2>y) printf("Vece\n");

        }while(kraj2!=true);






        return 0;
    }
