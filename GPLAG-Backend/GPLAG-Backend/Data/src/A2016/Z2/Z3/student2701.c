#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main ()
{
    int k, n, x[10], y[10], a, b;
    int i, j;
    char mat[VISINA][SIRINA];
    do
    {
        printf("Unesite broj tacaka: ");
        scanf("%d", &n);
        if(n<=0 || n>10) printf("Pogresan unos\n");
        else break;
    }while(n<=0 || n>10);
    
    for(k=0; k<n; ++k)
    {
        printf("Unesite %d. tacku: ", k+1);
        
        scanf("%d %d", &x[k], &y[k]);
        if(x[k]>=20 || x[k]<0) { printf("Pogresan unos\n"); k--; continue; }
        if(y[k]>=20 || y[k]<0) { printf("Pogresan unos\n"); k--; continue; }
    }
    for(i=0; i<VISINA; i++)
    {
        for(j=0; j<SIRINA; j++)
        {
            mat[i][j]=' ';
        }
        
    }
    
    for(k=0; k<n; k++)
    {
        {
            a=x[k]; b=y[k];
            
        }
        for(i=0; i<VISINA; i++)
        {
            for(j=0; j<SIRINA; j++)
            {
                if(j==a && i==b)
                mat[i][j]='*';
                
            }
        }
    }
    
    for(i=0; i<VISINA; i++)
    {
        for(j=0; j<SIRINA; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
  
  return 0;
}
