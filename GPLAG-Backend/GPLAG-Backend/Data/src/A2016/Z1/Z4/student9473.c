#include <stdio.h>

int main() {
	int n, x=0, y=0, A;
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	while (n<=0 || n>50) {
		printf ("Pogresan unos \n");
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		}
	for (x=0;x<n;x++) {
		for (y=0;y<n*4-3;y++) {
			if (n==1) {
			printf ("**");
		}
		A=2*n-2;
		if ((x==y) || (A==x+y) || (2*A==x+y) || (4*A==x+y) || (y-A==x) || (x-A==y))
		printf ("*");
		else printf (" "); 
		}
	printf ("\n");
}
return 0;
}
