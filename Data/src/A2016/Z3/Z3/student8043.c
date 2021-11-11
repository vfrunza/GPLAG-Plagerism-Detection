#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,niz[200][200],o,p,z=0,i,j,a,b,brojac=0,brojac2=0,c,d,l,e,r,brojac3=0,poz,h,g;
        do
    {
        if(z>0)
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        z++; 
    }while(m<1 || n<1 || m>200 || n>200);
        printf("Unesite elemente matrice: ");
    for(o=0;o<m;o++)
    {
        for(p=0;p<n;p++)
        {
            scanf("%d",&niz[o][p]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            l=j;
            for(a=i+1;a<m;a++)
            {
                for(b=0;b<n;b++)
                {
                    if(niz[i][j]==niz[a][b] && j==b)
                    {
                        brojac++;
                        j++;
                    }
                }
                if(brojac==n)
                {
                    for(c=a;c<=m-1;c++)
                    {
                        for(d=0;d<n;d++)
                        {
                            niz[c][d]=niz[c+1][d];
                        }
                    }
                    m--;
                    i=i-1;
                }
                brojac=0;
            }
        }
        j=l;
    }
    l3:
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) 
        {
            for(a=j+1;a<n;a++)
            {
                if(i==0)
                {
                    if(niz[i][j]==niz[i][a])
                    {
                        brojac3++;
                        poz=a;
                        goto l2;
                    }

                }
                if(i!=0)
                {
                    if(niz[i][j]==niz[i][a] && a==poz)
                    {
                        brojac3++;
                        goto l2;
                    }
                }
            }
        }
        l2:
            if(brojac3==0)
            {
                goto l1;
            }
            if(brojac3==m)
            {
                if(poz<n+1){
                for(h=0;h<m;h++)
                {
                    for(g=poz;g<n;g++)
                    {
                        niz[h][g]=niz[h][g+1];
                    }
                }}
                brojac3=0;
                n--;
                goto l3;
            }
    }
    l1:
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(e=0;e<m;e++)
    {
        for(r=0;r<n;r++)
        {
            if(niz[e][r]>9 || niz[e][r]<0)
            {
                printf("   %d",niz[e][r]);
            }
            else{
            printf("    %d",niz[e][r]);}
        }
        printf("\n");
    }
    return 0;
}
