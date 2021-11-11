#include <stdio.h>

int suma_cifara(int clan_niza)
{
    int i,suma=0;
    int cifra;

    do {
        cifra=clan_niza%10;
        clan_niza=clan_niza/10;
        suma=suma+cifra;

        } while(clan_niza!=0);

    return suma;
}

void ubaci (int niz[],int velicina)
{
    int i,pomocni_niz[100];

    for (i=0; i<velicina; i++)
    {
        pomocni_niz[i]=niz[i];
    }

    for (i=1; i<2*velicina; i++) 
    {
        if (i==1)
            niz[i]=suma_cifara(niz[0]);

        if (i%2==0)
            niz[i]=pomocni_niz[i/2];

        if (i%2==1)
            niz[i]=suma_cifara(niz[i-1]);
    }

}


int izbaci(int niz[],int velicina)

{
    int i,j,k;
    int fibi[100];

    // Fibi stands for Fibonaccijev niz //

    // Prva dva clana Fibonaccijevog niza su 1 i 1 pa mozemo pisati: //

    fibi[0]=1;
    fibi[1]=1;

    for (i=2; i<100; i++) 
    {
        fibi[i]=fibi[i-1]+fibi[i-2];
    }


    for (i=0; i<velicina; i++)
    {
        for(j=0; j<100; j++)
        {

            if(niz[i]==fibi[j])
            {
                // Izbacivanje Fibonaccijevih brojeva iz niza uz ocuvanje redoslijeda //

                for (k=i; k<(velicina-1); k++)
                {
                    niz[k]=niz[k+1];

                }
                velicina--;
                i--;
                break;
            }
        }
    }
    return velicina;
}


int main()
{
    int i,j,niz[10],modificirani_niz[20],broj_clanova;


    printf ("Unesite niz od 10 brojeva: ");

    for (i=0; i<10; i++)
    {
        scanf ("%d",&niz[i]);
    }

    ubaci(niz,10);
    izbaci(niz,20);
    broj_clanova=izbaci(niz,20);


    printf ("Modificirani niz glasi: ");

    for (i=0; i<broj_clanova-1; i++)
    {
        printf ("%d",niz[i]);
        printf ("%d",niz[broj_clanova-1]);
    }

    return 0;
}
