#include <stdio.h>

#define SIZE 100

int main() {
	int M,N;
	int A[SIZE][SIZE],B[SIZE][SIZE];
	int C[SIZE][SIZE];
	int i,j;
	int BR1,BR2;
	int NIZ[SIZE],NIZ2[SIZE],NIZ3[SIZE];

	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	}while(M>100||N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);	
		}
		
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
		}
		
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&C[i][j]);
		}
		
	}



	
	
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		
			
		}
		
	}

	
	return 0;
}
