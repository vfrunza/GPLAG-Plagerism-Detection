#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int brojac=0,i,n,niz1[100],niz2[1000],pomocniniz[1000],broj=1,k=0;
    printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    printf("Unesite clanove niza: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&niz1[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        if(niz1[i]==0)
        {
            pomocniniz[brojac]=0;
            brojac++;
        }
        else
        {
            while(niz1[i]>0)
            {
                pomocniniz[brojac]=niz1[i]%10;
                niz1[i]/=10;
                brojac++;
            }
        }
    }
    niz2[0]=pomocniniz[brojac-1];
    for(i=brojac-1;i>0;i--) {
        if(pomocniniz[i]==pomocniniz[i-1])
        {
            broj++;
        }
        else
        {
            niz2[k+1]=broj;
            k+=2;
            broj=1;
            niz2[k]=pomocniniz[i-1];
        }
    }
    k+=2;
    niz2[k-1]=broj;
    printf("Finalni niz glasi:\n");
    for(i=0;i<k;i++)
    {
        printf("%d ",niz2[i]);
    }
    return 0;
}
