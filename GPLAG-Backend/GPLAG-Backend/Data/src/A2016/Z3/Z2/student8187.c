#include <stdio.h>
#include <stdlib.h>

int suma (int a)
{
    int s=0;
    while (a>0)
    {
        s=s+a%10;
        a=a/10;
    }
    return s;
}


void ubaci (int niz[], int velicina)
{
    int sklj;
    int *s, *b;
    int i=2*velicina;
    
    /*ubacivanje praznog mjesta izmedju clanova*/
    for (i=velicina-1; i>=0; i--)
    {
        b=niz + i*2;
        s=niz + i;
        *b=*s;
    }
    /*implementacija sume cifara na stvorena prazna mjesta*/
    for (i=0; i<velicina*2; i=i+2)
    {
        b=niz + i;
        s=b + 1;
        sklj=abs(*b);
        *s=suma(sklj);
    }
}

int izbaci (int niz[], int velicina)
{
    int fibonacijev[1000]={0};
    int max, b=2, i, j, sklj, v2;
    max=niz[0];
    
    /*provjeravanje da li je broj Fibonaccijev*/
    for (i=0; i<velicina; i++)
        {
            if (max<niz[i]) 
            max=niz[i];
        }
        fibonacijev[0]=1; 
        fibonacijev[1]=1;
        
        
        
    for (i=2; i<1000; i++)
        {
            fibonacijev[i]=fibonacijev[i-1] + fibonacijev[i-2];
            if (fibonacijev[i]>max) break;
            else (b++);
        }
        
    v2=velicina;    
    
    /*izbacivanje Fibonaccijevih brojeva*/
    for (i=0; i<v2; i++)
    {
        for (j=0; j<b;j++)
        {
            if (niz[i]==fibonacijev[j])
            {
                for (sklj=i; sklj<v2-1; sklj++)
                
                niz[sklj]=niz[sklj+1];
                v2--;
                i--;
                break;
            }
        }
    }
    
    return v2;
    
}



int main()
{
    int niz[20], i, velicina=10, izbac;
    printf ("Unesite niz od 10 brojeva: ");
    for (i=0; i<10; i++)
    {
        scanf ("%d", &niz[i]);
    }
    
    /*poziv funkcije ubaci*/
    ubaci (niz, velicina);
    velicina=velicina*2;
    /*poziv funkcije izbaci*/
    izbac=izbaci(niz,velicina);
    
    /*ispis modificiranog niza*/
    printf ("Modificirani niz glasi: ");
    for (i=0;i<izbac-1;i++)
    printf ("%d, ", niz[i]);
    printf ("%d.", niz[i]);
    return 0;
}