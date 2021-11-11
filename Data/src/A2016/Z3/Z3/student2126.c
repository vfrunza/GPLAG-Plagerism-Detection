#include <stdio.h>

int main(){
		int M, N, Q;
		int matrica[201][201];
		do{
			printf("Unesite brojeve M i N: ");
			scanf("%d %d", &M, &N);
			if(N<=0 || N>200 || M<=0 || M>200){
				printf("Brojevi nisu u trazenom opsegu.\n");
			}
		}while(N<=0 || N>200 || M<=0 || M>200);
	
	int i, j;
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	while(1){
		int pr;
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				Q=1;
				for(pr=0;pr<M;pr++){
					if(matrica[pr][i]!=matrica[pr][j]){
						Q=0;
					}
				}
				if(Q){
					int A,B;
					for(B=j;B<N-1;B++){
						for(A=0;A<M;A++){
							matrica[A][B]=matrica[A][B+1];
						}
					}
					N--;
					j--;
				}
			}
		}
		for(i=0;i<M;i++){
			for(j=i+1;j<M;j++){
				Q=1;
				for(pr=0;pr<N;pr++){
					if(matrica[i][pr]!=matrica[j][pr]){
						Q=0;
					}
				}
				if(Q){
					int A,B;
					for(B=j;B<M-1;B++){
						for(A=0;A<N;A++){
							matrica[B][A]=matrica[B+1][A];
						}
					}
					M--;
					j--;
				}
			}
		}
		break;
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
	
		}
	
	return 0;
}
