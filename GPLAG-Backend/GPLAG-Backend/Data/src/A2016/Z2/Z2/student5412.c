#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
    double niz[500];
    int n, i, j, stepen, minuta, sekundica;
    double sekunda;
    
    do
    {
        printf ("Unesite broj uglova: ");
        scanf ("%d", &n);
    }while (n<0 && n>500);
    
    for (i=0; i<n; i++)
    {
        scanf ("%lf", &niz[i]);
    }
    
    printf ("Uglovi su: \n");
    
    for (i=0; i<n; i++)
    {
        stepen = (180/PI)*niz[i];
        minuta = fabs(niz[i]*(180/PI)*60) - fabs(stepen*60);
        sekunda = fabs(niz[i]*(180/PI)*3600) - fabs(minuta*60) - fabs(stepen*3600);
        
        if (sekunda >= 60 )
        {
            minuta += 1;
            sekunda = 0;
        }
        
        if (minuta > 60)
        {
            stepen += 1;
            minuta = 0;
        }
        
        if(sekunda > 30)
        {
            for (j=i; j<n-1; j++)
            {
                niz[j] = niz[j+1];
            }
            n--;
            i--;
        continue;
        }
        sekundica=(int)(sekunda+(0.5));
        
        printf ("%d stepeni %d minuta %d sekundi\n", stepen, minuta, sekundica);
    }
    
    return 0;
}