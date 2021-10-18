#include <stdio.h>

int main() {
	int M,N,i,j, m,n;
	float A[100][100], B[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &M, &N);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%f", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &m, &n);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			scanf("%f", &B[i][j]);
		}
	}
	

	for(i = 0; i < M; i++) {
		for(j = i+1; j < N; j++) {
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}
	for(i = 0; i < M; i++) {
		for(j=0; j < N/2; j++) {
			int temp = A[i][j];
			A[i][j] = A[i][N-j-1];
			A[i][N-1-j] = temp;
		}
	}
	int test = 0;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			if(A[i][j] != B[i][j]) { test = 0; break; }
			else test = 1;
		}
	}
	if(test == +1) printf("DA\n");
	else printf ("NE\n");
	return 0;
}
