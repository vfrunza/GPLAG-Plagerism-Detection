#include <stdio.h>
int main () {
	int i, j, n;
	unos:
	printf ("Unesite broj n: ");
	scanf ("%d",&n);
	if (n<=0 || n>50) {
		printf ("Pogresan unos\n");
		goto unos;
	}
	if (n!=1) {
	for (i=0; i<n; i++) {
		for (j=0; j<(4*n-3); j++) {
			if (j==i || j==(i+2*(n-i)-2) || j==((4*n-3)-i-1) || j==(4*n-4-i-(2*(n-i)-2))) 
				printf ("*");
				else printf (" ");
		}
		printf ("\n");
	}
	}
	if (n==1) printf ("***");
	return 0;
}
