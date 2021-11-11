#include <stdio.h>

int main(){
    
    int M,N;
    int mat[100][100];
    int i,j,k,x;
    int brojac;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M,&N);
        if(M<=0 || N<=0 || M>200 || N>200)
        printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M>200 || N>200 || M<=0 || N<=0);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(i=0;i<M-1;i++){
        for(j=i+1;j<M;j++){
           brojac=0;
            for(k=0;k<N;k++){
                if(mat[i][k]==mat[j][k])
                brojac++;
            }
            if(brojac==N){
                    for(k=j;k<M-1;k++){
                        for(x=0;x<N;x++){
                            mat[k][x]=mat[k+1][x];
                        }
                    }
                    M--;
                    j--;
            }
        }
    }
    
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
           brojac=0;
            for(k=0;k<M;k++){
                if(mat[k][i]==mat[k][j])
                brojac++;
            }
            if(brojac==M){
                    for(k=j;k<N-1;k++){
                        for(x=0;x<M;x++){
                            mat[x][k]=mat[x][k+1];
                        }
                    }
                    N--;
                    j--;
            }
        }
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}