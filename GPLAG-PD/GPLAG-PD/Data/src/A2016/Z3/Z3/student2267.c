#include <stdio.h>

int main()
{

    int i,j,p,m,matrica[200][200],brojacr=0,brojack=0,N,M,k,z;

    /*Unos kolona i redova matrice i provjera uslova*/
    do {

        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M>200 || N>200 || M<=0 || N<=0)
            printf("Brojevi nisu u trazenom opsegu.\n");
        else
            break;
    }

    while(M>200 || N>200 || M<=0 || N<=0);

    printf("Unesite elemente matrice: ");

    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    /*Petlja pronalazi redove koji su jednaki nakon cega slijedi izbacivanje*/
    for(m=0; m<M; m++) {
        for(i=m+1; i<M; i++) {
            brojacr=0;
            for(j=0; j<N; j++) {
                if(matrica[m][j]==matrica[i][j])
                    brojacr++;
            }
            if(brojacr==N) {
                for(z=i; z<M; z++) {
                    for(j=0; j<N; j++) {
                        matrica[z][j]=matrica[z+1][j];
                    }
                }
                M--;
                i--;
            }
        }
    }


    /*Petlja pronalazi kolone koje su jednake nakon cega slijedi izbacivanje*/
    for(p=0; p<N-1; p++) {
        for(j=p+1; j<N; j++) {
            brojack=0;
            for(i=0; i<M; i++) {
                if(matrica[i][p]==matrica[i][j])
                    brojack++;
            }

            if(brojack==M) {
                for(k=j; k<N; k++) {
                    for(i=0; i<M; i++) {
                        matrica[i][k]=matrica[i][k+1];
                    }
                }
                N--;
                j--;
            }
        }
    }

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

    /*Ispis konacne matrice nakon izbacivanja*/
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            printf("%5d", matrica[i][j]);
        }
        printf("\n");

    }

    return 0;

}
