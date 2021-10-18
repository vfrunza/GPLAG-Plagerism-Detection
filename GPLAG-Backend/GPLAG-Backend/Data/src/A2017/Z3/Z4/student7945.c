#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
    int N,i,j,br, brojac[10][10]={0};
    
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            brojac[i][j]++;
        }
    }
    br=brojac[0][0];
    
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if( br < brojac[i][j] ){
                br=brojac[i][j];
                N=matrica[i][j];
            }
        }
    }
    return N;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N) {
    int i,j,br_kolona=0,indeks=0;
    
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if(matrica[i][j]==N){
                indeks=j;
            }
        }
    }
    for(i=0; i<visina; i++){
        matrica[i][indeks]=matrica[i][sirina-1];
    }
    br_kolona=sirina-1;
    
    return br_kolona;
}

int main() {
    int matrica[100][100],sirina,visina,i,j,k;
    
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    
    /*Unos matrice */
    for(i=0; i<visina; i++){
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<sirina; j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    
    /*Ispis modificirane matrice */
    for(k=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina)); k>0; k--){
        printf("\nNakon  prolaza matrica glasi: " );
        for(i=0; i<visina; i++){
            printf("\n");
            for(j=0; j<izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina)); j++){
                printf("%d ", matrica[i][j]);
            }
        }
    }
    
    return 0;
}