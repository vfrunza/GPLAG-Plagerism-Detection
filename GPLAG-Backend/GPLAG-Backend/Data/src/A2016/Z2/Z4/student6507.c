#include <stdio.h>
#include <math.h>

#define EPSILON 0.001
double matrica[100][100];
int main() {
	int M, N, i, k, j, istina=0, istina1=0, istina2=0, istina3=0;
	
	
	
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100){
	do{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
	}while(M<=0 || M>100 || N<=0 || N>100);}
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(k=0; k<N; k++){
		scanf("%lf", &matrica[i][k]);
		}
	}
	
	for(i=0; i<M; i++){
			if(EPSILON>fabs(matrica[i][N-1]-matrica[i+1][0])){
				istina++;
			}
	}
	
	for(k=0; k<M-1; k++){
		for(j=0; j<N-1; j++){
			if(EPSILON>fabs(matrica[k][j]-matrica[k+1][j+1])){
				istina1++;
			}
		}
	}
	
		if(istina==M-1 && istina1==(M-1)*(N-1)){
			istina2=1;
			printf("Matrica je cirkularna");
			return 0;
	}
	
	for(k=0; k<M-1; k++){
		for(j=0; j<N-1; j++){
			if(EPSILON>fabs(matrica[k][j]-matrica[k+1][j+1])){
				istina3++;
			}
		}
	}
	
	if(istina3==(M-1)*(N-1)){
		printf("Matrica je Teplicova");
	}
	if(istina3!=(M-1)*(N-1) && istina2==0){
	
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
