#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main () {
	int i, j, Tp, Crk, M, N;
	float mat[VISINA][SIRINA];
	i=0;
	j=0;
	Tp=1;
	Crk=1;
	M=0;
	N=0;
	
	/*Unos matrice*/
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d", &M, &N);
		if (M<=0 || M>=100 || N<=0 || N>=100) {
			printf ("Pogresan unos!\n");
		}
		else {
			break;
		}
	} while (M>100 || M<=0 || N>100 || N>=0);
	
	/*Unos elemenata matrice*/
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	
	/*Ispitivanje da li je matrica Teplicova*/
	for (i=1; i<M; i++) {
		for (j=1; j<N; j++) {
			if (mat[i-1][j-1]!=mat[i][j] || mat[i][j]!=mat[i-1][j-1]) {
				Tp=0;
			}
		}
	}
	
	/*Ispitivanje da li je matrica cirkularna*/
	for (i=1; i<M; i++) {
		for (j=1; j<N; j++) {
			if  (mat[i][0]!=mat[i-1][N-1]) {
					Crk=0;
			}
		}
	}
	
	/*Ispis vrste matrice*/
	if ((Tp==1) && (Crk==0)) {
		printf ("Matrica je Teplicova");
	}
	if ((Tp==1) && (Crk==1)) {
		printf ("Matrica je cirkularna");
	}
	if (Tp==0) {
		printf ("Matrica nije ni cirkularna ni Teplicova");
	}
		
    return 0;
}