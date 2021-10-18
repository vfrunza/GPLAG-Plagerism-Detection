#include <stdio.h>

int main() {
	int M, N, mat[200][200], i, j, k, l, e, x=1;
	/*Unos dimenzija matrice*/
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || M<=0 || N>200 || N<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M>200 || M<=0 || N>200 || N<=0);
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	/*Provjerava se da li su elementi jednog reda jednaki elementima drugog reda,
	ukoliko jedan red nije jednak nekom drugom petlja se break-a te se prelazi na 
	novi red i vrši ista provjera*/
	for(i=0; i<M-1; i++) {
		for(j=i+1; j<M; j++) {
			x=1;
			for(k=0; k<N; k++) {
				if(mat[i][k]!=mat[j][k]) {
					x=0;
					break;
				}
			}
			/*Ukoliko su dva reda jednaka donji se izbacuje u konačnici smanjivanjem 
			formata matrice za 1*/
			if(x) {
				for(l=j+1; l<M; l++) {
					for(e=0; e<N; e++) {
						mat[l-1][e]=mat[l][e];
					}
				}
				M--;
				j--;
			}
		}
	}
	/*Analogni postupak prethodnom pri čemu se posmatraju kolone*/
	for(i=0; i<N-1; i++) {
		for(j=i+1; j<N; j++) {
			x=1;
			for(k=0; k<M; k++) {
				if(mat[k][i]!=mat[k][j]) {
					x=0;
					break;
				}
			}
			if(x) {
				for(l=j+1; l<N; l++) {
					for(e=0; e<M; e++) {
						mat[e][l-1]=mat[e][l];
					}
				}
				N--;
				j--;
			}
		}
	}
	/*Konačni ispis nove matrice*/
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0; 
}
