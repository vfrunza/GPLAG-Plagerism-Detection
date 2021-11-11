#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main ()
{
    int i, j, n;
    double niz[500], stepeni, stepeni_cijelidio, minute, minute_cijelidio, sekunde, sekunde_zaok;
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%lf", &niz[i]);
    }
    printf("Uglovi su:\n");
   
    for(i=0; i<n; i++)
    {
        stepeni=((niz[i]*180.00000)/PI);
        stepeni_cijelidio=(int)stepeni;
        
        minute=stepeni-stepeni_cijelidio;
        minute*=60.00;
        minute=fabs(minute);
        minute_cijelidio=(int)minute;
        
        sekunde=minute-minute_cijelidio;
        sekunde*=60.00;
        sekunde=fabs(sekunde);
        sekunde_zaok=(int)(sekunde + 0.50);
        
        if(sekunde_zaok>=60)
        {
            minute_cijelidio++;
            sekunde_zaok-=60.00;
           
        }
        if(minute_cijelidio>=60)
        {
            if(stepeni_cijelidio>0)
            stepeni_cijelidio++;
            if(stepeni_cijelidio<0)
            stepeni_cijelidio--;
            minute_cijelidio-=60.00;
        }
        
        if(sekunde_zaok<=30)
        {
            printf("%g stepeni %g minuta %g sekundi\n", stepeni_cijelidio, minute_cijelidio, sekunde_zaok);
            continue;
        }
        else
        {
            for(j=i; j<n-1; j++)
            {
                niz[j]=niz[j+1];
            }
            n--;
            i--;
        }
    }
    return 0;
}