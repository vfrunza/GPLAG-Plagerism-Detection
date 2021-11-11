#include <stdio.h>
#define MAXN 210

int main() {
    int n, m;
    int i, j, k, ii, jj;
    int ma[MAXN][MAXN];
    int indeksReda, indeksKolone;
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if (n <= 0 || m <= 0 || n > 200 || m > 200) printf("Brojevi nisu u trazenom opsegu.\n");
    } while (n <= 0 || m <= 0 || n > 200 || m > 200);
    
    
    printf("Unesite elemente matrice: ");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &ma[i][j]);
    }
    for (k = 0; k < m; k++) {
        for (i = 0; i < m; i++) {
            int tacno = 1;
            if (i == k) continue;
            for (j = 0; j < n; j++) {
                //printf("%d, %d = %d\n", i, j, ma[i][j]);
                //printf("%d, %d = %d\n*******\n", k, j, ma[k][j]);
                if (ma[i][j] != ma[k][j]) {
                    tacno = 0;
                    break;
                }
            }
            //printf("GOTOVA JEDNA ITERACIJA \n");
            if (tacno) {
                //printf("Red %d SE SLAZE SA %d\n", k, i);
                for (ii = i; ii < m; ii++)
                    for (jj = 0; jj < n; jj++)
                        ma[ii][jj] = ma[ii + 1][jj];
                m--;
                i--;
            }
            
        }
    }
    for (k = 0; k < n; k++) {
        for (j = 0; j < n; j++) {
            int tacno = 1;
            if (k == j) continue;
            for (i = 0; i < m; i++) {
                //printf("%d %d = %d\n", i, j, ma[i][j]);
                //printf("%d %d = %d\n*****\n", i, k, ma[i][k]);
                if(ma[i][j] != ma[i][k]) {
                    tacno = 0;
                    break;
                }   
            }
            //printf("KRAJ ITERACIJE\n");
            if (tacno) {
                
                for (ii = 0; ii < m; ii++)
                    for (jj = j; jj < n; jj++)
                    ma[ii][jj] = ma[ii][jj + 1];
                n--;
                j--;
            }
        }
    }
        
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i = 0; i < m; i++) {
        printf(" ");
        for (j = 0; j < n; j++)
            printf("%4d ", ma[i][j]);
        printf("\n");
    }
    return 0;
}