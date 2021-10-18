#include <stdio.h>

int main(){
    int matrica[200][200];
    int m, n, i, j, k, l, areSame;
    /* areSame je varijabla koja cuva vrijednost "ekvivalencije" 2 reda/kolone */
    /* UNOS */
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if(m<1 || m>200 || n<1 || n>200){
            printf("Brojevi nisu u trazenom opsegu.\n");
        } else break;
    }while(1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    /* PROVJERA REDOVA */
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            areSame=1;
            for(k=0;k<n;k++){
                if(matrica[i][k]!=matrica[j][k]){
                    areSame=0;
                    break;
                }    
            }
            if(areSame){
                for(k=0;k<n;k++){
                    for(l=j;l<m-1;l++){
                        matrica[l][k]=matrica[l+1][k];
                    }
                }
                m--;
                j--;
            }
        }
    }
    /* PROVJERA KOLONA */
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            areSame=1;
            for(k=0;k<m;k++){
                if(matrica[k][i]!=matrica[k][j]){
                    areSame=0;
                    break;
                }    
            }
            if(areSame){
                for(k=0;k<m;k++){
                    for(l=j;l<n-1;l++){
                        matrica[k][l]=matrica[k][l+1];
                    }
                }
                n--;
                j--;
            }
        }
    }
    /* ISPIS */
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}