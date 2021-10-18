#include <stdio.h>
#include <math.h>
#define eps 1e-2

int main()
{
    int M, N, i,j, teplicova=1;
    double mat[100][100];

    do {
        printf("Unesite M i N: ");
        scanf("%d %d", &M, &N);
        if(M<=0 || N<=0 || M >100 || N>100)
            printf("Pogresan unos!\n");

    } while(M<=0 || N<=0 || M >100 || N>100);


    printf("Unesite elemente matrice: ");

    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%lf", &mat[i][j]);

        }
    }
    if(M==1) {
        printf("Matrica je cirkularna");
        return 0;
    }
    for(i=0; i<M-1; i++) {
        for(j=0; j<N-1; j++) {
            if(fabs(mat[i][j]-mat[i+1][j+1])> eps) {
                teplicova=0;

            }
        }
    }
    if(teplicova) {

        if(fabs(mat[0][N-1]-mat[1][0])<=eps && fabs(mat[M-2][N-1]-mat[M-1][0])<=eps) {
            printf("Matrica je cirkularna");
            return 0;
        } else {
            printf("Matrica je Teplicova");
        }

    } else
        printf("Matrica nije ni cirkularna ni Teplicova");


    return 0;
}
