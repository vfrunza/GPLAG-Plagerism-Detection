#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
    int i,brojac=0,dodaj=1,j,Broj=0;
	int max=n1;
	int niz[100000];
	if(n2>max) max=n2;
	if(n3>max) max=n3;
 
    /*Pravimo niz i niz brojaca svih brojeva koji se nalaze u sva tri niza, bez ponavljanja istih*/
	for(i=0;i<max;i++)
    {
        if(i<n1)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz1[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz1[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }

        if(i<n2)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz2[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz2[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }
        if(i<n3)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz3[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz3[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }
    }

    /*Prebrojavamo sve brojeve i uvecavamo nizove*/
    for(i=0;i<brojac;i+=2)
    {
        for(j=0;j<n1;j++)
        {
            if(niz1[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
        for(j=0;j<n2;j++)
        {
            if(niz2[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
        for(j=0;j<n3;j++)
        {
            if(niz3[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
    }
    
    /*Svi brojaci koji imaju vrijednost 2 su dakle brojevi koji se nalaze u dva od tri niza*/
    for(i=1;i<brojac;i+=2)
    {
        if(niz[i]==2) Broj++;
    }
	return Broj;
}

int main()
{
    /* AT1: Primjer iz zadatka */
int niz1[] = {0, 1, 2};
int niz2[] = {0, 1, 2};
int niz3[] = {1, 1, 1};
int rez = dva_od_tri(niz1, 3, niz1, 3, niz1, 0);
printf("%d", rez);
	return 0;
}
