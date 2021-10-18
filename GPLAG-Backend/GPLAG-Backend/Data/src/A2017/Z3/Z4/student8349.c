#include <stdio.h>


int main() {

    int n, m, n1, m1;

    printf("Unesi sirinu i visinu matrice A:");
    scanf("%d", &m);
    scanf("%d", &n);

    float matrix[500][500];
    float matrixB[500][500];
    float matrixR[500][500];

    int i,j;

printf("Unesi clanove matrice A: ");
    for(i=0; i < m; i++) {
        for(j=0; j < n; j++) {
            float unos;
            scanf("%f", &unos);
            matrix[i][j] = unos;
        }
    }

    printf("Unesi sirinu i visinu matrice B: ");
    scanf("%d", &m1);
    scanf("%d", &n1);

    i=0;
    j=0;

printf("Unesi clanove matrice B: ");

    for(i=0; i < m1; i++) {
        for(j=0; j < n1; j++) {
            float unos;
            scanf("%f", &unos);
            matrixB[i][j] = unos;
        }
    }

    i=0;
    j=0;

    if(n != n1 || m != m1) {
        printf("NE\n");
    } else if(n == n1 && m == m1) {

        i=0;
        j=0;


        for(i=0; i<m1; i++) {
            for(j=0; j<n1; j++)
                if(matrixB[j][i] != matrixR[j][i]) {
                    printf("NE");
                    return 0;
                }
        }

        printf("DA\n");

    } else {
        printf("NE\n");
    }

    return 0;
}