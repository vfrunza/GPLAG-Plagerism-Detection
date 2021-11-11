#include <stdio.h>

int main()
{
    int tep,cir,M,N,i,j,mat[100][100];
    do
    {
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M>100 || N>100 || M<=0 || N<=0) printf("Pogresan unos!\n");
    }
    while(M>100 || N>100 || M<0 || N<0);
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    tep=0;
    cir=0;
    for(i=0; i<M-1; i++)
    {
        for(j=0; j<N-1; j++)
        {
            if(mat[i][j]==mat[i+1][j+1])
                tep=1;
            if(mat[i][N-1]==mat[i+1][0])
                cir=1;
        }
    }
    if(tep==1 && cir==1)
        printf("Matrica je cirkularna");
    else if(tep==1)
        printf("Matrica je Teplicova");
    else
        printf("Matrica nije ni cirkularna ni teplicova");
    return 0;
}