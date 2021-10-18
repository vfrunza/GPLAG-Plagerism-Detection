#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina) {
    int frequency[100] = {0}, holder[100][100], i, j, k, l, m, broj = 0, n = 0;

    for(i=0; i<visina; i++)
        for(j=0; j<sirina; j++)
            holder[i][j] = *(*(matrica+i)+j);

    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            for(m=0; m<=broj; m++) {
                if(holder[i][j] == frequency[m]) continue;
                frequency[n] = holder[i][j];
                n++;
                for(k=0; k<visina; k++) {
                    for(l=0; l<sirina; l++) {
                        if(holder[k][l] == holder[i][j]) frequency[n]++;
                    }
                }
                n++;
            }
        }
    }
    broj = frequency[1];
    m=0;
    for(i=3; i<n; i+=2) {
        if(broj < frequency[i]) {
            if(frequency[m] > frequency[i-1] || frequency[m] == frequency[0]) {
                broj = frequency[i-1];
                m=i-1;
            }
        }
    }
    
    return frequency[m];
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int broj) {
    int brojKolona = 0;
    return brojKolona;
}
int main() {
    int sirina, visina, matrica[100][100], i, j;
     printf("Unesite sirinu i visinu matrice: ");
     scanf("%d %d", &sirina, &visina);
     for(i=0; i<visina; i++) {
         printf("Unesite elemente %d. reda: ", i+1);
         for(j=0; j<sirina; j++) {
             scanf("%d", &matrica[i][j]);
         }

     }
    printf("%d", max(matrica, 3, 4));
    return 0;
}
