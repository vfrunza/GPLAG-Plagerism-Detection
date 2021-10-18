#include <stdio.h>
#define vel 100

int main() {
	
	int truthTEPLIC=0, truthCIRC=0, M, N;
	float mat[vel][vel]={0};
	int i=0, j=0, brEL=0, brPROV=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100){
			printf("Pogresan unos!\n");
		}
	}while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%f", &mat[i][j]);
			brEL++;
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(mat[i][j]==mat[i+1][j+1]){
				brPROV++;
			}
		}
	}
	if((M-1)*(N-1)==brPROV){
		truthTEPLIC=1;
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(mat[i][N-1]==mat[i+1][0]){
				truthCIRC=1;
			}
			else truthCIRC=0;
		}
	}
	
	if(truthTEPLIC==1 && truthCIRC==0){
		printf("Matrica je Teplicova");
	}
		else if(truthTEPLIC==1 && truthCIRC==1){
		printf("Matrica je cirkularna");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	
	
	
	return 0;
}
