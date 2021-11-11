#include <stdio.h>

int main() {
	
	int M, N, i, j, tep=0; 
	double mat[100][100];
	
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	
	do {
		if((M<1) || (N<1) || (M>100) || (N>100)) {
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		}
		
	} while (M<1 || N<1 || M>100 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
			if(M==1) {
				printf("Matrica je cirkularna ");
				return 0;
			}
			else if((mat[i][j])==(mat[i+1][j+1]) && (mat[i][j+1])==(mat[i+1][j+2]) && (mat[i+1][j])==(mat[i+2][j+1]) && (mat[i][j+2])==(mat[i+1][j+3]) && (mat[i+2][j])==(mat[i+3][j+1])) {
				tep=1;
				break;
			}
			
		}
	}
	
	if(tep==1) {
		printf("Matrica je Teplicova");
	}
	else  {
		printf("Matrica nije ni cirkularna ni Teplicova");
	}

	return 0;
}
