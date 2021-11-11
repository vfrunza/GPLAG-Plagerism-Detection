#include <stdio.h>

int main() {
	int i, j, r, k, sh, brojac = 0;
	
	do {
	printf ("Unesite broj redova: ");
	scanf ("%d", &r);
	} while (r<=0 || r > 10);
	
	do {
	printf ("Unesite broj kolona: ");
	scanf ("%d", &k);
	} while (k<=0);
	
	do {
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &sh);
	} while (sh<=0 || sh > 10);
	
	for (i=0; i<r*2+1; i++) {
		for (j=0; j<k+k*sh+1; j++) {
			if (i%2 == 0) {
				if(j == 0 || brojac == sh) {
					printf ("+");
					brojac = 0;
				}
				else {
					printf ("-");
					brojac++;
				}
			}
			else {
				if(j == 0 || brojac == sh) {
					printf ("|");
					brojac = 0;
				}
				else {
					printf (" ");
					brojac++;
				}
			}
		}
		printf ("\n");
	}
	
	return 0;
}
