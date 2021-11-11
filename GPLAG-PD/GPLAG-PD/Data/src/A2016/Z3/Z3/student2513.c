#include <stdio.h>

int main() {
	int mat[200][200], i, j, k, l, m, M, N, istinitost=1;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
		if(M>200 || N>200 || M<=0 || N<=0)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M>200 || N>200 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	/*Provjera da li se redovi matrice ponavljaju (odozgo prema dole)*/
	for(i=0; i<M; i++){
		for(j=i+1; j<M; j++){
			istinitost=1;
			for(k=0; k<N; k++){
				if(mat[i][k]!=mat[j][k]){
					istinitost=0;
					break;
				}
			}
			/*Izbacuje se iz matrice red koji se ponavlja*/
			if(istinitost==1){
			for(l=j; l<M-1; l++){
				for(m=0 ; m<N; m++){
					mat[l][m]=mat[l+1][m];
				}
			}	
				j--;
				M--;
			}
		}
	}
	/*Provjera da li se kolone matrice ponavljaju s lijeva na desno*/
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			istinitost=1;
			for(k=0; k<M; k++){
				if(mat[k][i]!=mat[k][j]){
					istinitost=0;
					break;
				}
				
			}
		/*Izbacivanje kolona koje se ponavljaju*/
			if(istinitost==1){ 
				for(l=j; l<N-1; l++){
					for(m=0 ; m<M; m++){
						mat[m][l]=mat[m][l+1];
					
					}
				}
				j--;
				N--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
	
	return 0;
}
