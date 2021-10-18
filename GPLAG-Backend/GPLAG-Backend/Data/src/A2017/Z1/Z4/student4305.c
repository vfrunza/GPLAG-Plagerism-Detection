#include <stdio.h>

int main() {
	int i, j, broj_redova_unos, broj_kolona_unos, sirina_kolone, broj_redova, broj_kolona;
	
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &broj_redova_unos);
	} while (broj_redova_unos <= 0 || broj_redova_unos > 10);
			 
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &broj_kolona_unos);
	} while (broj_kolona_unos <= 0 || broj_kolona_unos > 10);
	
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sirina_kolone);
	} while (sirina_kolone <= 0 || sirina_kolone > 10);
		
	/* Racunamo broj redova i kolona u petlji */
	
	broj_redova = 2 * broj_redova_unos + 1;
	broj_kolona = broj_kolona_unos * sirina_kolone + broj_kolona_unos + 1;
	
	for (i=0 ; i<broj_redova ; i++) {
		for (j=0 ; j<broj_kolona ; j++) {
			if (i%2==0) {
				if (j%(sirina_kolone + 1) == 0)
					printf ("+");
				else 
					printf ("-");
			}
			else  {
				if (j%(sirina_kolone + 1) == 0)
					printf ("|");
				else 
					printf (" ");
			}
	}
		printf ("\n");
	}
		return 0;
}
