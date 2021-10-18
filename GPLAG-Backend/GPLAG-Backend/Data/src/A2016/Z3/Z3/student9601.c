#include <stdio.h>

int main() {
	int M,N,i,j,k,l,istina=1;
	int mat[200][200];
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M>200||M<=0||N>200||N<=0)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0||N<=0||M>200||N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(j=i+1;j<M;j++){
			for(k=0;k<N;k++){
			if(mat[i][k]!=mat[j][k])
				istina=0;
			}
			if(istina==1){
				for(l=j+1;l<M;l++){
					for(k=0;k<N;k++){
						mat[l-1][k]=mat[l][k];
					}
				}
			M--;
			j--;
			}
			istina=1;
		}
	}
		for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			for(k=0;k<M;k++){
			if(mat[k][i]!=mat[k][j])
				istina=0;
			}
			if(istina==1){
				for(l=j+1;l<N;l++){
					for(k=0;k<M;k++){
						mat[k][l-1]=mat[k][l];
					}
				}
			N--;
			j--;
			}
			istina=1;
		}
	}
	

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
