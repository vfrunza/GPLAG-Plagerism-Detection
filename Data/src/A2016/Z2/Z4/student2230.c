#include <stdio.h>

int main() {
	int M,N,i=0,j=0;
	double mat[300][300];
	int teplicova=1, cirkularna=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || N<=0 || M>100 || N>100){ printf("Pogresan unos!\n");}
	} while(M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	while (i<M){
		j=0;
		while(j<N){
			scanf("%lf",&mat[i][j]);
			j++;
		}
		i++;
	}
	i=0;
	while(i<M-1){
		j=0;
		while(j<N-1){
			if(mat[i][N-1]!=mat[i+1][0]) cirkularna=0;
			if(mat[i][j]!=mat[i+1][j+1]) {teplicova=0; cirkularna=0;}
			j++;
		}
		i++;
	}
	if(M>1 && N==1){ cirkularna=0; teplicova=1;}
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	
	else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
