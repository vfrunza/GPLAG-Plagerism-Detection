#include <stdio.h>
int main() {
	double mat[100][100];
	int M,N,prett=1,cirkt=1,i,j,g;
	do{
    printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
		if(M<=0|| M>100||N<=0||M>100){
			printf("Pogresan unos!\n");
			continue;
		}
		else
		break;
	}while(M>100 || N>100 || N<=0 || M<=0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&mat[i][j]);
	}
	}
	g=N-1;
	for(i=1;i<M;i++) {
		for(j=1;j<N;j++) {
			if(mat[i][j]!=mat[i-1][j-1] || mat[i-1][j-1]!=mat[i][j]) {
			prett=0;
			}
			
		}
	}
	for(i=1;i<M;i++){
		for(j=1;j<N;j++){
			if( mat[i][0]!=mat[i-1][g] ){
			cirkt=0;
			}
			}
		}
	if(prett==1 && cirkt!=1){
			printf("Matrica je Teplicova");
	}
	if(prett==1 && cirkt==1){
		printf("Matrica je cirkularna");
	}
	if(prett==0){
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
