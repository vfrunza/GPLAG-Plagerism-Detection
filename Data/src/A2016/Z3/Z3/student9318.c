#include <stdio.h>

int main (){
    int mat[200][200]={{0}},i=0,j=0,M=0,N=0,k=0,p=0,h=0,isti;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M,&N);
        if(M<1 || N<1 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M<1 || N<1 || M>200 || N>200);
        printf("Unesite elemente matrice: ");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &mat[i][j]);
            }
        }        for(j=0; j<N; j++){
            for(i=j+1; i<N; i++){
                isti=1;
                for(k=0; k<M; k++){
                    if(mat[k][j]!=mat[k][i]){ isti=0; break; }
            }
                if(isti==1){
                    for(p=i; p<(N-1); p++){
                        for(h=0; h<M; h++){
                         mat[h][p]=mat[h][p+1];
                    }
                } 
                N--;
                i--;
            }
        }
    }
        
       
    for(i=0; i<M; i++){
        for(j=i+1; j<M; j++){
            isti=1;
            for(k=0; k<N; k++){
                if(mat[i][k]!=mat[j][k]){ isti=0; break; }
            }
                if(isti==1){
                    for(p=j; p<(M-1); p++){
                        for(h=0; h<N; h++){
                            mat[p][h]=mat[p+1][h];
                        }
                    }
                    M--;
                    j--;
                }
            }
        } 
        
         printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                printf("%5d", mat[i][j]);
            }printf("\n");
        }
   
    
    return 0;
}