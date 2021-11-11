#include <stdio.h>
int main() {
int i,j,k,z,y;	 
int mat[200][200];
int M,N;
int pret=1;

do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || N>200 || (N<=0 || M>200))
	printf("Brojevi nisu u trazenom opsegu.\n");
} while(M<1 || N>200 || (N<1 ||  M>200));
				
printf("Unesite elemente matrice: ");
for(i=0; i<M; i++) {
	for(j=0; j<N; j++) {
		scanf("%d", &mat[i][j]);
	}
}
for(i=0; i<M;i++) {
	for(j=i+1; j<M; j++) {
		pret=1;
		for(k=0; k<N; k++) {
			if(mat[i][k]!=mat[j][k]) 
			pret=0;
		}
		if(pret==1) {
			for(z=j; z<M-1; z++) {
				for(y=0; y<N; y++) {
					mat[z][y]=mat[z+1][y];
				}
			}
			M--;
			j--;
		}
	}
}
for(i=0; i<N;i++) {
	for(j=i+1; j<N; j++) {
		pret=1;
		for(k=0; k<M; k++) {
			if(mat[k][i]!=mat[k][j]) 
			pret=0;
		}
		if(pret==1) {
			for(z=j; z<N-1; z++) {
				for(y=0; y<M; y++) {
					mat[y][z]=mat[y][z+1];
				}
			}
			N--;
			j--;
		}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0; i<M; i++) {
	for(j=0; j<N;j++) {
		printf("%5d", mat[i][j]);
		
	}
	printf("\n");
}

return 0;
}
