#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	
	int M,N, i, j, matrica=2;
	double mat[100][100];
	
	do{
	
	printf("\nUnesite M i N: ");
	scanf ("%d%d", &M, &N);
	
		if (M>0 && M<101 && N>0 && N<101){
			break;
		}
	printf("Pogresan unos!");
	
	} while (M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	} 
	
	if (N==1 && M!=1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(i=0; i<M-1; i++){
			for (j=0; j<N-1; j++){
				if (fabs(mat[i][j]-mat[i+1][j+1])>eps){
					matrica=0;
					break;
				}
				
				if (fabs(mat[i][N-1]-mat[i+1][0])>eps){
						matrica=1;
						break;
			} 
				
			}
		}
	
	if (matrica==2){
		printf("Matrica je cirkularna");
	} else if (matrica==1){
		printf("Matrica je Teplicova");
	}else if (matrica==0){
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
