#include <stdio.h>


int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N) {
	
	int i,j,k,l;
	
	// ovdje je ideja da se izbace te kolone koje sadrze taj najveci clan matrice i ispis otprilike kako je receno u zadatku :D
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
				matrica [i][j] = matrica [i][sirina+1];
				sirina--;
				l=sirina;
				printf ("\nNakon %d. prolaza matrica glasi: ", j+1);
				for (k=0; k<visina; k++) {
					for (l=0; l<sirina; l++) {
						if (visina ==0 && sirina ==0) printf ("\nNakon %d. prolaza matrica je prazna!", j+1);
						else printf ("%d ", matrica[k][l]);
					}
				}
				
			}
		}
	}
	return sirina;
}

int max (int matrica[100][100], int visina, int sirina) {
	
	int i,j,k,l, brojac[100][100]={0}, ret=0,maxi;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			for (k=0; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if (matrica[i][j] == matrica[k][l]) 
						brojac[i][j]++;  //pravim matricu brojaca gdje ce za svaki element izracunati njegovo ponavljanje i upisati na poziciju tog clana 
			}
		}
	}
}
		// ovim dijelom prolazim kroz tu matricu brojaca i trazim max standardno, kad nadjem proslijedim tu vrijednost varijabli ret i to vracam iz fje
	maxi= brojac[0][0];
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
					if (brojac[i][j] > maxi) {
						maxi = brojac[i][j];
						ret = matrica[i][j];
					}
				}
			}
	return ret;
}

int main() {
	
	int sirina, visina, i,j, matrica[100][100];
	
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);
	
	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf ("%d ", &matrica[i][j]);
		}
	}
	

	do {
		max(matrica,100,100);
		izbaci_kolone(matrica,100,100,max(matrica,100,100));
	}
	while (visina!=0 && sirina!=0);
	
	return 0;
}
	