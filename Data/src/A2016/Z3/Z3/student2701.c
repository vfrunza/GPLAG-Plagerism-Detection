#include <stdio.h>
#define VISINA 200
#define SIRINA 200

int main ()
{
    int i, j, M, N, visina, sirina, index_red1, index_red2;
    float mat[VISINA][SIRINA];
    
    do
    {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &M, &N);
        if((M<=0 || M>200) || (N<=0 || N>200))
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    }while((M<=0 || M>200) ||(N<=0 || N>200));
    
    printf("Unesite elemente matrice: \n");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    visina=M;
    sirina=N;
    
    
    
     return 0;
    
}