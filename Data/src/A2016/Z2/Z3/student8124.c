#include <stdio.h>

int main() {

    int n, i, j, x, y;
    int matrica[20][20];

    do {
        printf("Unesite broj tacaka: ");
        scanf("%i", &n);
        if (n < 1 || n > 10)
            printf("Pogresan unos\n");
    } while (n < 1 || n > 10);

    for (i=0; i<=19; i++)
        for (j=0; j<=19; j++)
            matrica[i][j] = 0;

    for (i=1; i<=n; i++) {

        do {
	        printf("Unesite %i. tacku: ", i);
            scanf("%i %i", &x, &y);
            if (x < 0 || x > 19 || y < 0 || y > 19)
                printf("Pogresan unos\n");
        } while (x < 0 || x > 19 || y < 0 || y > 19);

        matrica[x][y] = 1;
    };

    for (j=0; j<=19; j++) {
        for (i=0; i<=19; i++)
            if (matrica[i][j] == 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }

    return 0;
}