#include <stdio.h>
#include <stdlib.h>

int main(){
    int M,N,mat[100][100];
    int i,j,k,l,m;
    int brojac=0;
    int niz[100];
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M,&N);
        if(M<1 || M>200 || N<1 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M<1 || M>200 || N<1 || N>200);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
        }
        
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            niz[j]=mat[i][j];
        }
        for(j=i+1;j<M;j++){
            for(k=0;k<N;k++){
                if(niz[k]==mat[j][k]) 
                brojac++;
               
            } 
            //printf("%d ",brojac);
                if(brojac==N){
                    for(l=j+1;l<M;l++){
                        for(m=0;m<N;m++){
                            mat[l-1][m]=mat[l][m];
                        }}
                        M--;
                        j--;
                    }
                
                brojac=0;
            }
        }
        
    brojac=0;
   
    for(j=0;j<N;j++){
        
        for(i=0;i<M;i++){
            niz[i]=mat[i][j];
        }
        for(i=j+1;i<N;i++){
            for(k=0;k<M;k++){
                if(niz[k]==mat[k][i]) brojac++;
            }
           
            if(brojac==M){
         
                for(l=i+1;l<N;l++){
                    for(m=0;m<M;m++){
                     mat[m][l-1]=mat[m][l];
                   
                    }
                    
                }
                N--;
                i--;
            }
            brojac=0;
        }
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
 
    
    
    return 0;
}