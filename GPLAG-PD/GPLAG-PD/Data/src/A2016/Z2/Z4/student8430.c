#include <stdio.h>
int main() {
	double mat[100][100]={{0}};
	int i, j, M, N;
	int Teplicova_matrica, Cirkularna_matrica;
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	
		
	} while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	Teplicova_matrica=0;
	Cirkularna_matrica=0;
	for(i=0; i<M-1; i++) {
			for(j=0; j<N-1; j++) {
			if(mat[i][j]==mat[i+1][j+1]) { 
				Teplicova_matrica=1;
				}
				else{ Teplicova_matrica=0;
			
					i=M-1;
					 break;
				}
				}
	}
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
				if((mat[i][j]==mat[i+1][j+1]) && (mat[i][N-1]==mat[i+1][0])) {
				
				Cirkularna_matrica=1;  
				}
				else{ Cirkularna_matrica=0;
					
					i=M-1;
				
					break;
				}
		}
	
	}
		if(M==1)Cirkularna_matrica=1;
		if(N==1)Teplicova_matrica=1;
	if(Teplicova_matrica && Cirkularna_matrica)printf("Matrica je cirkularna");
	else if(Teplicova_matrica) printf("Matrica je Teplicova");
	else if(Cirkularna_matrica) printf("Matrica je cirkularna");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
