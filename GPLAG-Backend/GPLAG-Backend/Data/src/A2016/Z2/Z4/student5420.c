#include <stdio.h>

int main() {
	int M,N,i,j,cirk=123;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &M,&N);
		if(M>100 || M<=0 || N>100 || N<=0){
			printf("Pogresan unos!\n");
		}
	} while(M>100 || M<=0 || N>100 || N<=0);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	int tep=1;
	for(i=1; i<M; i++){
		for(j=1; j<N; j++){
			if(mat[i][j]!=mat[i-1][j-1])
			tep=0;
		}
	}
	if(tep==1){
		cirk=1;
		for(i=1; i<M; i++){
			for(j=1; j<N; j++){
				if(mat[i][0]!=mat[0][N-i])
				cirk=0;
			}
		}
	}
	if(cirk==1)
	printf("Matrica je cirkularna");
	else if(tep==1)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
