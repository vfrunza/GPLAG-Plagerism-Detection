#include <stdio.h>

int main() {
	int x, a[20][20], i, j, b, c;
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			a[i][j]=0;
		}
	}
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &x);
		if (x<1 || x>10) {
			printf ("Pogresan unos\n");
		} else {
			for (i=0; i<x; i++) {
				printf ("Unesite %d. tacku: ", i+1);
				scanf ("%d %d", &c, &b);
				if (c<0 || c>19 || b<0 || b>19) {
					printf ("Pogresan unos\n");
					i--;
				} else {
					a[b][c]=1;
				}
			}
		}
	} while (x<1 || x>10 || c<0 || c>19 || b<0 || b>19);
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			if (a[i][j]==1) {
				printf ("*");
			} else {
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}