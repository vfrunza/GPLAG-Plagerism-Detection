#include <stdio.h>

int main() {
	int x, y, n;
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	while (n<=0 || n>50) {
		printf ("Pogresan unos\n");
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
	}
	if (n==1) {
		printf ("***");
	}
	else {
		for (x=1 ; x<=n ; x++) {
			for (y=1 ; y<=4*n-3 ; y++) {
				if ((x+y==2*n) || (y-x==2*n-2) || (x==y) || (x+y==4*n-2)) {
					printf ("*");
				}
				else printf (" "); }
				printf ("\n");
		}
	}
		
	return 0;
}
