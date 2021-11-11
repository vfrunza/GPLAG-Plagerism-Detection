#include <stdio.h>

int main() {
	int M,N,matrix[200][200],i,j,k,l,z,br=1;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || N<1 || M>200 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<1 || N<1 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%d", &matrix[i][j]);
	for(i=0; i<M-1; i++)
	{
		for(k=i+1; k<M; k++)
		{
			br=1;
			for(j=0; j<N; j++) if(matrix[i][j]!=matrix[k][j]) br=0;
			if(br==1)
			{
				for(l=k; l<M-1; l++)
				for(z=0; z<N; z++)
				matrix[l][z]=matrix[l+1][z];
				M--; k--;
			}
		}
	}
	
	for(i=0; i<N-1; i++)
	{
		for(k=i+1; k<N; k++)
		{
			br=1;
			for(j=0; j<M; j++) if(matrix[j][i]!=matrix[j][k]) br=0;
			if(br==1)
			{
				for(l=k; l<N-1; l++)
				for(z=0; z<M; z++)
				matrix[z][l]=matrix[z][l+1];
				N--; k--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
