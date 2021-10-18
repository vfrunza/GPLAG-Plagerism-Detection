#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int niz[10000], i, j, maax, brojac=0, min, tmp, ponav1=0, ponav2=0;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            niz[brojac]=matrica[i][j];
            brojac++;
        }
    }
    for(i=0; i<brojac; i++) {
        min=i;
        for(j=i+1; j<brojac; j++) {
            if(niz[min]>niz[j]) min=j;
        }
        tmp=niz[i];
        niz[i]=niz[min];
        niz[min]=tmp;
    }
    maax=niz[0];
    for(i=0; i<brojac-1; i++) {
        while(i<brojac-1) {
            if(niz[i]!=niz[i+1]) break;
            ponav1++;
            i++;
        }
        if(ponav2<ponav1) {
            ponav2=ponav1;
            maax=niz[i];
        }
        ponav1=0;
    }
    return maax;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
    int i, j, m, n;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==N) {
                for(m=0; m<visina; m++) {
                    for(n=j; n<sirina-1; n++) {
                        matrica[m][n]=matrica[m][n+1];
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
    /*	printf("Zadaća 3, Zadatak 4");*/
    int visina, sirina, matrica[100][100] = {{0}}, i, j, brojac=0, maax;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    while(1) {
        maax=max(matrica, visina, sirina);
        sirina=izbaci_kolone(matrica, visina, sirina, maax);
        brojac++;
        if(sirina==0) break;
        printf("\nNakon %d. prolaza matrica glasi:\n", brojac);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina; j++) {
                printf("%5d", matrica[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("Nakon %d. prolaza matrica je prazna!\n", brojac);
    return 0;
}
