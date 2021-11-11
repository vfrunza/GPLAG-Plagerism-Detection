#include <stdio.h>

int main() {
	int n, i, j;
	do {
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	if (n<1 || n>50) {
		printf ("Pogresan unos\n");
	}
	} while (n<1 || n>50);
	for (i=0; i<n; i++) {
		for (j=0; j<4*(n-1)+1; j++) {
			if (n==1) {
				printf ("***");
			} else {
				if (i==j || i==2*(n-1)-j || i==j-2*(n-1) || i==4*(n-1)-j) {
					printf ("*");
				} else {
					printf (" ");
				}
			}
		}
		printf ("\n");
	}
	return 0;
}
