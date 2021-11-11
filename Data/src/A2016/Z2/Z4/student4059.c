#include <stdio.h>

int main() {
	int i, j, M, N, cirkularna = 1, teplicova = 1;
	double matrica[100][100];
	do { 
    	printf("Unesite M i N: ");
    	scanf("%d %d", &M, &N);
    	if(M<=0 || N<=0 || M > 100 || N > 100) 
    		printf("Pogresan unos!\n");
    } while (M<=0 || N<=0 || M > 100 || N > 100);
    printf("Unesite elemente matrice: ");
    for(i = 0; i < M; i++)
    	for(j = 0; j < N; j++)
    		scanf("%lf", &matrica[i][j]);
    if(M == 1 && N == 1) {
    	printf("Matrica je cirkularna");
    	return 0;
    }
    if(M > 1 && N == 1) {
    	printf("Matrica je Teplicova");
    	return 0;
    }
    for(i = 1; i < M; i++) {
        if(matrica[i][0] != matrica[i-1][N-1]) cirkularna = 0;
    	for(j = 1; j < N; j++) {
    	    if(matrica[i][j] != matrica[i-1][j-1]) {
    	        teplicova = 0;
    	        break;
    	    }
    	}
    	if(teplicova == 0) break;
    }
    if(cirkularna && teplicova) printf("Matrica je cirkularna");
    else if(teplicova) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
