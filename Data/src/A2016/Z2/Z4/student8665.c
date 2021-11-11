#include <stdio.h>

int main ()
{
    int M,N,mat[100][100]= {0},i=0,j=0,tepl=1,cirk=1;
    do {
         printf("Unesite M i N: ");
         scanf("%d %d", &M,&N);
        if(M>100 || N>100 || M<1 || N<1)
            printf("Pogresan unos!\n");
    } while(M>100 || N>100 || M<1 || N<1);
    
         printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);

        }
    }
    for(i=0; i<M-1; i++) {
        for(j=0; j<N-1; j++) {
            if(mat[i][j]!=mat[i+1][j+1])
                tepl=0;
        }
    }
    for(i=0; i<M-1; i++) {
        for(j=0; j<N-1; j++) {
            if(mat[i][j]!=mat[i+1][j+1] || mat[i][N-1]!=mat[i+1][0])
                cirk=0;
        }

    }
    if(cirk && (N!=1 && M >= 1 || N==1 && M==1)) printf("Matrica je cirkularna");
    else if(tepl) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");




    return 0;
}