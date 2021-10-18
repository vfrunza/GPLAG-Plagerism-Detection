#include <stdio.h>
#define BROJ_EL 10000

int max(int matrica[100][100], int visina, int sirina)
{
    int i, j, k, duzina, vrijednost, niz1[BROJ_EL], niz2[BROJ_EL], mjesto, max_pon, max_br, brojac;

    for(i=0; i<BROJ_EL; i++) {
        niz1[i]=0;
        niz2[i]=0;
    }
    duzina=0;
    brojac=0;
    vrijednost=1;

    /*U niz1[] upisujemo sve clanove matrice koji su razliciti, u niz2[] upisujemo broj njihovih ponavljanja */
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            for(k=0; k<duzina; k++) {
                if(matrica[i][j]==niz1[k]) {
                    vrijednost=0;
                    mjesto=k;
                    break;
                }
            }
            if(vrijednost==0) niz2[mjesto]++;
            else {
                niz1[duzina]=matrica[i][j];
                niz2[duzina]++;
                duzina++;
            }
            vrijednost=1;
        }
    }

    max_pon=niz2[0];
    max_br=niz1[0];
    for(i=0; i<duzina; i++) {
        if(niz2[i]>=max_pon) {
            max_pon=niz2[i];
            max_br=niz1[i];
        }
    }
    for(i=0; i<duzina; i++) {
        if(niz2[i]==max_pon) {
            brojac++;
            max_br=niz1[i];
        }
    }

    if(brojac==1) return max_br;
    else {
        for(i=0; i<duzina; i++) {
            if(niz2[i]==max_pon) {
                if(niz1[i]<max_br) max_br=niz1[i];
            }
        }
    }

    return max_br;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int max_br)
{
    int i, j, k, p;
    
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==max_br) {
                for(k=0; k<visina; k++) {
                    for(p=j; p<sirina-1; p++) {
                        matrica[k][p]=matrica[k][p+1];
                    }
                }
                j--;
                sirina--;
            }
        }
    }
    
    return sirina;
}

int main()
{
    int matrica[100][100], visina, sirina, i, j, brojac=0, max_br, kolone;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);

    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    kolone=sirina;
    do {
        max_br=max(matrica,visina,kolone);
        kolone=izbaci_kolone(matrica,visina,kolone,max_br);
        brojac ++;

        if(kolone==0) printf("\nNakon %d. prolaza matrica je prazna!", brojac);
        else {
            printf("\nNakon %d. prolaza matrica glasi:\n", brojac);
            for(i=0; i<visina; i++) {
                for(j=0; j<kolone; j++) {
                    printf("%5d", matrica[i][j]);
                }
                printf("\n");
            }
        }
    } while(kolone>0);

    return 0;
}