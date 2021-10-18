/* Zadatak broj 4 je igrom slucaja radjen u zadatku broj 3 pa cu prekopirat ovo dokle sam uradio */

#include <stdio.h>

int max (int matrica[100][100], int visina, int sirina)
{
	int brojac[100][100]= {{0}}; /*Brojat cu svaki element matrice posebno radi lakseg odredjivanja */
	int i,j,k,l;
	int max, min;

	/* U naredne 4 petlje prvo odredjujem koliko puta se koji clan ponavlja  */

	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			for (k=0; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if (matrica[i][j]==matrica[k][l]) {
						brojac[i][j]++;
					}
				}
			}
		}
	}

	max = brojac[0][0];

	/* Sada odredjujem najveci broj ponavljanja clana */

	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (brojac[i][j]>max) {
				max = brojac[i][j];
			}
		}
	}
	/* Analogno prethodnim petljama, odredio sam najmanji clan koji se najvise ponavlja */
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (brojac[i][j]==max) {
				min=matrica[i][j];
				for(k=0; k<visina; k++) {
					for (l=0; l<sirina; l++) {
						if(matrica[k][l]<min && brojac [k][l]==max) {
							min=matrica[k][l];
						}
					}
				}
			}
		}
	}

	return min;
}

int izbaci_kolone (int matrica [100][100], int visina, int sirina, int N)
{

	/* Prvo cu traziti clan N u kolonama matrice, nakon sto ga nadjem izbacit cu kolonu tako sto cu
		preko iste prepisivati druge kolone (slicno kao izbacivanje clana niza) */

	int i,j,k,l;

	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
				for (k=0; k<visina; k++) {
					for (l=j; l<sirina-1; l++) {
						matrica [k][l]=matrica[k][l+1];
					}
				}
				sirina--;
				j--;
				i=0; /* Svi su veseli, a tek smo na pocetku */
			}
		}
	}
	return sirina;
}



int main ()
{
	int matrica[100][100],sirina,visina,clan,brojac=0,izbaciti,nova;
	int i=0,j,k;

	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d%d", &sirina, &visina);

	/* Unos matrice */

	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf ("%d", &clan);
			matrica[i][j]=clan;
		}
	}
	nova = sirina;
	/* Izbacujem kolone dok ne ispraznim matricu */
	while (nova!=0) {

		izbaciti = max(matrica,visina,nova);
		nova = izbaci_kolone(matrica,visina,nova,izbaciti);

		if (nova==0) {
			printf ("\nNakon %d. prolaza matrica je prazna!",brojac+1);
			break;
		}
		printf ("\nNakon %d. prolaza matrica glasi:\n",brojac+1);
		for (j=0; j<visina; j++) {
			for (k=0; k<nova; k++) {
				printf ("%5d", matrica[j][k]);
			}
			printf ("\n");
		}
		brojac++;
	}

	return 0;
}
