#include <stdio.h>

int main()
{
    int M, N, m[200][200]= {0}, i, j,k, l, p, Rjednakost=1, Kjednakost=1;
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M<=0 || N<=0 || M>200 || N>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    } while(M<=0 || N<=0 || M>200 || N>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++)
            scanf("%d", &m[i][j]);
    }
//RED
    for(i=0; i<M; i++) {                                        //Poredjenje redova
        for(k=i; k<M; k++) {
            Rjednakost=1;
            for(j=0; j<N; j++) {
                if(m[i][j] != m[k][j])
                    Rjednakost=0;
            }
            if(Rjednakost && k!=i) {                            //Izbacivanje redova ako su jednaki
                for(l=k; l<M; l++) {
                    for(p=0; p<N; p++)
                        m[l][p]=m[l+1][p];
                }
                M--;
                k--;
            }
        }
    }

//KOLONA
    for(i=0; i<N; i++) {                                        //Poredjenje kolona
        for(j=1; j<N; j++) {
            Kjednakost=1;
            for(k=0; k<M; k++) {
                if(m[k][i] != m[k][i+j])
                    Kjednakost=0;
            }
            if(Kjednakost) {                                    //Izbacivanje kolona ako su jednake
                for(l=j; l<N; l++)
                    for(k=0; k<M; k++)
                        m[k][i+l] = m[k][i+l+1];
                N--;
                j--;
            }
        }
    }

//ISPIS

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++)
            printf(" %4d", m[i][j]);
        printf("\n");
    }




    return 0;
}