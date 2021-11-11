#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int niz[200][200];
    int i=0, j=0, k, p=0, r;
    int M,N;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M>200 || M<=0 || N>200 || N<=0)
        printf("Brojevi nisu u trazenom opsegu. \n");
    } while (M>200 || M<=0 || N>200 || N<=0);
    
    printf("Unesite elemente matrice: ");
    for (i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &niz[i][j]);
        }
    }
    i=0; j=0;
    while(i<M){
        k=i+1;
        while(k<M){
            while(j<N){
                if(niz[i][j]==niz[k][j]) p++;
                j++;
            }
            j=0;
            if(p==N){
                r=k;
                while(r<M){
                    while (j<N){
                        niz[r][j]=niz[r+1][j];
                        j++;
                    }
                    j=0;
                    r++;
                }
                M--;
                k--;
            }
            p=0;
            j=0;
            k++;
        }
        i++;
    }
  
    p=0; r=0;
    i=0; j=0;
    
    while(i<N){
        k=i+1;
        while(k<N){
            while(j<M){
                if(niz[j][i]==niz[j][k]) p++;
                j++;
            }
            j=0;
            if(p==M){
                r=k;
                while(r<N){
                    while(j<N){
                        niz[j][r]=niz[j][r+1];
                        j++;
                    }
                    j=0;
                    r++;
                }
                N--;
                k--;
            }
            p=0;
            j=0;
            k++;
        }
        i++;
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%5d", niz[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}