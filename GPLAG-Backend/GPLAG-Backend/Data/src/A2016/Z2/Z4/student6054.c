#include <stdio.h>

int main (){
	int teplic=1,cirkular=1,i,j,M,N;
	double matrica[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M>100)||(M<=0)||(N>100)||(N<=0)){
			printf("Pogresan unos!\n");
		}}
		while((M<=0)||(M>100)||(N<=0)||(N>100));
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				scanf("%lf", &matrica[i][j]);
			}
		}
		for (i=0;i<M-1;i++){
			for(j=0;j<N-1;j++){
				if((matrica[i][j])!=(matrica[i+1][j+1])){
				teplic=0;
			}
			
			}
		}
		for(i=0;i<M-1;i++){
			if((matrica[i][N-1])!=(matrica[i+1][0])){
				cirkular=0;
			}
			for (j=0;j<N-1;j++){
				if ((matrica[i][j])!=(matrica[i+1][j+1])) {
					cirkular=0;
				}
				
			}
		}
		if (cirkular==1){
			printf("Matrica je cirkularna");
		}
		else if(teplic==1){
			printf("Matrica je Teplicova");
		}
		else {
			printf("Matrica nije ni cirkularna ni Teplicova");
		}
		return 0;
	}

