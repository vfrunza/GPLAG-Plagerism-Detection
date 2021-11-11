#include <stdio.h>
int main() {
	int M, N, i, j, k, l, m, n, mat[200][200], red[200], kolona[200], kontrolareda=1, kontrolakolone=1;                            
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
		if(M<=0 || M>200 || N<=0 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			red[j]=mat[i][j];
		}
		for(k=i+1; k<M; k++) {
			for(l=0; l<N; l++) {
				if(red[l]!=mat[k][l]){
					kontrolareda=0;
					break;     
				}
				else kontrolareda=1;
			}
			if(kontrolareda) {
				for(m=k; m<M-1; m++) {
					for(n=0; n<N; n++) {
						mat[m][n]=mat[m+1][n];
					}
				}
				M--;
				k--;
			}
		}
	}
	if(M==1) {
		for(i=0; i<M; i++) {
			for(j=0; j<N; j++) {
				red[j]=mat[i][j];
			}
		}
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(red[i]==red[j]){
					for(k=j; k<N-1; k++) {
						red[k]=red[k+1];
					}
					N--;
					j--;
				}
			}
		}
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0; i<N; i++) 
			printf("%5d", red[i]);
		return 0;
	}
	for(i=0; i<N; i++) {
		for(j=0; j<M; j++) {
			kolona[j]=mat[j][i];
		}
		for(k=i+1; k<N; k++) {
			for(l=0; l<M; l++) {
				if(kolona[l]!=mat[l][k]){
					kontrolakolone=0;
					break;
				}
				else kontrolakolone=1;
			}
			if(kontrolakolone) {
				for(m=k; m<N-1; m++) {
					for(n=0; n<M; n++) {
						mat[n][m]=mat[n+1][m];
					}
				}
				N--;
				k--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
