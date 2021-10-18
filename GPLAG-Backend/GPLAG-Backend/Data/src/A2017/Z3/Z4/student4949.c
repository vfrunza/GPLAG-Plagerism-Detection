#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{

	int i, j, k, l, brojac, najviseponavljani, najveci;
	int brojacielemenata[100][100]= {{0}}; /*Pravimo matricu brojaca elemenata posmatrane matrice. Tako da i sirina i visina moraju biti isti
	kao kod unesene matrice kako bi svaki element imao vlastiti brojac */

	for(i=0; i<visina; i++) { /*Vec koristeni algoritam za usporedbu brojeva u matrici*/
		for(j=0; j<sirina; j++) {
			brojac=1;
			for(l=i; l<visina; l++) {
				for(k=0; k<sirina; k++) {
					if(k>j || l!=i) {
						if(matrica[i][j]==matrica[l][k]) {
							brojac++;
							brojacielemenata[l][k]=-5; /*if u 16.toj liniji se odnosi na duplikate, u tom slucaju bi se brojaci razdijelili.
					Zbog toga radi posebnog "tretmana" u nastavku vrsimo dodjelu randomly izabrane vrijednosti radi koristenja u nastavku.*/
						}
					}
				}
			}

			if(brojacielemenata[i][j]!=-5) {
				brojacielemenata[i][j]=brojac; /*Ovdje prvom brojacu koji je "naletio" na broj koji se ponavlja dalje u matrici dodjeljujemo
				pravi brojac kako bi prebrojavanje bilo validno*/
			}
		}
	}

	najviseponavljani=matrica[0][0]; /*Trazenje najveceg brojaca*/
	najveci=brojacielemenata[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(najveci==brojacielemenata[i][j]) {
				/* U nastavku osiguravamo da ukoliko imamo vise clanova s jednakim brojem ponavljanja, uzmemo manji od ta dva jer je takva
				postavka zadatka */
				if(najviseponavljani>matrica[i][j]) {
					najveci=brojacielemenata[i][j];
					najviseponavljani=matrica[i][j];
				}
			}
			if(najveci<brojacielemenata[i][j]) {
				najveci=brojacielemenata[i][j];
				najviseponavljani=matrica[i][j];
			}
		}
	}

	return najviseponavljani;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int br)
{
	int i, j, k, l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==br) {
				for(l=i; l<visina; l++) {
					for(k=j; k<sirina-1; k++) {
						matrica[l][k]=matrica[l][k+1];
					}
				}
				i=0;
				j--;
				sirina--; /*Ranije smo koristili slicne algoritme za izbacivanje kolona*/
			}
		}
	}
	return sirina; /* Na kraju funkcija treba da vrati sirinu  */
}

int main()
{

	int sirina, visina, i, j, nProlaza, matrica[100][100];

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	nProlaza=0;
	while(sirina!=0) {
		sirina=izbaci_kolone(matrica, visina, sirina, max(matrica,visina,sirina));
		nProlaza++;

		if(sirina==0)
			printf("\nNakon %d. prolaza matrica je prazna!", nProlaza);
		else {
			printf("\nNakon %d. prolaza matrica glasi:\n", nProlaza);

			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d", matrica[i][j]);
				}

				printf("\n");
			}
		}
	}
	return 0;
}
