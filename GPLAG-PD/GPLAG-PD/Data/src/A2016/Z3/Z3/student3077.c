#include <stdio.h>

int main() {
	int matrica[200][200],i,j,k,l,m,M,N,brojac=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
		if(M<1 || M>200 || N<1 || N>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
 
		for(i=0; i<M; i++){
			for(j=i+1; j<M; j++){
				for(k=0; k<N; k++){
					if(matrica[i][k]==matrica[j][k]) brojac++;
					if(brojac==N){
						for(m=j; m<M; m++){
							for(l=0; l<N; l++){
								matrica[m][l]=matrica[m+1][l];
								brojac=0;
								
							}
						} M--;
						  j--;
					}
				} brojac=0;
			}
		}
		for(i=0; i<N; i++){
			for(j=i+1; j<N; j++){
				for(k=0; k<M; k++){
					if(matrica[k][j]==matrica[k][i]) brojac++;
					if(brojac==M){
						matrica[k][j]=matrica[k+1][j];
						brojac=0;
						N--;
		  	        	j--;
					}
				} brojac=0;
			}
		}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", matrica[i][j]);
		} printf("\n");
	}
	
	return 0;
}
