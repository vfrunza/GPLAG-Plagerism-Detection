#include <stdio.h>

/* Vraca clan matrice koji se najvise puta ponavlja, ukoliko ih se vise ponavlja
isti (najveci) broj puta onda se vraca manji od njih */

int max (int matrica[100][100], int visina, int sirina)
{
	int i, j, k, n;

	/* Inicijalizacija za max_clan se mora uraditi zbog poredjenja u else if */

	int tr_clan, tr_br_ponavljanja, max_clan = matrica[0][0];
	int max_br_ponavljanja = 0;

	/* Za svaki clan matrice mora se po jednom proci kroz matricu */
	for (i=0 ; i<visina ; i++) {
		for (j=0 ; j<sirina ; j++) {
			/* Ove dvije petlje nam sluze da se uzme svaki clan matrice,
			   ali trebaju nam i jos dvije da za taj uzeti clan prodjemo kroz matricu */
			tr_clan = matrica[i][j];
			tr_br_ponavljanja = 0;
			for (k=0 ; k<visina ; k++) {
				for (n=0 ; n<sirina ; n++) {
					if (matrica[k][n] == tr_clan)
						tr_br_ponavljanja++;
				}
			}
			if (tr_br_ponavljanja > max_br_ponavljanja) {
				max_br_ponavljanja = tr_br_ponavljanja;
				max_clan = tr_clan;
			} else if (tr_br_ponavljanja == max_br_ponavljanja) {
				/* Trebamo zapamtiti onaj clan koji je manji */
				if (tr_clan < max_clan)
					max_clan = tr_clan;
				/* U suprotnom nista ne diramo, jer nema smisla pisati if (max_clan < tr_clan) max_clan = max_clan */

			}
		}
	}

	return max_clan;
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{

	/* Prolazimo kroz matricu, ali ovaj put po kolonama */

	int i, j, k, n;

	for (i=0 ; i<sirina ; i++) {
		for (j=0 ; j<visina ; j++) {

			/* Ako je element == N, potrebno je izbaciti kolonu */
			if (matrica[j][i] == N) {

				/* Opet je potrebna dvostruka for petlja, koja prolazi po kolonama, i izbaca kolonu koja sadrzi N */
				for (k=i ; k<sirina-1 ; k++) {
					for (n=0 ; n<visina ; n++) {
						matrica[n][k] = matrica[n][k+1];
					}
				}
				sirina--;
				i--;
			}
		}
	}
	return sirina;
}

int main()
{
	int mat[100][100];
	int i, j, sirina, visina, max_pon_element;
	int br_prolaza;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			mat[i][j] = 0;

	for (i=0 ; i<visina ; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0 ; j<sirina ; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	br_prolaza = 0;
	max_pon_element = max(mat, visina, sirina);
	sirina = izbaci_kolone(mat, visina, sirina, max_pon_element);
	while(sirina > 0) {
		printf("\nNakon %d. prolaza matrica glasi:\n", br_prolaza+1);
		for (i = 0; i < visina; i++) {
			for (j = 0; j < sirina; j++) {
				printf("%5d", mat[i][j]);
			}
			printf("\n");
		}
		max_pon_element = max(mat, visina, sirina);
		sirina = izbaci_kolone(mat, visina, sirina, max_pon_element);
		br_prolaza++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!", br_prolaza+1);

	return 0;
}
