#include <stdio.h>
int max(int matrica[100][100],int visina, int sirina)
{
    int i,j,k,l;
    int max_vr=matrica[0][0];
    int br=0;
    int max_brojac=0,trenutni;
    int matpr[100][100];

    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            matpr[i][j]=0;
        }
    }

    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            if (matpr[i][j]==0) {
                trenutni=matrica[i][j];
                br=0;
                for (k=0; k<visina; k++) {
                    for (l=0; l<sirina; l++) {
                        if (matrica[k][l]==trenutni) {
                            br++;
                            matpr[k][l]=1;
                        }
                    }
                }
                if (br>=max_brojac) {
                    if(br==max_brojac) {
                        if (trenutni<max_vr) {
                            max_vr=trenutni;
                        }
                    } else {
                        max_brojac=br;
                        max_vr=trenutni;
                    }
                }
            }
        }

    }
    return max_vr;

}
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
    int i, j, k, l, pom;
    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            if (matrica[i][j]==N) {
                for (k=0; k<visina; k++) {
                    for (l=j; l<sirina-1; l++) {
                        matrica[k][l]=matrica[k][l+1];
                    }
                }
                j--;
                sirina--;
            }
        }
    }

    return sirina;
}

void printaj(int matrica[100][100], int visina, int sirina)
{
    int i, j;
    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            printf ("%5.d", matrica[i][j]);
        }
        printf ("\n");
    }
}


int main()
{
    int i,j,visina,sirina,N, t=1;
    int matrica [100][100];
    printf ("Unesite sirinu i visinu matrice: ");
    scanf ("%d %d", &sirina, &visina);
    for (i=0; i<visina; i++) {
        printf ("Unesite elemente %d. reda: ", i+1);
        for (j=0; j<sirina; j++) {
            scanf ("%d", &matrica[i][j]);
        }
    }

    while(sirina!=0) {
        N = max(matrica, visina, sirina);
        sirina = izbaci_kolone(matrica, visina, sirina, N);
        if(sirina==0) {
            printf ("\nNakon %d. prolaza matrica je prazna!", t);
            break;
        } else {
            printf ("\nNakon %d. prolaza matrica glasi:\n", t);
            printaj(matrica, visina, sirina);
        }
        t++;
    }

    return 0;
}
