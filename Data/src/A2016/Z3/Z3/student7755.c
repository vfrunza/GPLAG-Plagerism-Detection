#include <stdio.h>

int main() {
	int M,N,i,j,matrica[200][200];
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
	if(M<=0 || M>200 || N<=0 || N>200){
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
	}while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
		for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matrica[i][j-1]==matrica[i][j]){
				j--;
				N--;
			}
			
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matrica[i-1][j]==matrica[i][j]){
				i--;
				M--;}
		}
	}
	printf("%d",matrica[i][j]);
	return 0;
}
