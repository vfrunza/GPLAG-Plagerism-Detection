#include <stdio.h>

int main() {
    int matrica[200][200], i, j, k, l, m, n,pret,pret1,p;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if(m<=0||n<=0||m>200||n>200) 
            printf("Brojevi nisu u trazenom opsegu.\n");
    } 
    while(m<=0||n<=0||m>200||n>200); // petlja osigurava da su brojevi u trazenom opsegu
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&matrica[i][j]);
    for(i=0;i<m;i++){
        for(k=i+1;k<m;k++){ 
            pret=1;
            for(j=0;j<n;j++){
                if(matrica[i][j]!=matrica[k][j]) pret=0; //ispitujemo da li su redovi matrice jednaki
            } 
            if(pret==1){ //izbacivanje jednakog reda matrice
                for(l=k;l<m-1;l++){
                    for(p=0;p<n;p++)
                        matrica[l][p]=matrica[l+1][p];
                }
                m--;
                k--;
            }
        }
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            pret1=1;
            for(j=0;j<m;j++){
                if(matrica[j][i]!=matrica[j][k]) pret1=0; //ispitujemo da li su kolone matrice jednake
            }
            if(pret1==1){//izbacivanje jednake kolone matrice
                for(l=k;l<n-1;l++){
                    for(p=0;p<m;p++)
                        matrica[p][l]=matrica[p][l+1];
                }
                    n--;
                    k--;
            }
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%5d",matrica[i][j]);
        printf("\n");
    }
    return 0;
}
