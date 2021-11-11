#include <stdio.h>
int main() {
	int n, k, i, j;
	
	/*Mogucnost unosa broja zvjezdica sve dok upisana vrijednost ne bude: n <= 50*/
	
	for (k=0;; k++) {
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		if (n<1 || n>50) {
			printf ("Pogresan unos");
			printf ("\n");
		}
		else break;
	}
	
	/*Crtanje W*/
	
	if (n==1) {
		printf ("***");
		return 0;
	}
	else {
	for (i=0; i<n; i++) {
		for (j=0; j<(4*n-3); j++) {
			if (i==j || j==2*(n-1)-i || j==2*(n-1)+i || j==2*(2*(n-1))-i ) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	}
	return 0;
}