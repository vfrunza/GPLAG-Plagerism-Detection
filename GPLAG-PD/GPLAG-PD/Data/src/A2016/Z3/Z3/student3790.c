#include <stdio.h>

int main() {
	int M,N;
	int matrica[200][200];
	
	// unos M i N
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>200 || N>200){ 
			printf("Brojevi nisu u trazenom opsegu.\n");}
		
	}
	while(M<1 || N<1 || M>200 || N>200);
	
	// unos matrice 
	
	printf("Unesite elemente matrice: ");
	int i,j,k,l;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	
	// izbacivanje istih redova
	
	int jednakost;
	
	for(i=0;i<M-1;i++){
		for(k=i+1;k<M;k++){
			jednakost=1;
			// trazenje istog reda
			for(j=0;j<N;j++){
				if(matrica[i][j]!=matrica[k][j]){
					jednakost=0;
					break;
				}
			}
			// izbacivanje tog reda uz ocuvanje redoslijeda
			if(jednakost){
				for(l=k;l<M;l++){
					for(j=0;j<N;j++){
						matrica[l][j]=matrica[l+1][j];
					}
				}
				M--;
				k--;
			}
		}
	}
	
	// izbacivanje istih kolona
	
	for(i=0;i<N-1;i++){
		for(k=i+1;k<N;k++){
			jednakost=1;
			// trazenje iste kolone
			for(j=0;j<M;j++){
				if(matrica[j][i]!=matrica[j][k]){
					jednakost=0;
					break;
				}
			}
			//izbacivanje te kolone uz ocuvanje redoslijeda
			if(jednakost){
				for(l=k;l<N;l++){
					for(j=0;j<M;j++){
						matrica[j][l]=matrica[j][l+1];
					}
				}
				N--;
				k--;
			}
		}
	}
	
	// ispis matrice
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}

	

	return 0;
}
