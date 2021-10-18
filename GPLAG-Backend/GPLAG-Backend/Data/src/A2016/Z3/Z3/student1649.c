#include <stdio.h>

int main() {
	int matrica[200][200], M, N, i, j, k, l, m, jednaki;
	/*Unos dimenzija matrice.*/
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
		if(!(M>0 && M<=200 && N>0 && N<=200)) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(!(M>0 && M<=200 && N>0 && N<=200));
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++) scanf("%d", &matrica[i][j]);
	/*Izbacivanje redova koji se ponavljaju.*/
	for(i=0;i<(M-1);i++){
		/*U petlji se vrsi provjera da li se i-ti red ponavlja u matrici.*/
		for(j=i+1;j<M;j++){
			jednaki=1;
			/*Provjera da li je i-ti red jednak j-tom.*/
			for(k=0;k<N;k++)
				if(matrica[i][k]!=matrica[j][k]){
					jednaki=0;
					break;
				}
			/*Izbacivanje j-tog reda ako je on jednak i-tom.*/
			if(jednaki){
				for(l=j;l<(M-1);l++){
					for(m=0;m<N;m++) matrica[l][m]=matrica[l+1][m];
				}
				j--;
				M--;
			}
		}
	}
	/*Izbacivanje kolona koje se ponavljaju analogno izbacivanju redova.*/
	for(i=0;i<(N-1);i++){
		for(j=i+1;j<N;j++){
			jednaki=1;
			for(k=0;k<M;k++)
				if(matrica[k][i]!=matrica[k][j]){
					jednaki=0;
					break;
				}
			if(jednaki){
				for(l=j;l<(N-1);l++){
					for(m=0;m<M;m++) matrica[m][l]=matrica[m][l+1];
				}
				j--;
				N--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++) printf("%5d", matrica[i][j]);
		printf("\n");
	}
	return 0;
}
