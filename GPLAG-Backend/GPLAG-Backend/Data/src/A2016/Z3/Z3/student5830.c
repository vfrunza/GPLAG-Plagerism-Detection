#include <stdio.h>

int main()
{
	int mat[200][200];
	int j,M,N,i,k=0,a,b,temp;
	int brojac=0;
	do {
		printf("Unesite brojeve M i N:");
		scanf("%d %d",&M,&N);
		if (M<1||M>200||N<1||N>200) printf (" Brojevi nisu u trazenom opsegu.\n");
	} while(M<1||M>200||N<1||N>200);

	printf (" Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d",&mat[i][j]);
		}
	}
	for (i=0; i<N; i++) {
		for (j=i+1; j<N; j++) {
			brojac=0;
			for (k=0; k<M; k++) {
				if(mat[k][i]==mat[k][j]) {
					brojac++;
				}
				if(brojac==M) {
					for (a=j+1; a<N; a++) {
						for (b=0; b<M; b++) {
							temp=mat[b][a-1];
							mat[b][a-1]=mat[b][a];
							mat[b][a]=temp;
						}
					}
					N--;
					j--;
				}
			}
		}
	}
	for (i=0; i<M; i++) {
		for (j=i+1; j<M; j++) {
			brojac=0;
			for (k=0; k<N; k++) {
				if(mat[i][k]==mat[j][k]) {
					brojac++;
				}
				if(brojac==N) {
					for (a=j+1; a<M; a++) {
						for (b=0; b<N; b++) {
							temp=mat[a-1][b];
							mat[a-1][b]=mat[a][b];
							mat[a][b]=temp;
						}
					}
					M--;
					j--;
				}
			}
		}
	}

	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf ("%5d",mat[i] [j]);
		}
		printf("\n");
	}
	return 0;
}