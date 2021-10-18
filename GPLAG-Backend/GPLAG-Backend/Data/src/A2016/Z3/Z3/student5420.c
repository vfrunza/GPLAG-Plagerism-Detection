#include <stdio.h>

int main() {
	int M,N,mat[200][200],i,j,k,l,pret;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M,&N);
		if(M<=0 || M>200 || N<=0 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	   for(j=0; j<N; j++)
	      scanf("%d", &mat[i][j]);
	for(i=0; i<M-1; i++){
		for(k=i+1; k<M; k++){
			pret=1;
			for(j=0; j<N; j++){
				if(mat[i][j]!=mat[k][j])
				pret=0;
			}
			if(pret){
				for(l=k; l<M; l++){
					for(j=0; j<N; j++)
						mat[l][j]=mat[l+1][j];
					}
					M--;
					k--;
			}
		}
    }
	for(i=0; i<N-1; i++){
		for(k=i+1; k<N; k++){
			pret=1;
			for(j=0; j<M; j++){
				if(mat[j][i]!=mat[j][k])
				pret=0;
				if(pret){
					for(l=k; l<N; l++){
					   for(j=0; j<M; j++)
						mat[j][l]=mat[j][l+1];
					}
					N--;
					k--;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
	   for(j=0; j<N; j++){
	      printf("%5d", mat[i][j]);
	   }
	   printf("\n");
	}
	return 0;
}
