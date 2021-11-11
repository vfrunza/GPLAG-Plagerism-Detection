#include <stdio.h>

int main(){
    int i,j,matrica[200][200],M,N,x,y,z,s;
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }
    while(M>200 || M<=0 || N>200 || N<=0);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    
    for(i=0;i<M-1;i++){
        for(j=i+1;j<M;j++){
            x=0;
            if(matrica[i][0]==matrica[j][0]){
                x=1;
                for(y=1;y<N;y++){
                    if(matrica[i][y]!=matrica[j][y]) x=0;
                }
                
                if(x==1){
                    for(z=j;z<M-1;z++){
                        for(s=0;s<N;s++){
                            matrica[z][s]=matrica[z+1][s];
                            }
                        }
                    M--;
                    j--;
                    }
                
                }
            }
        }
        
        
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            x=0;
            if(matrica[0][i]==matrica[0][j]){
                x=1;
                for(y=1;y<M;y++){
                    if(matrica[y][i]!=matrica[y][j]) x=0;
                }
                
                if(x==1){
                    for(z=j;z<N-1;z++){
                        for(s=0;s<M;s++){
                            matrica[s][z]=matrica[s][z+1];
                        }
                    }
                N--;
                j--;
                }
            }
            
        }
    }
    
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}
