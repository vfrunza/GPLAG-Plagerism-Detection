#include <stdio.h>

int main() {
    int M, N, i, j, a, b, c, d, isti=0, matrix[200][200] ;
    
    /*Unos dimenzija matrice */
    
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &M, &N);
        if(M > 200 || M <= 0 || N > 200 || N <= 0){
            printf("Brojevi nisu u trazenom opsegu. \n");
        } 
        else break ;
    } while (M > 200 || M <= 0 || N > 200 || N <= 0) ;
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
   /* Provjerava da li u matrici dimenzije M*N ima jednakih redova. */ 
    
    for(i=0; i<M; i++) {
        for(a=i+1; a<M; a++){
           isti=1;
            for(j=0; j<N; j++){
                if(matrix[i][j]!=matrix[a][j]){
                    isti=0;
                }
            }
            
    /* Izbacivanje jednakih redova matrice dimenzije M*N. */
            
                if(isti==1) {
                    for(b=a+1; b<M; b++) {
                        for(j=0; j<N; j++) {
                            matrix[b-1][j]=matrix[b][j];
                        
                    }
                } 
                
                M--;
                a--;
                    
            }
            
        }
    
    }   
    
    /* Provjerava da li u matrici dimenzije M*N ima jednakih kolona. */
    
    for(j=0; j<N; j++) {
        for(c=j+1; c<N; c++){
            isti=1;
            for(i=0; i<M; i++) {
                if(matrix[i][j]!=matrix[i][c]){
                    isti=0;
                }
            }
    
    /* Izbacivanje jednakih kolona matrice dimenzije M*N. */
    
            if(isti==1) {
                for(d=c+1; d<N; d++){
                    for(i=0; i<M; i++){
                        matrix[i][d-1]=matrix[i][d];
                    }
                }
                
                N--;
                c--;
            }
        }
    }
    
    
    /* Ispisivanje modificirane matrice nakon izbacivanja trazenih redova i kolona. */ 
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    
return 0;

}
    

    
    
    
    
    