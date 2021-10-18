#include <stdio.h>

int main() {
	int niz1[100],i,n,ponavljanje[100],niz2[1000],k,r;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	do
	{
	    for (i=0;i<n;i++)
	    {
	    scanf("%d",&niz1[i]);
	    }
	}
    while (niz1[i]<0);
    k=0;
        for (i=0;i<n;i++)
        {
        r=niz1[i]%10;
        niz2[k]=r;
        ponavljanje[r]++;
        niz1[i]=niz1[i]/10;
        k++;
        i++;
        }
    printf("Finalni niz glasi: ");
    for (k=0;k<n;k++)
    {
            printf("%d %d",niz2[k],ponavljanje[r]);
    }
	return 0;
}
