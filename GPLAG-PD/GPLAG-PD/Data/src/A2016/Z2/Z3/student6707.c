#include <stdio.h>

int main()
{
    char mat[20][20];
    int n,i,j,m,k,l;
    
     for( i=0; i<20; i++)
    {
       for( j=0; j<20; j++)
    {
         mat[i][j]=' ';
      
    } 
    }
    do{
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        if(n<=0 || n>10) printf("Pogresan unos\n");
        }while(n<=0 || n>10);
    
    
    m=0;
    while(m!=n)
    {
        do{
        printf("Unesite %d. tacku: ", m+1);
        scanf("%d %d",&k, &l);
        if(k<0 || k>19 || l<0 || l>19 ) printf("Pogresan unos\n");
        }while(k<0 || k>19 || l<0 || l>19 );
        mat[l][k]='*';
    m++;
    }
    for( i=0; i<20; i++)
    {
       for( j=0; j<20; j++)
    {
        printf("%c",mat[i][j]);
    } 
    printf("\n");
    }
    return 0;
    
}