#include <stdio.h>
#define vel 200
int main() {
	int mat[vel][vel],i,j,M,N;
	int k,l,m,n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		if(M>200 || M<1 || N>200 || N<1) 
			printf("Brojevi nisu u trazenom opsegu.\n");
		}while(M>200 || M<1 || N>200 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
		/*izbacivanje redova*/
	for(i=0; i<M; i++) {
		for(j=i+1; j<M; j++) {
			for(k=0; k<N; k++) {
				if(mat[i][k]!=mat[j][k])
					break;
			}
			if(k==N){
				for(l=j; l<M; l++){
					for(m=l; m<M-1; m++){
						for(n=0; n<N; n++){
							mat[m][n]=mat[m+1][n];
						}
					}
				}
				M--;
				i--;
				break;
			}
		}
	}
	    /*izbacivanje kolona*/
	for(i=0; i<N; i++) {
		for(j=i+1; j<N; j++) {
			for(k=0; k<M; k++) {
				if(mat[k][i]!=mat[k][j])
					break;
			}
			if(k==M){
				for(l=j; l<N; l++) {
					for(m=l; m<N-1; m++) {
						for(n=0; n<M; n++) {
							mat[n][m]=mat[n][m+1];
						}
					}
				}
				N--;
				i--;
				break;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}