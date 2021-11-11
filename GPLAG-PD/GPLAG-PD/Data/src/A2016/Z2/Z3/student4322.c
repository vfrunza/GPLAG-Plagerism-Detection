#include <stdio.h>
#define SIRINA 20
int main() {
	int x, y, i, j, n, mat[SIRINA][SIRINA]={0};
	printf("Unesite broj tacaka: ");
	scanf ("%d", &n);
	while (n<1 || n>10) {
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
	}
	for (i=1; i<=n; i++) {
		printf ("Unesite %d. tacku: ", i);
		scanf ("%d %d", &x, &y);
		mat[x][y]=1;
	}
	for (i=0; i<=19; i++) {
		for (j=0; j<=19; j++) {
			if (mat[j][i]==1) {
				printf ("*");
			} else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
