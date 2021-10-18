#include <stdio.h>

int main() {
    int i,j,i2,j2,i3,j3,duzina,sirina,red_izbaci,kolona_izbaci,brojac,matrica[200][200];
    /*unos dimenzija matrice*/
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d", &sirina);
        scanf("%d", &duzina);
        if (duzina<1 || duzina>200 || sirina<1 || sirina>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    } while (duzina<1 || duzina>200 || sirina<1 || sirina>200);
    printf("Unesite elemente matrice: ");
    for (i=0; i<sirina; i++) {
        for (j=0; j<duzina; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    /*pronalazenje i izbacivanje redova koji se ponavljaju*/
    for (i=0; i<sirina; i++) {
        for (i2=i+1; i2<sirina; i2++) {
            brojac=0;
            if (i2==i)
                continue;
            /*uporedjivanje redova*/
            for (j=0; j<duzina; j++) {
                if (matrica[i][j]==matrica[i2][j]) {
                    red_izbaci=i2;
                    brojac++;
                }
            }
            /*izbacivanje reda iz matrice*/
            if (brojac==j && i<i2) {
                for (i3=red_izbaci; i3<sirina-1; i3++) {
                    for (j3=0; j3<duzina; j3++) {
                        matrica[i3][j3]=matrica[i3+1][j3];
                    }
                }
                sirina--;
                i2--;
            }
        }
    }

    /*pronalazenje i izbacivanje kolona koje se ponavljaju*/
    for (j=0; j<duzina; j++) {
        for (j2=j+1; j2<duzina; j2++) {
            brojac=0;
            if (j2==j)
                continue;
            /*uporedjivanje kolona*/
            for (i=0; i<sirina; i++) {
                if (matrica[i][j]==matrica[i][j2]) {
                    kolona_izbaci=j2;
                    brojac++;
                } 
            }
            /*izbacivanje kolone iz matrice*/
            if (brojac==i && j<j2) {
                for (i3=0; i3<sirina; i3++) {
                    for (j3=kolona_izbaci; j3<duzina-1; j3++) {
                        matrica[i3][j3]=matrica[i3][j3+1];
                    }
                }
                duzina--;
                j2--;
            }
        }
    }

    /*ispis promijenjene matrice*/
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i=0; i<sirina; i++) {
        for (j=0; j<duzina; j++) {
            printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}
