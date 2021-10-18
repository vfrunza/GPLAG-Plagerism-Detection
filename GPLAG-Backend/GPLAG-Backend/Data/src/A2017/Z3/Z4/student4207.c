#include <stdio.h>
#include<math.h>
int max (int matrica[100][100], int visina, int sirina)
{

    int i=0, j, k, niz_p[10000],br_ponavljanja=1,max=-1,maxclan=1;

    while(i<sirina*visina) {
        for(j=0; j<visina; j++) {
            for(k=0; k<sirina; k++) {
                niz_p[i]=matrica[j][k];
                i++;
            }
        }
    }
    for(i=0; i<visina*sirina; i++) {
        br_ponavljanja=1;
        for(j=i; j<visina*sirina; j++) {
            if(niz_p[i]==niz_p[j]) {
                br_ponavljanja++;
            }
        }
        if(br_ponavljanja>max) {
            max=br_ponavljanja;
            maxclan=niz_p[i];
        }
        if(br_ponavljanja==max) {
            if(niz_p[i]<maxclan) {
                niz_p[i]=maxclan;
            }
        }
    }

    return maxclan;
}
int izbaci_kolone(int matrica[100][100],int visina, int sirina, int N)
{
    int i, j, k, l;
    for(i = 0; i<visina; i++) {
        for(j = 0; j<sirina; j++) {
            if(matrica[i][j] == N) {
                for(k =0; k<visina; k++) {
                    for(l = k; l<sirina-1; l++) {
                        matrica[k][l] = matrica[k][l+1];
                    }
                }
                sirina--;
                j--;
                i=0;
            }

        }

    }

    return sirina;
}

int main()
{
    int matrica[100][100];
    int visina,sirina;
    int i,j;
    int broj,sirina_1,k;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina,&visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d",&matrica[i][j]);
        }
    }
    for(k=0; k<visina; k++) {
        broj = max(matrica, visina, sirina);
        sirina_1 =izbaci_kolone(matrica,visina, sirina, broj);
        if(sirina_1==0) break;
        printf("\nNakon %d. prolaza matrica glasi: \n",k+1);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina_1; j++) {
                printf("%5d",matrica[i][j]);
            }
            printf("\n");
        }
        sirina=sirina_1;
    }
    printf("\nNakon %d. prolaza patrica je prazna!",k+1);

    return 0;
}
