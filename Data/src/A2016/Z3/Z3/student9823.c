#include <stdio.h>

int main()
{
	int M,N;
	int i, j, k, r;
	double mat[200][200];
	printf("Unesite brojeve M i N: ");
	do {
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>200 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
			printf("Unesite brojeve M i N: ");
		}

	} while(M<=0 || N<=0 || M>200 || N>200);

	printf("Unesite elemente matrice: ");

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}

	int dred, dkolona; // deklarisemo istinite vrijednosti
	dred=1;
	dkolona=1;

	for(k=0; k<M-1; k++) {
		for(i=k+1; i<M; i++) { // provjeravamo prvi red sa svakim narednim redom i tako do M-1
 			for(j=0; j<N; j++) { 
				if (mat[k][j]==mat[i][j]) dred=1; // provjeravamo svaki element reda i mjenjamo istinite vrijednosti
				else {
					dred=0;
					break;
				}
			}

			if(dred==1) { // ukoliko su isti redovi -> algoritam za izbacivanje redova
				for(j=0; j<N; j++) {
					for(r=i; r<M-1; r++) {
						mat[r][j]=mat[r+1][j];
					}
				}
				M--; // smanjujemo duzinu redova
				i--;


			}
		}
	}





	for(k=0; k<N-1; k++) {
		for(i=k+1; i<N; i++) { // provjeravamo prvu kolonu sa svakom narednom kolonom i tako do N-1
			for(j=0; j<M; j++) {
				if (mat[j][k]==mat[j][i]) dkolona=1; // provjeravamo svaki element kolone i mjenjamo istinite vrijednosti
				else {
					dkolona=0;
					break;
				}
			}

			if(dkolona==1) { // ukoliko su iste kolone -> algoritam za izbacivanje kolona
				for(j=0; j<M; j++) {
					for(r=i; r<N-1; r++) {
						mat[j][r]=mat[j][r+1];
					}
				}
				N--; // smanjujemo duzinu kolona
				i--;

 
			}
		}
	}

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5g", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
