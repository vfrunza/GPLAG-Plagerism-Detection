#include<stdio.h>

    int main(){
    int ponovo, M, N, i, j, k, brisanje=1, niz[200][200];
    
        do{
            ponovo=0;
            printf("Unesite brojeve M i N: ");
            scanf("%d %d", &M, &N);
            if(M>200 || N>200 || M<1 || N<1){
                printf("Brojevi nisu u trazenom opsegu.\n");
                ponovo=1;
            }
        } while(ponovo!=0);
  
  
  
    printf("Unesite elemente matrice: ");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &niz[i][j]);
            }
        }
  
        for(i=0; i<M; i++){
            for(k=i+1; k<M; k++){
                for(j=0; j<N; j++){
                    if(niz[i][j]==niz[k][j]) brisanje=1;
                    else {brisanje=0; j=N;}
              
                } 
                if(brisanje==1){
                    for(; k<M; k++){
                        for(j=0; j<N; j++){
                            niz[k][j]=niz[k+1][j];
                        }
                    } M--; i--;
                }
            }
        }
  
  
  
        for(j=0; j<N; j++){
            for(k=j+1; k<N; k++){
                for(i=0; i<M; i++){
                    if(niz[i][j]==niz[i][k]) brisanje=1;
                    else {brisanje=0; i=M;}
              
        
                }
                    if(brisanje==1){
                        for(; k<N; k++){
                            for(i=0; i<M; i++){
                                niz[i][k]=niz[i][k+1];
                            }
                        } N--; j--;
                    }
            }
        }
        
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                printf("%5d", niz[i][j]);
            }printf("\n");
        }
  
        return 0;
    }