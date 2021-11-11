#include <stdio.h>

int main() {
	int i,j, mat[200][200],M,N,i1,i2;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		 if (M<0 || M>200 || N<0 || N>200)
		 printf("Brojevi nisu u trazenom opsegu.\n");
		 else break;
	} while (1);
	
	printf("Unesite elemente matrice: ");
	 for (i=0;i<M;i++){
	 	for (j=0;j<N;j++){
	 		scanf("%d",&mat[i][j]);
	 	}
	 }
	 
	for (i=0;i<M;i++){
		for (i1=i+1; i1<M; i1++){
			int istinitost=1;
			 for (j=0;j<N;j++){
			 	if (mat[i][j]!= mat[i1][j])
			 	istinitost=0;
			 }
	if (istinitost==1){
		for (i2=i1+1;i2<M;i2++){
			for (j=0;j<N;j++){
				int temp=mat[i2-1][j];
				mat[i2-1][j]=mat[i2][j];
				mat[i2][j]=temp;
			}
		}
		M--;
		i1--;
	}
		}
	}
		
	for (j=0;j<N;j++){
		for (i1=j+1;i1<N;i1++){
			int istinitost=1;
			for (i2=0;i2<M;i2++){
				if (mat[i2][j]!=mat[i2][i1])
				istinitost=0;
			}
			if (istinitost==1){
				for (i=i1+1;i<N;i++){
					for (i2=0;i2<M;i2++){
						int temp =mat[i2][i-1];
						mat[i2][i-1]=mat[i2][i];
						mat[i2][i]=temp;
						
					}
				}
				N--;
				i1--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	 for (i=0;i<M;i++){
	 	for (j=0;j<N;j++){
	 		printf("%5.d",mat[i][j]);
	 	}
	 	printf("\n");
	 }
	
	return 0;
}
