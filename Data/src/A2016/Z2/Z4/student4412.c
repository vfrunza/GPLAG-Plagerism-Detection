#include <stdio.h>

int main() {
	double mat[100][100];
	int M, N, i, j, c=0, t=0;
	i=0;
	do{
		if(i!=0){
			printf("Pogresan unos!\n");
		}
		i++;
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
	}
	while(M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=1; i<M; i++){
		for(j=0; j<N; j++){
			if(j==0){
				if(mat[i][j]!=mat[i-1][N-1])c++;
			}
			else{
				if(mat[i][j]!=mat[i-1][j-1])c++;
			}
		}
	}
	for(i=1; i<M; i++){
		for(j=0; j<N; j++){
			if(j==0){
				//if(mat[i][j]==mat[i-1][N-1])t++;
				continue;
			}
			else{
				if(mat[i][j]!=mat[i-1][j-1]) t++;
			}
		}
	}
	
	if (c==0 || (t==0 && c==0)) printf("Matrica je cirkularna");
	else if(t==0) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
