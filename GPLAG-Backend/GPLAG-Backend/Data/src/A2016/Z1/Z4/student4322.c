#include <stdio.h>
#include <stdlib.h>

int main() {
	int n=1, i=0, j=0, dodatni=0;
	do 
	{
		if (n<1 || n>50) printf ("Pogresan unos\n");
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
	} while (n<1 || n>50);
	if (n>1) dodatni = n-3;
	for (i=0; i<n; i++) {
		for (j=0; j<3*n+dodatni; j++) {
			if (i==j) printf ("*");
			else if (j-i == n+dodatni+1) printf ("*");
			else if (j+i == 3*n-1+dodatni) printf ("*");
			else if (j+i == n+1+dodatni || (n==1 && j==1)) printf ("*");
			else printf (" ");
		}
		printf("\n");
	}
	return 0;
}
