#include <stdio.h>

int main() {
	
	int M, N, p=1, i=0, j=0, k=0, l=0, t=1,m=0, mat[200][200];
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d" "%d", &M, &N);
		
		if(M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
		scanf("%d", &mat[i][j]);
	}
	
	
	//REDOVI
	
	for(i=0; i<M-1; i++) {
		for(j=i+1; j<M; j++) {
			p=1;
			for(k=0; k<N; k++) {
				
				if(mat[i][k]!=mat[j][k]) { 
					p=0;
					break;
				}
			}
				
				if(p==1) {
					for(l=j; l<M-1; l++) {
						for(m=0; m<N; m++) {
						mat[l][m]=mat[l+1][m];
						}
						
					}
				M--;
				j--;
				}
				
			}
		} 
	
	// KOLONE
	
	for(i=0; i<N-1; i++) {
		for(j=i+1; j<N; j++) {
			t=1;
			for(k=0; k<M; k++) {
			//	t=1;
				if(mat[k][i]!=mat[k][j]) { 
					t=0;
					break;
				}
			}
				if(t==1) {
					for(l=j; l<N-1; l++) {
						for(m=0; m<M; m++){
								mat[m][l]=mat[m][l+1];
						}
					}
				N--;
				j--;
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
