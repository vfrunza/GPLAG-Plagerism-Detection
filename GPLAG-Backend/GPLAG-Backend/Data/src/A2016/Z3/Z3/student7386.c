#include <stdio.h>
int main()
{
    int m,n,a,b,c,d,niz[200][200],brojac;
    brojac=0;
    do
    {
        printf ("Unesite brojeve m i n: ");
        scanf ("%d %d",&m  ,&n);
        if ( m<1 || n<1 || m>200 || n>200)
        printf ("Brojevi nisu u traženom opsegu. ");
    }
    
    while (m<1 || n<1 || m>200 || n>200);
    printf ("Unesite elemente matrice: \n ");
    for (a=0; a<m; a++)
    for (b=0; b<n; b++)
    scanf ("%d", &niz [a][b]);
    for (a=0; a<m-1; a++)
    for (c=a+1; c<m; c++)
    
    {
        for (b=0; b<n; b++)
        {
            if (niz [a][b]!=niz [c][b])
        break;
        else
        brojac++;
        }
        if (brojac==n)
        {
            for (d=c; d<m; d++)
            for (b=0;b<n;b++)
            niz [d][b]= niz [d+1][b];
            m--;
            c--;
        }
    }
    for (a=0; a<m; a++)
    for (b=0; b<n; b++)
    printf ("%d", niz [a][b]);
    for (b=0; b<n; b++)
    for (c=b+1;c<n; c++)
    {
        brojac=0;
        for (a=0;a<m; a++)
        {if (niz [a][b] != niz [a][c])
        break;
        else
        brojac++;
        }
        if (brojac=m)
        {
            for (a=0; a<m; a++)
            for (d=c;d<n; d++)
            niz [a][d]=niz [a][d+1];
            n--;
            c--;
        }
    }
    printf ("\n Nakon izbacivanja redova/kolona matrica glasi : ");
    for (a=0;a<m; a++)
    {
        for (b=0; b<n; b++)
        {
            printf (" %d", niz [a+3][b+3]);
        }
    }
    return 0;
}
