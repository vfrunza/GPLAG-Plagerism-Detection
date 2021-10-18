#include <stdio.h>

int main() {
	int i, i1, i2, j, M, N, matrica[200][200], temp;
	/*Unos dimenzija matrice */
	do {
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d",&M,&N);
	if (M < 0 || M > 200 || N < 0 || N > 200)
	printf ("Brojevi nisu u trazenom opsegu.\n");
	else break;
	} while (1);
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			scanf ("%d",&matrica[i][j]);
		}
	}
	/* Za izbacivanje redova matrice */
	for(i=0; i<M; i++){
		for(i1 = i+1; i1<M; i1++){
			int a=1;
			for(j=0; j<N; j++){
				if(matrica[i][j] != matrica[i1][j])
					a=0;
			}
			if(a == 1){
				for(i2=i1+1; i2<M; i2++){
					for(j=0; j<N; j++){
						int temp = matrica[i2-1][j];
						matrica[i2-1][j] = matrica[i2][j];
					    matrica[i2][j] = temp;
					}
				}
				M--;
				i1--;
			}
		}
	}
	/*Za izbacivanje kolona matrice*/
    for (j = 0; j < N; j++){
 		for (i1 = j + 1; i1 < N; i1++){
 			int a = 1;
 			for (i2 = 0; i2 < M; i2++){
 				if (matrica[i2][j] != matrica[i2][i1] ) a = 0;
 			}
 			if (a == 1){
 				for (i = i1 + 1; i < N; i++){
 					for (i2 = 0; i2 < M; i2++){
 						int temp;
 					    temp = matrica [i2][i-1];
 						matrica[i2][i-1] = matrica [i2][i];
 					    matrica [i2][i] = temp;
 					}
 				}
 				N--;
 				i1--;
 			}
 		}
 	}	
 	/* Ispis matrice */
 	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
         printf("%5.d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
