#include <stdio.h>

int main() {
	
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int i, j, M, N;
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	
	}while((M<0) || (N<0) || (M>100) || (N>100));
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		
		for(j=0; j<N; j++){
		
		scanf("%d ", &A[i][j]);
	}
}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		
		for(j=0; j<N; j++){
			
			scanf("%d ", &B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		
		for(j=0; j<N; j++){
			
			scanf("%d ", &C[i][j]);
			
		}
	}
	
	
	return 0;
}
