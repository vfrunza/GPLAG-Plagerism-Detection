#include <stdio.h>

int main (){
    
    int matA[100][100],matB[100][100],matC[100][100],M,N,i,j,m,n,jednake1=0,jednake2=0,jednake3=0, jednake;
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M,&N);
    }while ((M<0 || M>100) && (N<100 || N>00)); 
        
        printf("Unesite clanove matrice A: ");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &matA[i][j]);
            }
        }
        printf("Unesite clanove matrice B: ");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &matB[i][j]);
            }
        }
        printf("Unesite clanove matrice C: ");
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &matC[i][j]);
            }
        }
         for(i=0; i<M; i++){
             for(j=0; j<N; j++){
                  for(m=0; m<M; m++){
                      for(n=0; n<N; n++){
                          if(matA[i][j]==matA[m][n]) 
                          jednake1++;
                  }
                }
                for(m=0; m<M; m++){
                    for(n=0; n<N; n++){
                        if(matA[i][j]==matB[m][n])
                        jednake2++;
                    }
                }
                for(m=0; m<M; m++){
                    for(n=0; n<N; n++){
                        if(matA[i][j]==matC[m][n]) 
                        jednake3++;
                    }
                }
                 jednake=1;
                if(jednake1!=jednake2 || jednake1!=jednake3 || jednake2!=jednake3)
                jednake=0;
                break;
             }
           }
         
   if(jednake) printf("DA");
    else printf("NE");
         
         return 0;
        
        
    }
    
    
    
    
