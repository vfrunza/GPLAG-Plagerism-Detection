#include <stdio.h>

int main() {
	int matrica[200][200], M, N,l, i, j, k, o, n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M<1||M>200 || N<1||N>200){
			printf("Brojevi nisu u trazenom opsegu. \n");}
	}while(M<1||M>200 || N<1||N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		 	scanf("%d",&matrica[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(k=0;k<M-i-1;k++){
			for(j=0;j<N;j++){
			if(matrica[i][j]!=matrica[i+k+1][j]){break;}
			}
			if(j==N){
				for(l=0;l<M-k-i-1;l++){
					for(j=0;j<N;j++){
						matrica[i+k+l+1][j]=matrica[i+k+l+2][j];
					}
				}M--;
				k--;
			}
		}
	}
		for(j=0;j<N-1;j++){
			for(k=0;k<N-j-1;k++){
				for(i=0;i<M;i++){
					if(matrica[i][j]!=matrica[i][j+k+1]){break;}
				}
				if(i==M){
					for(n=0;n<M;n++){
						for(o=0;o<N-k-j-1;o++){
						matrica[n][j+k+1+o]=matrica[n][j+k+2+o];
						}
					}N--;
					k--;
				}
			}
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