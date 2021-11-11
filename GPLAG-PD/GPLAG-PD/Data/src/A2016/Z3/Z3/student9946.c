#include <stdio.h>

int main ()
{
    int matrica[200][200];
    int j;
    int M;
    int N;
    int i;
    int k=0;
    int m;
    int n;
    int temp;
    int brojac=0;
    do {
        printf("Unesite brojeve M i N:");
        scanf("%d%d", &M,&N);
        if (M<1 || M>200 || N<1 || N>200)
            printf(" Brojevi nisu u trazenom opsegu.\n");
    } while(M<1 || M>200 || N<1 || N>200);

    printf(" Unesite elemente matrice: ");
    for (i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%d",&matrica[i][j]);
        }
    }
    for(i=0; i<M; i++) {
        for(j=i+1; j<M; j++) {

            brojac =0;
            for(k=0; k<N; k++) {
                if(matrica[i][k]==matrica[j][k]) {
                    brojac++;
                }
                if(brojac==N) {
                    for(m=j+1; m<M; m++) {
                        for(n=0; n<N; n++) {
                            temp=matrica[m-1][n];
                            matrica[m-1][n]=matrica[m][n];
                            matrica[m][n]=temp;
                        }
                    }
                    M--;
                    j--;
                }
            }
        }
    }
    for(i=0; i<N; i++) {
        for(j=i+1; j<N; j++) {
            brojac=0;
            for(k=0; k<M; k++) {
                if(matrica[k][i]==matrica[k][j]) {
                    brojac++;
                }
                if (brojac==M) {
                    for(m=j+1; m<N; m++) {
                        for(n=0; n<M; n++) {
                            temp=matrica[n][m-1];
                            matrica[n][m-1]=matrica[n][m];
                            matrica[n][m]=temp;
                        }
                    }
                    N--;
                    j--;
                }

            }
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            printf("%5d",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}