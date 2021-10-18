/*#include <stdio.h>
int max(int matrica[100][100],int visina, int sirina)
{
    int i,j,k,g,max;
    int brojac=0;
    int brojac1=0;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            brojac=0;
            for(k=0; k<visina; k++) {
                for(g=0; g<sirina; g++) {
                    if(matrica[i][j]==matrica[k][g]) {
                        brojac++;
                    }
                }
            }
            if(brojac==brojac1) {//Ako se neki clanovi matrice ponavljaju isti(najveci) broj puta funkcija vraca onaj manji
                if(matrica[i][j]<max)
                    max=matrica[i][j];
            }
            if (brojac>brojac1) {//Provjeravanje da li se pobrojani element ponovio vise puta od prethodno najvise ponovljenog
                max=matrica[i][j];
                brojac1=brojac;
            }
        }
    }
    return max;
}
int izbaci_kolone(int matrica[100][100],int visina, int sirina, int N)
{
    int i,j,k,g;
    int temp;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==N) {
                for(k=0; k<visina; k++) { //visina nam je fiksna jer hocemo izbaciti kolonu, odnosno mijenjamo "sirinu" matrice
                    for(g=j; g<sirina-1; g++) {
                        temp=matrica[k][g];
                        matrica[k][g]=matrica[k][g+1];
                        matrica[k][g+1]=temp;
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
    int matrica[100][100];
    int visina, sirina,i,j,najveci;
    int brojac=1;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d",&sirina,&visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d",&matrica[i][j]);
        }
    }
    najveci=max(matrica,visina,sirina);
    sirina=izbaci_kolone(matrica,visina,sirina,najveci);
    while(sirina!=0) {
        printf("\nNakon %d. prolaza matrica glasi:\n",brojac);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina; j++) {
                printf("%5d",matrica[i][j]);
            }
            printf("\n");
        }
        brojac++;
        najveci=max(matrica,visina,sirina);
        sirina=izbaci_kolone(matrica,visina,sirina,najveci);
    }
    printf("\nNakon %d. prolaza matrica je prazna!",brojac);
    return 0;
}*/
#include <stdio.h>

int max (int mat[100][100], int visina, int sirina)
{
    int i, j, k, l, brojac1 = 0, brojac2 = 0;
    int max = mat[0][0];

    for(i = 0; i < visina; i++) {
        for(j = 0; j < sirina; j++) {
            brojac1 = 0;
            for(k = 0; k < visina; k++) {
                for(l = 0; l < sirina; l++) {
                    if(mat[i][j] == mat[k][l])
                        brojac1++;
                }
            }
            if(brojac1 == brojac2) {
                if(mat[i][j] < max)
                    max = mat[i][j];
            } else if(brojac1 > brojac2) {
                max = mat[i][j];
                brojac2 = brojac1;
            }
        }
    }
    return max;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int N)
{
    int i, j, k, l, tmp;
    for(i = 0; i < visina; i++) {
        for( j = 0; j < sirina; j++) {
            if(mat[i][j] == N) {
                for(k = 0; k < visina; k++) {
                    for(l = j; l < sirina - 1; l++) {
                        tmp = mat[k][l];
                        mat[k][l] = mat[k][l + 1];
                        mat[k][l + 1] = tmp;
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
    int matrica[100][100];
    int visina, sirina,i,j,najveci;
    int brojac=1;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d",&sirina,&visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d",&matrica[i][j]);
        }
    }
    najveci=max(matrica,visina,sirina);
    sirina=izbaci_kolone(matrica,visina,sirina,najveci);
    while(sirina!=0) {
        printf("\nNakon %d. prolaza matrica glasi:\n",brojac);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina; j++) {
                printf("%5d",matrica[i][j]);
            }
            printf("\n");
        }
        brojac++;
        najveci=max(matrica,visina,sirina);
        sirina=izbaci_kolone(matrica,visina,sirina,najveci);
    }
    printf("\nNakon %d. prolaza matrica je prazna!",brojac);
    return 0;

}
