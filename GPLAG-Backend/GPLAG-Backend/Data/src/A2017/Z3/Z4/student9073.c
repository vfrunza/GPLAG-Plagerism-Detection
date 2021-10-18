#include <stdio.h>
int max (int matrica[100][100], int visina, int sirina)
{
    int ponavljanja[100][100];
    int i,j,k,m,brojac;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            brojac=0;
            for(k=0; k<visina; k++) {
                for(m=0; m<sirina; m++) {
                    if(matrica[i][j]==matrica[k][m]) brojac++;
                }
            }
            ponavljanja[i][j]=brojac;
        }
    }
    int max=ponavljanja[0][0];
    int najmanji=matrica[0][0];
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(ponavljanja[i][j]>max) {
                max=ponavljanja[i][j];
                najmanji=matrica[i][j];
            }
        }
    }
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(ponavljanja[i][j]==max && matrica[i][j]<najmanji) najmanji=matrica[i][j];
        }
    }
    return najmanji;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
    int i,j,k,m;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==n) {
                for(k=0; k<visina; k++) {
                    for(m=j; m<sirina-1; m++) {
                        matrica[k][m]=matrica[k][m+1];
                    }
                }
                sirina--;
                j--;
            }
        }
    }
    return sirina;
}
int main()
{
    int matrica[100][100],visina,sirina,i,j;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    int broj,brojac=0;
    while(sirina>0) {
        brojac++;
        broj=max(matrica, visina, sirina);
        sirina=izbaci_kolone(matrica, visina, sirina, broj);
        printf("\n");
        if (sirina!=0) printf("Nakon %d. prolaza matrica glasi:\n", brojac);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina; j++) {
                printf("%5d", matrica[i][j]);
            }
            printf("\n");
        }

    }
    printf("Nakon %d. prolaza matrica je prazna!", brojac);
    return 0;
}
