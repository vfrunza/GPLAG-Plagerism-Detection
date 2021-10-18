#include <stdio.h>
#include <stdlib.h>
#define n 100
#define m 100
#define x 300

int main() {
	int i, j, A[m][n], B[m][n], C[m][n], Ab[x]={0}, Bb[x]={0}, Cb[x]={0}, t=1, M, N;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}while(M>100 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &C[i][j]);
		}
	}
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			Ab[abs(A[i][j])]++;
		}
	}
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			Bb[abs(B[i][j])]++;
		}
	}
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			Cb[abs(C[i][j])]++;
		}
	}
	for(i = 0; i < x; i++){
			if(Ab[i] != Bb[i] || Ab[i] != Cb[i] || Bb[i] != Cb[i]) t=0;
	}
	if(t == 0) printf("NE\n");
	else printf("DA\n");
	return 0;
}