#include <stdio.h>

int main() {
	int mat[200][200], i, j, l, k, a, z;
	int M, N;
	do{
		printf("Unesite brojeve M i N:");
		scanf("%d %d",&M,&N);
		if (M<=0 || M>200 || N<=0 || N>200){
			printf (" Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
	} while (M<=0 || M>200 || N<=0 || N>200);
	printf (" Unesite elemente matrice: ");
	for (i=1;i<=M;i++){
		for (j=1;j<=N;j++)
		{
			scanf ("%d",&mat[i][j]);
		}
	}
	for (l=1;l<=M;l++){
		for(i=l+1;i<=M;i++){
			a=1;
			for(j=1;j<=N;j++){
				if (mat[l][j]!=mat[i][j]) a=0;
			}
			/*izbacivanje reda*/
			if (a) {
				for(z=i;z<=M;z++){
					for(j=1;j<=N;j++){
						mat[z][j]=mat[z+1][j];
					}
				}
				i--;
				M--;
			}
		}
	}

	for (k=1;k<=N;k++){
		for(j=k+1;j<=N;j++){
			a=1;
			for(i=1;i<=M;i++){
				if (mat[i][k]!=mat[i][j]) a=0;
			}
			if (a) {
				/*izbacivanje kolone*/
				for(i=1;i<=M;i++){
					for(z=j;z<=N;z++){
						mat[i][z]=mat[i][z+1];
					}
				}
				j--;
				N--;
			}
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=1;i<=M;i++){
		printf(" ");
		for (j=1;j<=N;j++){
			printf("%4d ", mat[i][j]);
		}
		printf ("\n");
	}
	return 0;
}