#include <stdio.h>

int main() {
	int n;
	int l, u, c, a, s;
	Alvaro_Morata:
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	while (n<1 || n>50) {
		printf ("Pogresan unos\n");
		goto Alvaro_Morata;
	}
	
	for (l=0;l<n;l++) {
		for (u=0;u<n-1;u++) {
			if (l==u) printf ("*");
			else printf (" ");
		}
		for (c=0;c<n-1;c++) {
			if (l+c==n-1) printf ("*");
			else printf (" ");
		}
		for (a=0;a<n-1;a++) {
			if (l==a) printf ("*");
			else printf (" ");
		}
		for (s=0;s<n;s++) {
			if (l+s==n-1) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}