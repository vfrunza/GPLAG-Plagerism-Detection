#include <stdio.h>
#define mat[M][N] 10000
int main() {
int M, N, i, j, k, A, B, C, mat;


do{
    printf ("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    if(M<100 && N<100){
        printf("Unesite brojeve M i N: ");
            scanf("%d %d", &M, &N);
    }
    }
while(M>100 && N>100);
    printf("Unesite clanove matrice A: ");
        for(i=0; i<mat[M][N]; i++){
            scanf("%d", &A);
        }

    printf("Unesite clanove matrice B: ");
        for(j=0; j<mat[M][N]; j++){
            scanf("%d", &B);
        }
    printf("Unesite clanove matrice C: ");
        for(k=0; k<mat[M][N]; k++ ){
            scanf("%d", &C);
        }
    

	return 0;
}
