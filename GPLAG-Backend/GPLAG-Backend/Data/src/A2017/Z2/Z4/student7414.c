#include <stdio.h>

int main() {
	int M,N,A[100][100],B[100][100],C[100][100],i,j,k,l,brojac,pom,brojac_b,brojac_c;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
	}while(M< 0 || N < 0 || M >100 || N > 100);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			scanf("%d",&A[i][j]);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			scanf("%d",&B[i][j]);
			printf("Unesite clanove matrice C: ");
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			scanf("%d",&C[i][j]);
	
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			pom = A[i][j];
			brojac=0;
			brojac_b=0;
			brojac_c=0;
			for(k = 0; k < M; k++){
				for(l = 0; l < N; l++){
					if(pom == A[k][l])brojac++;
					if(pom == B[k][l])brojac_b++;
					if(pom == C[k][l])brojac_c++;
				}
			}
			if(brojac != brojac_b || brojac_c != brojac_b || brojac != brojac_c){printf("NE");return 0;}
		}
	}
	
	printf("DA");
	return 0;
}
