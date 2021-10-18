#include <stdio.h>

int main() { 
    double mat[100][100];
    int teplicova=1, is_circ=1, M, N;
    int i, j, sljedeci;
    do { 
        printf("Unesite M i N: ");
        scanf("%d %d", &M, &N);
        { if(M<=0 || M>100 || N<=0 || N>100)
        printf("Pogresan unos!\n"); }
        }
     while (M<=0 || M>100 || N<=0 || N>100); 
     printf("Unesite elemente matrice: "); 
     for(i=0; i<M; i++) {
         for(j=0; j<N; j++) {
             scanf("%lf", &mat[i][j]);
         }
     } for(i=0; i<M-1; i++) {
         for(j=0; j<N-1; j++) {
         if(mat[i][j]!=mat[i+1][j+1])
         teplicova=0;
         }
     } 
     for (i=0; i<M-1; i++) {
         for (j=0; j<N; j++) {
             sljedeci=j+1;
             if(sljedeci == N) sljedeci=0;
             if(mat[i][j]!=mat[i+1][sljedeci]) is_circ=0;
         }
     }
     
     if(is_circ==1) printf("Matrica je cirkularna");
     else if(teplicova==1 && is_circ==0) printf("Matrica je Teplicova");
     else printf("Matrica nije ni cirkularna ni Teplicova");
        
	return 0;
}
