#include <stdio.h>
#define max_el 100
#define max_br 10000
int main() {
	int M,N,i,j;
	int matA[max_el][max_el], matB[max_el][max_el], matC[max_el][max_el];
	int nizA[max_br],x,brA=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while(M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++)
		scanf("%d ", &matA[i][j]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++)
		scanf("%d ", &matB[i][j]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++)
		scanf("%d ", &matC[i][j]);
	}
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		x=matA[i][j];
    		nizA[brA]=x; 
    		brA++;
    	}
    }
    printf("Niz A: ");
    for(i=0; i<brA; i++)
    printf("%d ", nizA[i]);
	return 0;
}
