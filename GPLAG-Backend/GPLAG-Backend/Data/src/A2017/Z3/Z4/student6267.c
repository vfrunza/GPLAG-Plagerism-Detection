#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int brojaci[100][100]= {{0}};
	int i, j, k, l, brojac, najfrekventniji, najveciBrojac;
	// Pravimo novu matricu sastavljenu od brojaca, koja ce imati iste parametre duzine i visine kao i pocetna matrica. Svaki element matrice ima vlastiti brojac na istoj [i][j] adresi u matrici brojaca.
	// Algoritam za uporedjivanje dva broja u matrici
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			brojac=1;
			for (k=i; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if (k!=i || l>j) {
						if (matrica[i][j]==matrica[k][l]) {
							brojac++;
							brojaci[k][l]=-1; // Ne zelimo da imamo vise brojaca za jedan isti broj, tako da brojac svakog duplog clana postavljamo na -1 da znamo da je on duplikat.
						}
					}
				}
			}
			if (brojaci[i][j]!=-1) {
				brojaci[i][j]=brojac; // Ovdje iskoristimo cinjenicu da su brojaci duplikata -1, i samo originalnom brojacu proslijedjujemo vrijednost broja jednakih clanova
			}
		}
	}
	// Algoritam za trazenje max elementa u matrici (trazimo max vrijednost brojaca)
	najfrekventniji=matrica[0][0];
	najveciBrojac=brojaci[0][0];
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (brojaci[i][j]==najveciBrojac) {
				if (matrica[i][j]<najfrekventniji) {
					najveciBrojac=brojaci[i][j]; // U slucaju da se vise clanova ponavljaju isti broj puta, po postavci zadatka, biramo najmanji
					najfrekventniji=matrica[i][j];
				}
			}
			if (brojaci[i][j]>najveciBrojac) {
				najveciBrojac=brojaci[i][j]; 
				najfrekventniji=matrica[i][j];
			}
		}
	}
	return najfrekventniji;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, l;
	// Algoritam za izbacivanje kolone iz matrice
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
				for (k=i; k<visina; k++) {
					for (l=j; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];
					}
				}
				sirina--;
				i=0;
				j--;
			}
		}
	}
	return sirina;
}
int main()
{
	int matrica[100][100], sirina, visina, i, j, brojacProlaza;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	brojacProlaza=0;
	while (sirina!=0) {
		sirina=izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
		brojacProlaza++;
		if (sirina==0)
			printf("\nNakon %d. prolaza matrica je prazna!", brojacProlaza);
		else {
			printf("\nNakon %d. prolaza matrica glasi: \n", brojacProlaza);
			for (i=0; i<visina; i++) {
				for (j=0; j<sirina; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
