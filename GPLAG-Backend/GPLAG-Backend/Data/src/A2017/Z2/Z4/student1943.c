#include <stdio.h>

int main() {
	int brojac=0, k, l;
	int jelPostoji = 0;
	int M, N, matA[100][100], matB[100][100], matC[100][100], i, j, nekibroj;
	int brojZajednickihAiB=0,brojZajednickihBiC=0,brojZajednickihAiC=0;
	int brojRazlA=0,brojRazlB=0,brojRazlC=0;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	}while (M>100 || M<0  || N>100 || N<0);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &matA[i][j]);
		}
	}
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &matB[i][j]);
		}
	}
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &matC[i][j]);
		}
	}
	int bb=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			bb = 0;
			for(k=0;k<i;k++){
				for(l=0;l<j;l++){
					if(matA[i][j] == matA[k][l]){
						bb = 1;
						break;
					}
					
				}
				if(bb) break;	
			}
			if(k==i && l==j) brojRazlA++;
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			bb=0;
			for(k=0;k<i;k++){
				for(l=0;l<j;l++){
					if(matB[i][j] == matB[k][l]){
						bb= 1;
						break;
					}
				}
				if(bb == 1) break;
			}
			if(k==i && l==j) brojRazlB++;
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			bb=0;
			for(k=0;k<i;k++){
				for(l=0;l<j;l++){
					if(matC[i][j] == matC[k][l]){
						bb = 1;
						break;
					}
				}
				if(bb == 1) break;
			}
			if(k == i && l == j) brojRazlC++;
		}
	}
	
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			for(k=0;k<M;k++){
				for(l=0;l<N;l++){
					if(matA[i][j] == matB[k][l])
					brojZajednickihAiB++;
					if(matA[i][j] == matC[k][l]) brojZajednickihAiC++;
					if(matB[i][j] == matC[k][l]) brojZajednickihBiC++;
				}
			}
		}
	}
	if(brojZajednickihAiB == brojZajednickihAiC && brojZajednickihAiC == brojZajednickihBiC && brojRazlA == brojRazlB && brojRazlB == brojRazlC) printf("DA\n");
	else printf("NE\n");
	return 0;
}
