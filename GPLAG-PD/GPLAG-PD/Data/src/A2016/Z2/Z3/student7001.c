#include <stdio.h>
int main() {
	int mat[20][20]={0}, n, a, b, i, j;
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if (n<=0 || n>10) printf ("Pogresan unos\n");
	} while (n<=0 || n>10);
	for (i=0; i<n; i++) {
			printf ("Unesite %d. tacku: ", i+1);
			scanf ("%d %d", &a, &b);
			if (a<0 || a>19 || b<0 || b>19) {
				printf ("Pogresan unos\n");
				i--;
			}
			else mat[b][a]=1;
	}
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			if (mat[i][j]==1) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}