#include <stdio.h>

int main()
{
	int mat[200][200]={0};
	int M,N,brojac,temp;
	int i,j,r,k,m;
	/*Petljom osiguravam unos formata matrice MxN sve dok ne budu u trazenom opsegu*/ 
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || N>200 || M>200 || N<=0) 
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<=0 || N>200 || M>200 || N<=0); 
	/*Unos elemenata matrice , osiguran dvostrukom petljom za redove i kolone*/ 
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	} 
	/*Provjeravam redove matrice , pocevsi od pocetnog , zatim pravim petlju za redove sa indeksom vecim od pocetnog(referentnog) reda*/
	for(i=0; i<M; i++) {
		for(j=i+1; j<M; j++) {
			brojac=0;
			/*Petlja koja prolazi kroz sve elemente reda*/ 
			for(r=0; r<N; r++) {
				/*U slucaju da su elementi reda jednaki , brojac ce se povecati za jedan , ako brojac bude jednak broju kolona, pravimo petlje za zamjenu mjesta elemenata matrice te izbacivanje reda iz matrice */
				if(mat[i][r]==mat[j][r]) brojac++;
				if (brojac==N) {
					for(m=j; m<M; m++) {
						for(k=0; k<N; k++) {
							temp=mat[m][k];
							mat[m][k]=mat[m+1][k];
							mat[m+1][k]=temp;
						}

					}
					j--;
					M--;

				}
			}
		}
	}
	/*Prolazimo kroz kolone analogno kao sto smo prosli kroz redove*/
	for(j=0; j<N; j++) {
		for(i=j+1; i<N; i++) {
			brojac=0;
			for(r=0; r<M; r++) {
				if(mat[r][i]==mat[r][j]) brojac++;
				if(brojac==M) {
					for(m=i; m<N; m++) {
						for(k=0; k<N; k++) {
							temp=mat[k][m];
							mat[k][m]=mat[k][m+1];
							mat[k][m+1]=temp;
						}

					}
					i--;
					N--;
				}
			}
		}
	}
	/*Ispis*/
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
