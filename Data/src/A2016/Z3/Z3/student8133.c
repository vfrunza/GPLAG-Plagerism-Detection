#include <stdio.h>

int main() {
	int M,N,i,j,k,l,m,temp,b,temp1,b1;
	double mat[200][200]={{0}};
	do {
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &M, &N);
	if (M<=0 || M>=201 || N<=0 || N>=201)	printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (M<=0 || M>=201 || N<=0 || N>=201);
	
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf ("%lf", &mat[i][j]);
		}
	}
	
	for (i=0; i<M-1; i++) {
		for (j=i+1; j<M; j++) {
			b=0;
			for (k=0; k<N; k++) {
				if (mat[i][k]==mat[j][k])	b++;
			
			}
			if (b==N) {
				for (l=j; l<M-1; l++) {
					for (m=0; m<N; m++) {
						temp=mat[l][m];
						mat[l][m]=mat[l+1][m];
						mat[l+1][m]=temp;
						
					}
				}
				M--;
				j--;
			}
			
		}
		
	}

	for (j=0; j<N-1; j++) {
		for (k=j+1; k<N; k++) {
			b1=0;
			for (i=0; i<M; i++) {
				if (mat[i][j]==mat[i][k])	b1++;
			}
			if (b1==M) {
				for (l=0; l<M; l++) {
					for (m=k; m<N-1; m++) {
						temp1=mat[l][m];
						mat[l][m]=mat[l][m+1];
						mat[l][m+1]=temp1;
						
						
					}
				}
				N--;
				k--;
			}
		}
	}
			
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf ("%5g", mat[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
