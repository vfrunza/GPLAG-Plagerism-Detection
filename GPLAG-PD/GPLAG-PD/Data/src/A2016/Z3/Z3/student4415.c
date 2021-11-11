#include <stdio.h>

int main()
{

	int i, j, k, t, c, x; // variable koje koristimo da se pomjeramo u 2d nizu ( i, j, k, t itd.)

	int niz[200][200], BR_RED, BR_KOL;

	// Unos broja redova i kolona matrice i provjera da li su u datom opsegu
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &BR_RED, &BR_KOL);

		if (BR_KOL < 1 || BR_KOL > 200 || BR_RED < 1 || BR_RED > 200 )
			printf ("Brojevi nisu u trazenom opsegu.\n");

	} while (BR_KOL < 1 || BR_KOL > 200 || BR_RED < 1 || BR_RED > 200 );

	printf ("Unesite elemente matrice: ");

	for ( i = 0; i < BR_RED; i++) {
		for (j = 0; j < BR_KOL; j++) {
			scanf ("%d", &niz[i][j]);
		}
	}
	// Izbacivanje reda ako se nalazi vec u nizu ( duplikat ), uz ocuvanje redoslijda

	// i , j nam sluze da se pomjeramo po redovima tako da ih mozemo porediti svaki sa svakim
	for ( i = 0; i < BR_RED; i++) {
		for (j = 0; j < BR_RED; j++) {
			x = 1; 						// postavimo uslov istinit ( da su dva reda jednaka )

			if (j == i) continue; 		// Izbacivamo slucaj kada je i == j da nebi poredili red sam sa sobom

			// k nam sluzi da uporedimo sve clanove  prvog reda sa odgovarajucim clanovima drugog
			for (k = 0; k < BR_KOL; k++) {
				if ( niz[i][k] != niz [j][k]) { 		// ako pronadjemo samo jedan element koji se razlikuje postavljamo x na 0 i zaustavljamo petlju
					x = 0;
					break;
				}
			}

			// Ukoliko je uslov x = 1 ostao zadovoljen tj da su svi elementi jednog reda jednaki odgovarajucim elementima drugog reda, drugi red izbacivamo
			if (x && i < j) {
				for (t = j; t < BR_RED -1; t++) {
					for (c = 0; c < BR_KOL; c++)
						niz[t][c] = niz[t+1][c];
				}
				BR_RED --;
				j --;
			}
		}
	}
	// Izbacivanje kolona iz matrice ukoliko se vec nalazi ista u matrici ( duplikat), uz ocuvanje redoslijeda
	// Ista prica kao i za redove samo sto sada radimo za kolone i, j nam sluze da se pomjeramo po kolonama

	for ( i = 0; i < BR_KOL; i++) {
		for (j =0; j < BR_KOL; j++) {
			x = 1;

			if (j == i) continue;

			for (k = 0; k < BR_RED; k++) {
				if ( niz[k][i] != niz [k][j]) {
					x = 0;
					break;
				}
			}

			if (x && i < j) {
				for (t = j; t < BR_KOL -1; t++) {
					for (c = 0; c < BR_RED; c++)
						niz[c][t] = niz[c][t+1];
				}
				BR_KOL--;
				j--;
			}
		}
	}
	//Nakon izbacivanje ispisivamo matricu

	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

	for (i = 0; i < BR_RED; i++) {
		for (j = 0; j< BR_KOL; j++) {
			printf ("%5d",niz[i][j]);
		}
		printf ("\n");

	}

	return 0;
}
