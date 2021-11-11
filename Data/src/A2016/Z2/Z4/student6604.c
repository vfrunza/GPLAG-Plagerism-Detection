#include <stdio.h>

int main(){
	 int M, N, i, j, k;
	 double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	if((M==1 && N==1)|| M==1){
	printf("Matrica je cirkularna");
	return 0;
	}
	if(N==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	int Teplicova=0;
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]){
			Teplicova=0;
			break;
			}
			else Teplicova=1;
	}
	}
	int cirkularna=0;
	for(i=0; i<M-1;i++){
			k=N-1;
			if((Teplicova==0 && mat[i+1][0]!=mat[i][k]) || (Teplicova==1 && mat[i+1][0]!=mat[i][k])||(Teplicova==0 && mat[i+1][0]==mat[i][k])) {
			cirkularna=0;
			break;
			}
			else cirkularna=1;
		}
	

    if(cirkularna==1) printf("Matrica je cirkularna");
    else if (Teplicova==1) printf("Matrica je Teplicova");


	else if((Teplicova==0) && (cirkularna==0))printf("Matrica nije ni cirkularna ni Teplicova");

	
	return 0;
}