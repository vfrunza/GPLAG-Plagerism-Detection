#include <stdio.h>

int main() {
    int i, j, M=0, N=0, mat[200][200], x, jednaki=1, y, a, b;
    
/* unos granica */

    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M, &N);
        if(M>200 || N<=0 || M<=0 || N>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M>200 || N<=0 || M<=0 || N>200);

/* unos matrice */
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
/* prolazimo kroz redove */

    for(i=0; i<M; i++){
        for(x=i+1; x<M; x++){
            jednaki=1;
            /* pretpostavljamo da su jednaki elementi redova, pokusavamo dokazati suprotno */
            for(j=0; j<N; j++){
                if(mat[i][j]!=mat[x][j]){
                        jednaki=0;
                            }
                     }
                     /* izbacivanje */
                     if(jednaki==1){
                for(y=x; y<M-1; y++){ 
                    for(j=0; j<N; j++){
                    mat[y][j]=mat[y+1][j];
                        }
                    }
                   M--; 
                   x--;
                }
              
        }
 }
 
 /* prolazimo kroz kolone */
 
     for(j=0; j<N; j++){
        for(a=j+1; a<N; a++){
            jednaki=1;
            /* pretpostavljamo da su jednaki elementi kolona, pokusavamo dokazati suprotno */
            for(i=0; i<M; i++){
                if(mat[i][j]!=mat[i][a]){
                        jednaki=0;
                            }
                     }
                     /* izbacivanje */
                     if(jednaki==1){
                for(b=a; b<N-1; b++){ 
                    for(i=0; i<M; i++){
                    mat[i][b]=mat[i][b+1];
                        }
                    }
                   N--; 
                   a--;
                }
        }
 }
 
 /* ispis */ 
 
 printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    
return 0;
}