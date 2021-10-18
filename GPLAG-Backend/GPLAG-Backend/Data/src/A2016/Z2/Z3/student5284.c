#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Niz[20][20];
    int x,y;
    int i,j;
    int n;
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    while(n>10 || n<1)
    {
    printf("Pogresan unos \n");
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    }

    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            Niz[i][j]=0;

    for(i=0;i<n;i++)
    {

        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&x,&y);
        while(x>19 || y>19 || x<0 || y<0)
        {
        printf("Pogresan unos\n");
        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&x,&y);
        }

        Niz[y][x]=1;
    }

    for(i=0;i<20;i++)
    {
      for(j=0;j<20;j++)
    {
        if(Niz[i][j]==1) printf("*");
        else printf(" ");
    }
     printf("\n");
    }

    return 0;
}