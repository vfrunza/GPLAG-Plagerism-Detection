#include <stdio.h>

int main() {
	int i, j,  matA[100][100], matB[100][100], matC[100][100], M, N;
	int nizA[10000], nizB[10000], nizC[10000], sort;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}
	while((M<0 || M>100) || (N<0 || N>100));
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matC[i][j]);
		}
	}
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizA[N*i+j]=matA[i][j];
		}
	}
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizB[N*i+j]=matB[i][j];
		}
	}
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizC[N*i+j]=matC[i][j];
		}
	}
	
	for(i=0; i<M*N-1; i++) {
		for(j=i+1; j<M*N; j++) {
			if(nizA[i]>nizA[j]) {
				sort=nizA[i];
				nizA[i]=nizA[j];
				nizA[j]=sort;
				}
		}
	}
	
	for(i=0; i<M*N-1; i++) {
		for(j=i+1; j<M*N; j++) {
			if(nizB[i]>nizB[j]) {
				sort=nizB[i];
				nizB[i]=nizB[j];
				nizB[j]=sort;
			}
		}
	}
	
	for(i=0; i<M*N-1; i++) {
		for(j=i+1; j<M*N; j++) {
			if(nizC[i]>nizC[j]) {
				sort=nizC[i];
				nizC[i]=nizC[j];
				nizC[j]=sort;
			}
		}
	}
	
	
	for(i=0; i<M*N; i++) {
		
		if(nizA[i]!=nizB[i] || nizA[i]!=nizC[i]) {
			printf("NE");
			return 0;
		}
	}
	printf("DA");

	
	
	return 0;
}
