#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define g 0.0000000000000000000000000000000000000000000001
 
int main()
{
    int i,j,n,sekundaF,stepen,minuta;
    double niz[500]={0},sekunda,m,b=0.5;
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&niz[i]);
        niz[i]*=180./PI;
    }
    for(i=0;i<n;i++)
    {
        m=((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i]))));
        sekunda=fabs(60*m);
        sekunda+=b;
        sekundaF=sekunda;
        if(sekundaF==60) 
        {
            sekundaF=0;
        }
        if(sekundaF>30)
            {
                for(j=i;j<n;j++)
                {
                    niz[j]=niz[j+1];
                }
                n--;
                i--;
            }
    }
    printf("Uglovi su: \n");
    for (i=0;i<n;i++)
    {
        stepen=niz[i];
        minuta=abs((60*(niz[i]-(int)niz[i])));
        if(niz[i]>=0)
        {
        sekunda=fabs((int)((60*((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i])))))+b));
        }
        else
        {
        sekunda=fabs((int)((60*((60*(niz[i]-(int)(niz[i])))-(int)(60*(niz[i]-(int)(niz[i])))))-b));
        }
        if(fabs(sekunda-60)<g)
        { 
            minuta++; 
            sekunda=0;
        }
        if(niz[i]>=0)
        {
            if(minuta>=60) 
            { 
                stepen++; 
                minuta=0;
            }
        }
        else
        {
            if (minuta>=60)
            {
                stepen--;
                minuta=0;
            }
        }
        sekundaF=sekunda;
        printf ("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekundaF);
    }
    return 0;
}