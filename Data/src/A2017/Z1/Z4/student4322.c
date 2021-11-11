#include <stdio.h>

int main() {
	int i, j, k, brRed, brKol, sirina;
	do {
	printf ("Unesite broj redova: ");
	scanf ("%d", &brRed);
	} while (brRed<=0 || brRed>10);
	do { printf ("Unesite broj kolona: ");
	scanf ("%d", &brKol);
	} while (brKol<=0 || brKol>10);
	do { printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &sirina);
	} while (sirina<=0 || sirina>10); 
	for (i=0; i<2*brRed+1; i++) {
		for (j=0; j<brKol+1; j++) {
		if (i==0 || i%2==0) { printf ("+");
		if (j<brKol) { for (k=0;k<sirina;k++) { printf ("-"); } }}
		else { printf ("|");
		for (k=0;k<sirina;k++) { printf (" "); } }
		} printf ("\n");
	}
	
	return 0;
}