#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,a,b,s,z,niz1[20][20],t,k;
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    while(n>10 || n<=0)
    {
        printf("Pogresan unos \n");
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
    }
    int niz[20][20];
    for(t=0;t<=19;t++)
    {
        for(k=0;k<=19;k++)
        {
            niz[t][k]=0;
            niz1[t][k]=1;
        }
    }
    for(m=1;m<=n;m++)
    {
    	printf("Unesite %d. tacku: ",m);
        scanf("%d %d",&a,&b);
        while((a<0 && b<0)||(a>19 && b>19)||(a<=0 && b>19)||(a>19 && b<=0)||(a<20 && b<0)||(a<0 && b<20))
        {
            printf("Pogresan unos \n");
            printf("Unesite %d. tacku: ",m);
            scanf("%d %d",&a,&b);
        }
        niz[b][a]=1;
    }
    for(s=0;s<=19;s++)
    {
        for(z=0;z<=19;z++)
        {
            if(niz[s][z]==niz1[s][z])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
