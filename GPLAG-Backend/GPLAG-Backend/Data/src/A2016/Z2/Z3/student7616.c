#include<stdio.h>
int main()
{
    int mat[20][20]= {0};
    int i,j,n,x,y;
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    while(n>10 || n<=0)
    {
    printf("Pogresan unos\n");
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    }
    for(i=0; i<n; i++)
    {
        printf("Unesite %d. tacku: ", i+1);
        scanf("%d %d", &x,&y);
        while(x<0 || x>19 || y<0 || y>19)
        {
            printf("Pogresan unos\n");
            printf("Unesite %d. tacku: ", i+1);
            scanf("%d %d", &x, &y);
        }
        mat[y][x]=1;
    }
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            if(mat[i][j]==1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
    
}