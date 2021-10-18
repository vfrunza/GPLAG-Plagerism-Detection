#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int matrica[200][200];
    int M = 0, N = 0, i, j, k, l, isti;

    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M <= 0 || N <= 0 || M >= 200 || N >= 200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    } while(M <= 0 || N <= 0 || M >= 200 || N >= 200);

    printf("Unesite elemente matrice: ");
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &matrica[i][j]);

    for(i = 0; i < M-1; i++) {
        for(j = i+1; j < M; j++) {
            isti = TRUE;
            for(k = 0; k < N; k++) {
                if(matrica[i][k] != matrica[j][k]) {
                    isti = FALSE;
                    break;
                }
            }
            if(isti) {
                for(k = j; k < M-1; k++)
                    for(l = 0; l < N; l++)
                        matrica[k][l] = matrica[k+1][l];
                M--;
                j--;
            }
        }
    }

    for(i = 0; i < N-1; i++) {
        for(j = i+1; j < N; j++) {
            isti = TRUE;
            for(k = 0; k < M; k++) {
                if(matrica[k][i] != matrica[k][j]) {
                    isti = FALSE;
                    break;
                }
            }
            if(isti) {
                for(k = j; k < N-1; k++) {
                    for(l = 0; l < M; l++)
                        matrica[l][k] = matrica[l][k+1];
                }
                N--;
                j--;
            }
        }
    }

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++)
            printf("%5d", matrica[i][j]);
        printf("\n");
    }
    return 0;
}