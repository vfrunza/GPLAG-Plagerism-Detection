#include <stdio.h>

int main() {

    int i, j, m, n, x;
    double matrica[100][100]; // matrica[0..m redovi][0..n kolone]
    int cirkularna, teplecova;

    do {
        printf("Unesite M i N: ");
        scanf("%i %i", &m, &n); // m = broj redova, n = broj kolona
        if (n < 1 || n > 100 || m < 1 || m > 100)
            printf("Pogresan unos!\n");
    } while (n < 1 || n > 100 || m < 1 || m > 100);


    printf("Unesite elemente matrice: ");
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf("%lf", &matrica[i][j]);

/*  // zakomentarisana proba stampe matrice
    printf("Matrica:\n");
    for (i=0; i<m; i++) {
        printf("\n");
        for (j=0; j<n; j++)
            printf("%i,", matrica[i][j]);
    }
    printf("\n");
*/

    // provjera da li je cirkularna
    cirkularna = 1;

    if (m > 1) {
        i = 1;
        while (i <= m - 1 && cirkularna == 1) {
            j = 1;
            while (j <= n && cirkularna == 1) {

                if (j == n)
                    x = 1;
                else
                    x = j + 1;

                if (matrica[i-1][j-1] != matrica[i][x-1])
                    cirkularna = 0;
                
                j++;
            }
        i++;
        }
    }

    if (cirkularna == 1) {
        printf("Matrica je cirkularna");
        return 0;
    }

    // provjera da li je Teplecova
    teplecova = 1;

    i = 1;
    while (i <= m && teplecova == 1) {
        j = 0;
        while (i+j < m && j+1 < n && teplecova == 1) {
            if (matrica[i+j-1][j] != matrica[i+j][j+1])
                teplecova = 0;
                
                j++;
        }
        i++;
    }

    i = 1;
    while (i <= n && teplecova == 1) {
        j = 0;
        while (i+j < n && j+1 < m && teplecova == 1) {
            if (matrica[j][i+j-1] != matrica[j+1][i+j])
                teplecova = 0;
                
                j++;
        }
        i++;
    }

    if (teplecova == 1) {
        printf("Matrica je Teplicova");
        return 0;
    }


    printf("Matrica nije ni cirkularna ni Teplicova");

    return 0;
}
