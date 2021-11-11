#include <stdio.h>

int main() {
	int mat[200][200],i,j,k,T=1,p,q,N,M;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || N<=0 || M>200 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<=0 || N<=0 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			T=1;
			for(k=0;k<N;k++){
				if(mat[i][k]!=mat[j][k])
				T=0;
			}
			if(T==1){
				for(p=j;p<M-1;p++)
					for(q=0;q<N;q++)
						mat[p][q]=mat[p+1][q];
						M--;
						j--;
				}
		}
	}
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			T=1;
			for(k=0; k<M; k++){
				if(mat[k][i]!=mat[k][j]) T=0;
			}
			if(T==1){
				for(p=0; p<M; p++) 
					for(q=j; q<N-1; q++)
						mat[p][q]=mat[p][q+1];
				N--;
				j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
