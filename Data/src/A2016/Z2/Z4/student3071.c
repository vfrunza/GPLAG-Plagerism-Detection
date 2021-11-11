#include <stdio.h>
#define EPSILON 0.001
#include<math.h>
int main() {
	int M=0,N=0;
	double matrix[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M>100 || N>100 || M<=0 || N<=0){
			printf("Pogresan unos!\n");
		}
	} while (M>100 || N>100 || M<=0 || N<=0);
	int i,j;
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf", &matrix[i][j]);
		}
	}
	//RACUN
	int TCOUNT=0,CCOUNT=0,counter=0,b=0,Tuslov=0,Cuslov=0;
	int temp,pseudo_diagonal_count;
	pseudo_diagonal_count=M+N-3;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(fabs(matrix[i][j]-matrix[i+1][j+1])<EPSILON){
				counter++;
			}
		}
	}
	if(counter==(M-1)*(N-1)){
		Tuslov=1;
	}
	for(i=1;i<M;i++){
	
			if(fabs(matrix[i][0]-matrix[i-1][N-1])<EPSILON){
				CCOUNT++;
			}	
		
	}
	if(CCOUNT==(M-1)){
		Cuslov=1;
	}
	if(Tuslov==1 && Cuslov==0){
		printf("Matrica je Teplicova");
	} else if (Cuslov==1 && Tuslov==1){
		printf("Matrica je cirkularna");
	} else {
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
