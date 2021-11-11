#include <stdio.h>

int main() {
    int mat[201][201], i, j, M, N, k, x, y, br=0;
    do {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d %d", &M, &N);
        if (M<=0 || M>200 || N<=0 || N>200)
            printf ("Brojevi nisu u trazenom opsegu.\n");
    } while (M<=0 || M>200 || N<=0 || N>200); 
printf ("Unesite elemente matrice: ");
for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
        scanf ("%d", &mat[i][j]);
    }
}
/* Izbacivanje istih kolona iz matrice */
for (i=0; i<N; i++){
    for (k=i; k<N-1; k++){
        br=0;
        for (j=0; j<M; j++){
            if (mat[j][i]==mat[j][k+1])
            br++;
        }
        if (br==M) {
            for (x=k; x<N-1; x++){
                for (y=0; y<M; y++){
                    mat[y][x+1]=mat[y][x+2];
                }
            }
        k--;
        N--;
      }
    }
} 
/* Izbacivanje istih redova iz matrice */
for (i=0; i<M; i++){
    for (k=i; k<M-1; k++){
        br=0;
        for (j=0; j<N; j++){
            if (mat[i][j]==mat[k+1][j])
            br++;
        }
        if (br==N) {
            for (x=k; x<M-1; x++){
                for (y=0; y<N; y++){
                    mat[x+1][y]=mat[x+2][y];
                }
            }
        k--;
        M--;
      }
    }
}    
printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf ("%5d", mat[i][j]);
        }
        printf ("\n");
    }
	return 0;
}
