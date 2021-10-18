#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int niz[10000], j, i, k=0, element=0, brojac=0, pomocni_element=0, pomocni_brojac=0, broj_elemenata=0;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			niz[k]=matrica[i][j];
			k++;
		}
	}
	broj_elemenata=k;
	for (j=0; j<broj_elemenata; j++) {
		pomocni_element=niz[j];
		pomocni_brojac=0;
		for (i=0; i<broj_elemenata; i++) {
			if (niz[i]==pomocni_element) pomocni_brojac++;
		}
		if (pomocni_brojac>brojac) {
				element=pomocni_element;
				brojac=pomocni_brojac;
			}
		if (pomocni_brojac==brojac) {
			if (pomocni_element<element) element=pomocni_element;
		}
	}
	return element;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N) { 
	int i, j, p, q;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
					for (p=0; p<visina; p++) {
						for (q=j; q<sirina-1; q++) {
							matrica[p][q]=matrica[p][q+1];
						}
					}
					j--;
					sirina=sirina-1;
			}
		}
	}
	return sirina;
}

int main() {
	int i, j, sirina, sirina2, visina, matrica[100][100], N, prolaz=1;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d" , &sirina, &visina);
		for (i=0; i<visina; i++) {
			printf ("Unesite elemente %d. reda: ", i+1);
			for (j=0; j<sirina; j++) {
				scanf ("%d" , &matrica[i][j]);
			}
		}
	sirina2=sirina;
	while (sirina2!=0) {
	N = max(matrica,visina,sirina2);
	sirina2=izbaci_kolone(matrica, visina, sirina2, N);
	if (sirina2==0) {
		printf ("\nNakon %d. prolaza matrica je prazna!" , prolaz);
		return 0;
	}
	printf ("\nNakon %d. prolaza matrica glasi:\n" , prolaz);
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina2; j++) {
			printf ("%5d" , matrica[i][j]);
		}
		printf ("\n");
	}
	prolaz++;
	}
	return 0;
	}

