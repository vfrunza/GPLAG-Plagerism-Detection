#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max (int matrica[100][100], int visina, int sirina)
{
    int maxClan, maxBrPon, clanovi[100*100], clanBrPon[100*100], brojac=0, i ,j ,k;
    bool nadjen=false;

    for(k=0; k<visina*sirina; k++)
        clanBrPon[k]=0;

    for(i=0; i<visina; i++)
        for(j=0; j<sirina; j++) {

            for(k=0; k<brojac; k++)
                if(matrica[i][j]==clanovi[k]) {
                    nadjen=true;
                    break;
                }

            if (nadjen) {
                clanBrPon[k]++;
                nadjen=false;
            } else {
                clanovi[brojac]=matrica[i][j];
                clanBrPon[brojac]++;
                brojac++;
            }
        }

    maxClan=clanovi[0];
    maxBrPon=clanBrPon[0];
    for(i=0; i<brojac; i++)
        if(maxBrPon<clanBrPon[i] || (maxBrPon==clanBrPon[i] && maxClan>clanovi[i])) {
            maxClan=clanovi[i];
            maxBrPon=clanBrPon[i];
        }
    return maxClan;
}

    int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
        int i,j,r,k;
        bool nadjen=false;

        for(j=0; j<sirina; j++) {

            for(i=0; i<visina; i++)
                if(matrica[i][j]==n)
                    nadjen=true;

            if(nadjen) {
                for(k=j; k<sirina-1; k++)
                    for(r=0; r<visina; r++)
                        matrica[r][k]=matrica[r][k+1];
                sirina--;
                j--;

                nadjen=false;
            }
        }
        return sirina;

    }

    int main() {
        int sirina=0, visina=0, matrica[100][100], i, j, pr;
        bool tacno=false;

        do {
            printf("Unesite sirinu i visinu matrice: ");
            scanf("%d %d", &sirina, &visina);
            if(sirina<0 || sirina>100 || visina<0 || visina>100)
                printf("Pogresne dimenzije!\n");
            else tacno=true;
        } while(!tacno);

        for(i=0; i<visina; i++) {
            printf("Unesite elemente %d. reda: ", i+1);
            for(j=0; j<sirina; j++)
                scanf("%d",&matrica[i][j]);
        }

        pr=0;
        do {
            sirina= izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
            if (sirina) {
                printf("\nNakon %d. prolaza matrica glasi:\n", pr+1);
                for(i=0; i<visina; i++) {
                    for(j=0; j<sirina; j++)
                        printf("%5d", matrica[i][j]);
                    printf("\n");
                }
            } else
                printf("\nNakon %d. prolaza matrica je prazna!\n", pr+1);
            pr++;
        } while (sirina);

        return 0;

    }
        