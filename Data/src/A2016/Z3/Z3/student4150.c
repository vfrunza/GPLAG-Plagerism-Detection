#include <stdio.h>
#define vel 200

int izbaci_redove(int niz[vel][vel], int m, int n) {
    int i, j, k, isto = 0, z;
    for (i = 0; i < m - 1; i++) {
        for (k = i+1; k < m; k++) {
            isto = 1;
            for (j = 0; j < n; j++) {
                if (niz[i][j] != niz[k][j]) {
                    isto = 0; 
                    break;
                }
            }
            if (isto == 1) break;
        }
        if (isto == 1) {
            z = k; 
            for (k = z; k < m-1; k++) {
                for (j = 0; j < n; j++) {
                    niz[k][j] = niz[k+1][j];
                }
            }
            m--;
            i--;
        }
    }
    return m;
}
int izbaci_kolone(int niz[vel][vel], int m, int n) {
    int i, j, k, isto = 1, z;
    for (j = 0; j < n-1; j++) {
        for (k = j+1; k < n; k++) {
            isto = 1;
            for (i = 0; i < m; i++) {
                if (niz[i][j] != niz[i][k]) {
                    isto = 0;
                    break;
                }
        }
        if (isto == 1) break;
    }
    if (isto == 1) {
        z = k;
        for (k = z; k < n-1; k++) {
            for (i = 0; i < m-1; i++) {
                niz[i][k] = niz[i][k+1];
            }
        }
        j--;
        n--;
    }
}
return n;
}

int main() {
    int i, j, M, N, niz[vel][vel], m, n;
    do {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d %d", &M, &N);
        if (M <= 0 || M > 200 || N <= 0 || N > 200) printf ("Brojevi nisu u trazenom opsegu.\n");
    } while (M <= 0 || M > 200 || N <= 0 || N > 200);
    printf ("Unesite elemente matrice: ");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf ("%d", &niz[i][j]);
        }
    }
    m = izbaci_redove(niz, M, N);
    n = izbaci_kolone(niz, m, N);
    
    printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf ("%5d", niz[i][j]);
        printf ("\n");
}
return 0;
}