#include <stdio.h>

int main() {
	/*printf("Zadaća 3, Zadatak 3");*/
	int M,N,i,j,mat[50][50],k,z,x,istina;
	do{
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &M, &N);
	if (M>200 || N>200 || M<=0 || N<=0)
		printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (M>200 || N>200 || M<=0 || N<=0);
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf ("%d", &mat[i][j]);
		}
	}
	for (k=0;k<M-1;k++){
		for (i=k+1;i<M;i++){
			for (j=0;j<N;j++){
			if (mat[k][j]==mat[i][j]){
				istina=1;
		
			}
			else{ 
				istina=0;
				break;
			}
		}
		
	if (istina==1) {
	for(z=i; z<M-1; z++){
		for(x=0; x<N; x++){
			mat[z][x]=mat[z+1][x];
			}
	
	}
	M--;
	i--;
	}

	}
	}

	for (k=0;k<N-1;k++){
		for (i=k+1;i<N;i++){
			for (j=0;j<M;j++){
			if (mat[j][k]==mat[j][i]){
				istina=1;
		
			}
			else{ 
				istina=0;
				break;
			}
		}
		
	if (istina==1) {
	for(z=i; z<N-1; z++){
		for(x=0; x<M; x++){
			mat[x][z]=mat[x][z+1];
			}
	
	}
	N--;
	i--;
	}
	}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			printf ("%5d", mat[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
