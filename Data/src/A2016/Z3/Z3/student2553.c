#include <stdio.h>
int uporedi_nizove(int niz1[],int niz2[],int duzina){
    int i;
    for(i=0;i<duzina;i++){
        if (niz1[i]!=niz2[i]) return 0;
    }
    return 1;
}
int main() {
    int matrica[200][200],M,N,i,j,k,l,niz1[200],niz2[200];
    do{
    printf("Unesite brojeve M i N: ");
    scanf("%d %d",&M,&N);
    if(M>200 || M<1 || N>200 || N<1)
        printf("Brojevi nisu u trazenom opsegu.\n");
    
    }while(M>200 || M<1 || N>200 || N<1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    
    for(i=0; i<M; i++){
        for(k=0;k<N;k++){niz1[k]=matrica[i][k];}
        for(j=i+1;j<M;j++){
            for(k=0;k<N;k++){niz2[k]=matrica[j][k];}
            if(uporedi_nizove(niz1,niz2,N)){
                for(k=j;k<(M-1);k++){
                    for(l=0;l<N;l++){
                        matrica[k][l]=matrica[k+1][l];
                    }
                }
                j--;
                M--;
            }
        }
    }
    
    for(i=0; i<N; i++){
        for(k=0;k<M;k++){niz1[k]=matrica[k][i];}
        for(j=i+1;j<N;j++){
            for(k=0;k<M;k++){niz2[k]=matrica[k][j];}
            if(uporedi_nizove(niz1,niz2,M)){
                for(k=j;k<(N-1);k++){
                    for(l=0;l<M;l++){
                        matrica[l][k]=matrica[l][k+1];
                    }
                }
                j--;
                N--;
            }
        }
    }
    
    
    
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}