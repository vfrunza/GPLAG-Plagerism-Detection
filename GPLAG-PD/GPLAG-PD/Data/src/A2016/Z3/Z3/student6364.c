#include <stdio.h>
#define DUZINA 200
int main() { int M, N, i, j, k, p, q, same;
    int mat[200][200];
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    while (M>200 || N>200 || M<1 || N<1) {
        printf("Brojevi nisu u trazenom opsegu.\n");
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
    } printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
        } 
    } for(i=0; i<M-1; i++) {
       for(j=i+1; j<M; j++) {
        same=1;
        for(k=0; k<N; k++) {
            if(mat[i][k]!=mat[j][k]) {
                same=0;
                break;
            } 
        }    if(same) { 
                if(j==M) {
                M--;
                break;
            }
                for(p=j; p<M-1; p++) {
                    for(q=0; q<N; q++) {
                        mat[p][q]=mat[p+1][q];
                    } 
                } M--;
                 j--;
            }
        }
   } 
   for(i=0; i<N-1; i++) {
       for(j=i+1; j<N; j++) {
           same=1;
           for(k=0; k<M; k++) {
               if(mat[k][i]!=mat[k][j]) {
                   same=0;
                   break;
               } 
            }  if(same) {
                   if(j==N) {
                       N--;
                       break;
                   } for(p=j; p<N-1; p++) {
                       for(q=0; q<M; q++) {
                           mat[q][p]=mat[q][p+1];
                       } 
                   } N--;
                     j--;
               }
           }
        }  printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
            for(i=0; i<M; i++) {
            for(j=0; j<N; j++) 
            printf("%5d", mat[i][j]);
        printf("\n"); 
     }
        
return 0;   
}