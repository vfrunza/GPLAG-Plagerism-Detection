#include <stdio.h>

int main() {
	
	int M,N,tep=0,circ=0;
	int i,j;
	double matrica[100][100];
	while(1) {
		
	
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M>100 || M<=0 || N>100 || N<=0) {
			printf("Pogresan unos!\n");
				continue; 
		}
		else break;
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%lf", &matrica[i][j]);
		}
	}
	for(i=0;i<M-1;i++) {
		for(j=0;j<N-1;j++) {
			if(matrica[i][j]!=matrica[i+1][j+1]) tep=1;
		}
	}
		for(i=0;i<M;i++) {
		  for(j=0;j<N;j++) {
				if(i-1 < 0) continue;
				if(matrica[i][0]!=matrica[i-1][N-1]) circ=1;
		}
	}
	
	if(tep==0 && circ==0) printf("Matrica je cirkularna");
	else if(tep==0 && circ==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	


	return 0;
}
