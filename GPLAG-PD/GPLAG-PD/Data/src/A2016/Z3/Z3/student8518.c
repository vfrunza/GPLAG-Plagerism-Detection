#include <stdio.h>

int main()
{
	int M,N,i,j,k,z,istavrsta,istakolona;
	int mat[200][200];
	do {
		printf("Unesite brojeve M i N:");
		scanf("%d %d",&M,&N);
		if(M<=0 || M>200 || N<=0 || N>200) {
			printf(" Brojevi nisu u trazenom opsegu.\n");
		}
	} while(M<=0 || M>200 || N<=0 || N>200 );

	printf(" Unesite elemente matrice:");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	//*vrste*\\

	for(i=0; i<M-1; i++) {
		for(k=i+1; k<M; k++) {
			istavrsta=1;
			for(j=0; j<N; j++) {

				if(mat[i][j]!=mat[k][j]) {
					istavrsta=0;
					break;
				}
			}

			if(istavrsta==1) {
				for(j=0; j<N; j++) {
					for(z=k; z<M-1; z++) {
						mat[z][j]=mat[z+1][j];
					}
				}
				M--;
				k--;
			}
		}
	}

	//*kolone*\\

	for(j=0; j<N-1; j++) {
		for(k=j+1; k<N; k++) {
			istakolona=1;
			for(i=0; i<M; i++) {

				if(mat[i][j]!=mat[i][k]) {
					istakolona=0;
					break;
				}
			}

			if(istakolona==1) {
				for(z=k; z<N-1; z++) {
					for(j=0; j<M; j++) {
						mat[j][z]=mat[j][z+1];
					}
					j--;
				}
				N--;
				k--;
			}
		}
	}

	//*ISPIS MATRICE*\\

	printf(" Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
