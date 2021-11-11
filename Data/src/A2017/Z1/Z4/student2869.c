#include <stdio.h>

int main()
{
	int red, kolone, sirina, j, i;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &red);
	} while ( red<=0 || red>10) ;
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &kolone);
	} while (kolone<=0 || kolone>10);
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sirina);
	} while (sirina<=0 || sirina>10);
	for (i=0; i<red*2+1; i++) {
		for (j=0; j<(kolone*sirina+kolone+1); j++) {
			if (i%2==0) {
				if (j%(sirina+1)==0) {
					printf ("+");
				} else printf ("-");
			} else {
				if (j%(sirina+1)==0) printf ("|");
				else printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}