#include <stdio.h>
#include <math.h>

int max (int matrica [100][100], int visina, int sirina) {
	int i=0, j, k, najvisePuta=1, pomocniNiz[10000], maxi=-1, brojPonavljanja=1;
	
	/*u pomocni niz stavljamo sve clanove matrice*/
	while (i<sirina*visina) {
		for (j=0; j<visina; j++) {
			for (k=0; k<sirina; k++) {
				pomocniNiz[i]=matrica[j][k];
				i++;
			}
		}
	}
	
	for (i=0; i<sirina*visina; i++) {
		brojPonavljanja=1;
		for (j=i; j<sirina*visina; j++) {
			if (pomocniNiz[i]==pomocniNiz[j]) {
				brojPonavljanja++;
			}
		}
		if (brojPonavljanja>maxi) {
			maxi=brojPonavljanja;
			najvisePuta=pomocniNiz[i];
		}
		if (brojPonavljanja==maxi) {
			if (pomocniNiz[i]<najvisePuta) {
				najvisePuta=pomocniNiz[i];
			}
		}
	}
	
	return najvisePuta;
	
}

int izbaci_kolone (int matrica [100][100], int visina, int sirina, int N) {
	int i, j, k, l, pomocna=0;

	for (j=0; j<sirina; j++) {
		pomocna=0;
		for (i=0; i<visina; i++) {
			if (matrica[i][j]==N) {
				for (k=j; k<sirina-1; k++) {
					for (l=0; l<visina; l++) {
						matrica[l][k]=matrica[l][k+1];
					}
				}
				pomocna=1;
			}
			if (pomocna==1) {
				j--;
				sirina--;
				break;
			}
			
		}
	}
	
	return sirina;
}


int main() {
	int matrica [100][100], visina, sirina, i, j, z, m, broj=1;
	
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);
	
	m=sirina;
	
	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf ("%d", &matrica [i][j]);
		}
	}
	
	while (m>0) {
		z=max(matrica, visina, m);
		m=izbaci_kolone(matrica, visina, m, z);
		
		if (m==0) {
			printf ("\nNakon %d. prolaza matrica je prazna!", broj);
			break;
		}
		
		printf ("\nNakon %d. prolaza matrica glasi:\n", broj);
		for (i=0; i<visina; i++) {
			for (j=0; j<m; j++) {
				printf ("%5d", matrica[i][j]);
			}
			printf ("\n");
		}
		broj++;
	}
	
	return 0;
}
