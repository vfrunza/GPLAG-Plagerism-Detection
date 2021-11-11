#include <stdio.h>

int main() {
	int M,N,i,j,cirkularna=1,Teplicova=1;
	float matrica[100][100];
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
			
		}
		
	} while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i< M; i++) {
		for(j=0; j<N; j++) {
			scanf("%f", &matrica[i][j]);
			
		}
	}
		for(i=1; i<M; i++) {
			for(j=0; j<N;j++) {
				if(j==0) {
					if((matrica[i][0]) != (matrica[i-1][N-1])) {
						cirkularna =0;
						break;
						
					}
				} else {
					if((matrica[i][j])!= (matrica[i-1][j-1])) {
						cirkularna=0;
						break;
						
					}
				}
			}
		}
		for(j=0; j<(N-1); j++) {
			for(i=1; ((i<M)&& ((j+i)<N)); i++) {
				if (matrica[0][j]!=matrica[i][j+1]) {
					Teplicova=0;
					break;
					
				}
					
				}
			}
			if(cirkularna==1) {
				printf("Matrica je cirkularna\n");
				
			} else if (Teplicova ==1 ) {
				printf("Matrica je Teplicova\n");
				
			} else {
				printf("Matrica nije ni cirkularna ni Teplicova\n");
				
			}
		
	
	
	return 0;
}
