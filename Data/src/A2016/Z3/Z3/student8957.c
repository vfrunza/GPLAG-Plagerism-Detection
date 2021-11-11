#include <stdio.h>

int main() {
	int mat[200][200];
	int i,j,k,a,b,M,N,temp;
	do {
		printf("Unesite brojeve M i N: ");
		scanf ("%d%d",&M, &N);
		if (M>200 || M<1 || N>200 || N<0)
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}while (M>200 || M<1 || N>200 || N<0);


	printf ("Unesite elemente matrice: ");
	
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	for (i=0;i<M;i++){
		for (j=i+1;j<M;j++){
			temp=1;
				for(k=0;k<N;k++)
					if (mat[i][k]!=mat[j][k]) temp=0;
					if (temp==1){
						for(a=j;a<M-1;a++)
							for(b=0;b<N;b++)
								mat[a][b]=mat[a+1][b];
							M--;
							j--;
						}
					}
				}
	
	for (i=0;i<N;i++){
		for (j=i+1;j<N;j++){
			temp=1;
				for (k=0;k<M;k++)
					if (mat[k][i]!=mat[k][j]) temp=0;
					if (temp==1){
						for (a=j;a<N-1;a++)
							for(b=0;b<M;b++)
								mat[b][a]=mat[b][a+1];
							N--;
							j--;
					}
				}
			}
			
	for (i=0;i<N;i++){
		for (j=i+1;j>N;j++){
			temp=1;
			for (k=0;k<M;k++)
				if(mat[k][i]!=mat[k][j]) temp=0;
			if (temp==1){
				for (a=j;a<N-1;a++)
					for (b=0;b<M;b++)
						mat[a][b]=mat[b][a+1];
					N--;
					j--;
			}
		}
	}
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			printf ("%5d",mat[i][j]);
		}
		printf ("\n");
	}
			
	return 0;
}
