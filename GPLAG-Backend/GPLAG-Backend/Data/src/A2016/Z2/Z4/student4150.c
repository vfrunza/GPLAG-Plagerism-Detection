#include <stdio.h>
#define vel 100
int main() {
	int M,N,i,j, teplicova = 1, cirkularna = 1; 
	double matrica[vel][vel] = {};
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	}
		while(M<=0 || M>100 || N<=0 || N>100);
		 
		printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
			for(j=0;j<N;j++) {
				scanf("%lf", &matrica[i][j]);
			}
	}
		for(i=0;i<M-1;i++) {
		for(j=0;j<N;j++) {
			
	if(j==N-1) {
		if(matrica[i][j] != matrica[i+1][0]) cirkularna=0;
	}
		else {
			if(matrica[i][j] != matrica[i+1][j+1]) teplicova=0;
	}
		}
		}
		
		if(cirkularna==1 && teplicova==1)  {
			printf("Matrica je cirkularna");
			return 0;
		}
		if (teplicova) {
		printf("Matrica je Teplicova");
		return 0;
}
	if (teplicova == 0) {
		printf ("Matrica nije ni cirkularna ni Teplicova");
	}

			
		return 0;
	}
