#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float prec = 0.0000001;
    int p=0, q=0, r=0, pravougli=0, tr=0;
    float a,b,c;

    printf("Unesite koordinate tacke t1: ");
    scanf("%f %f %f", &a,&b,&c);
    printf("Unesite koordinate tacke t2: ");
    scanf ("%f %f %f", &a,&b,&c);
    printf ("Unesite koordinate tacke t3: ");
    scanf ("%f %f %f", &a,&b,&c);

     if( a<=0 || b<=0 || c<=0)
        {
            printf("Brojevi moraju biti pozitivni i veci od nule");
        }
     else if((a+b<=c) || (a+c<=b) || (b+c<=a))
        {
            printf("Nije trougao\n");
        }
     else
        {
                if (fabs(a-b)<prec) p=1; 
                if (fabs(b-c)<prec) q=1; 
                if (fabs(c-a)<prec) r=1; 
                if(fabs(c-sqrt(a*a+b*b))<prec || fabs(a-sqrt(b*b+c*c))<prec || fabs(b-sqrt(a*a+c*c))<prec) pravougli=1;

                if (p==1 && q==1 && r==1) printf("Jednakostranicni trougao\n");
                else if ( (p==1 && q==0 && r==0) || (p==0 && q==1 && r==0) || (p==0 && q==0 && r==1) )
                            printf("Jednakokraki trougao\n");
                else tr=1;

                if (pravougli==1) printf ("Pravougli trougao\n");
                else if (tr==1) printf("Obicni trougao");
        }

return 0;
}
