#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main() {
    
    int M, N, i, j, k, m, n;
    int mat[VISINA][SIRINA];
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M<1 || M>200 || N<1 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M<1 || M>200 || N<1 || N>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    ovde:
    if(M==1){
        for(i=0; i<N; i++){
            for(j=i+1; j<N; j++){
                if(mat[0][i]==mat[0][j]){
                    for(k=j; k<N-1; k++) mat[0][k]=mat[0][k+1];
                    N--;
                    j--;
                }
            }
        }
    }
    else if(N==1){
        for(i=0; i<M; i++){
            for(j=i+1; j<M; j++){
                if(mat[i][0]==mat[j][0]){
                    for(k=j; k<M-1; k++) mat[k][0]=mat[k+1][0];
                    M--;
                    j--;
                }
            }
        }
    }
    else{
    for(i=0; i<M; i++){
        for(j=i+1; j<M; j++){
            int br=0;
            for(k=0; k<N; k++){
                if(mat[i][k]!=mat[j][k]) break;
                else br++;
                if(br==N){
                    for(m=j+1; m<M; m++){
                        for(n=0; n<N; n++){
                            mat[m-1][n]=mat[m][n];
                        }
                    }
                    M--;
                    j--;
                    if(M==1) goto ovde;
                }
            }
        }
    }
    
    for(i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            int brojac=0;
            for(k=0; k<M; k++){
                if(mat[k][i]!=mat[k][j]) break;
                else brojac++;
                if(brojac==M){
                    for(m=j+1; m<N; m++){
                        for(n=0; n<M; n++){
                            mat[j][n]=mat[m][n];
                        }
                    }
                    N--;
                    j--;
                    if(N==1) goto ovde;
                }
            }
        }
    }
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}