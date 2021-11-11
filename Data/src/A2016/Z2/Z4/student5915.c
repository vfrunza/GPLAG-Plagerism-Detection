#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0000001

int main() {
	int M, N, i, j;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M > 100 || N > 100 || M < 1 || N < 1)
		  printf("Pogresan unos!\n");
	} while(M > 100 || N > 100 || M <1 || N < 1);
     printf("Unesite elemente matrice: ");
     for(i = 0; i < M; i++){
     	for(j = 0; j< N; j++)
     		scanf("%lf", &mat[i][j]);
     }
     if(M == 1){
     printf("Matrica je cirkularna");
     return 0;
     }
     if(N == 1){
         printf("Matrica je Teplicova");
         return 0;
     }
     for(i = 0; i < M - 1; i++){
         for(j = 0; j < N - 1; j++){
           if (fabs(mat[i+1][j+1] - mat[i][j]) < EPSILON && fabs(mat[i][N-1] - mat[i+1][0]) < EPSILON){
     		  if(i == M - 2 && j == N - 2){
     			printf("Matrica je cirkularna");
     			return 0;
     		  }
             }
             else {
                 j = N - 1;
                 i = M - 1;
                 }
              }
     }
     for(i = 0; i < M - 1; i++){
         for(j = 0; j < N - 1; j++){
             if(fabs(mat[i+1][j+1] - mat[i][j]) < EPSILON){
                 if(i == M - 2 && j == N - 2)
                 printf("Matrica je Teplicova");
             }
             else{
                 printf("Matrica nije ni cirkularna ni Teplicova");
                 return 0;
             }
         }
     }
    
   return 0;
}
