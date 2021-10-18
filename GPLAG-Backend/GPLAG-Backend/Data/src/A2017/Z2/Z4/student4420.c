#include <stdio.h>

int main()
{
	int  brojac_ponavljanjaA=0,brojac_ponavljanjaB=0,brojac_ponavljanjaC=0,i,j,k,l,M,N,matricaA[100][100],matricaB[100][100],matricaC[100][100];

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while((M<0 || M>100) || (N<0 || N>100));

	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&matricaA[i][j]);
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&matricaB[i][j]);
		}
	}

	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&matricaC[i][j]);
		}
	}

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			for(k=0; k<M; k++) {
				for(l=0; l<N; l++) {

					if(matricaA[i][j]==matricaA[k][l]) {
						brojac_ponavljanjaA++;
					}
				}
			}

			for(k=0; k<M; k++) {
				for(l=0; l<N; l++) {

					if(matricaA[i][j]==matricaB[k][l]) {
						brojac_ponavljanjaB++;
					}
				}
			}

			for(k=0; k<M; k++) {
				for(l=0; l<N; l++) {
					if(matricaA[i][j]==matricaC[k][l]) {
						brojac_ponavljanjaC++;
					}
				}
			}

			if((brojac_ponavljanjaA!=brojac_ponavljanjaB) || (brojac_ponavljanjaA!=brojac_ponavljanjaC) || (brojac_ponavljanjaB!=brojac_ponavljanjaC)) {
				printf("NE");
				return 0;
			}

			brojac_ponavljanjaC=0;
			brojac_ponavljanjaB=0;
			brojac_ponavljanjaA=0;
		}
	}

	printf("DA");

	return 0;
}
