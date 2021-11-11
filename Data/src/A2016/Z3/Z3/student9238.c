#include <stdio.h>
#define sirina 200
#define visina 200

int main() {
	int i,j, M, N, mat[200][200];
	do {
		printf("\nUnesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || M<=0 || N>200|| N<=0) printf("Brojevi nisu u trazenom opsegu.");
	} while(M>200 || M<=0 || N>200 || N<=0);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0; i<M; i++) {
		if(mat[i][j]==mat[i][j+2])
		mat[i][j]==mat[i][M-1];
	M--; }
	for(j=0; j<N; j++) {
		if(mat[i][j]==mat[i+2][j])
		mat[i][j]==mat[N-1][j];
	N--; } 
printf("Nakon izbacivanja redova/kolona matrica glasi: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
