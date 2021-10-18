#include <stdio.h>

int main() {
	
	int M,N,matA[100][100],matB[100][100],matC[100][100];
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);}
	while(M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",matA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",matB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",matC[i][j]);
		}
	}
}
