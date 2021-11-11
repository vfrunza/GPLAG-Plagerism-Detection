#include <stdio.h>

int main() {
    int unos = 1, N, M, matrica [200][200]={{0}}, i, j, k=1, l, m, o, p;
    do {
        printf("Unesite brojeve M i N: ");
        scanf ("%d %d", &M, &N);
        if (M<0 || N<0 || M>200 || N>200) {
            printf ("Brojevi nisu u trazenom opsegu.\n");
            unos = 0;
        }
        else unos = 1;
    }
    while (unos==0);
    
    printf ("Unesite elemente matrice: ");
    for (i=0; i<M; i++) {
    	for (j=0; j<N; j++) {
    		scanf ("%d", &matrica [i][j]);
    	}
    }
    
    for (i=0; i<M; i++) {
        for (k=i+1; k<M; k++) {
            for (j=0; j<N; j++) {
                if (matrica[i][j]!=matrica[k][j])
                break;
            }
            if (j==N) {
            /*Ako je ispunjen ovaj uslov k-ti red je jednak i-tom redu */
            for (l=k; l<M-1; l++) {
                for (m=0; m<N; m++) {
                    matrica [l][m]=matrica[l+1][m];
                }
            }
            M--;
        }
        }
    }
    
    for (j=0; j<N; j++) {
        for (k=j+1; k<N; k++) {
            for (i=0; i<M; i++) {
                if (matrica [i][j]!=matrica[i][k])
                break;
            }
            if (i==M) {
                /*k-ta kolona jednaka j-toj */
                for (o=k; o<N-1; o++) {
                    for (p=0; p<M; p++) {
                        matrica [p][o]=matrica[p][o+1];
                    }
                }
                N--;
            }
        }
    }
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
	    for (j=0; j<N;j++) {
	        printf ("%5d", matrica [i][j]);
	    }
	    printf ("\n");
	}
	return 0;
}
