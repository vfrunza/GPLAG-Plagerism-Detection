#include <stdio.h>

int main() {
	
	int M,N,i,j,k,l,m,mat[200][200],brojac=1;
	
	do{
		printf("\nUnesite brojeve M i N: ");
		scanf ("%d%d", &M,&N);
		if (M<=0 || M>200 || N<=0 || N>200){
			printf("Brojevi nisu u trazenom opsegu.");
		}
	} while(M<=0 || M>200 || N<=0 || N>200);
	
    printf("Unesite elemente matrice: ");
    
    	for (i=0; i<M; i++){
    		for(j=0; j<N; j++){
    			scanf("%d", &mat[i][j]);
    		}
    	}
	
		for (i=0; i<M-1; i++){
			for (m=i+1; m<M; m++){
				for (j=0; j<N; j++){
					if (mat[i][j]!=mat[m][j]) brojac = 0;
				}
				if (brojac == 1){
					for (k=m+1; k<M; k++){
						for (l=0; l<N; l++){
							mat[k-1][l] = mat[k][l];
						}
					}
					M--;
					m--;
				}
				brojac = 1;
			}
		}
		
		brojac = 1;
		for (i=0; i<N-1; i++){
			for (m=i+1; m<N; m++){
				for (j=0; j<M; j++){
					if (mat[j][i]!=mat[j][m]) brojac = 0;
				}
				if (brojac == 1){
					for (k=m+1; k<N; k++){
						for (l=0; l<M; l++){
							mat[l][k-1] = mat[l][k];
						}
					}
					N--;
					m--;
				}
				brojac = 1;
			}
		}
		
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	 for (i=0; i<M; i++){
	 	for (j=0; j<N; j++){
	 		printf("%5d", mat[i][j]);
	 	}
	 	printf("\n");
	 }
	
	return 0;
}
