#include <stdio.h>

int main() {
	
	int n, i, j, k;
	int niz1[10], niz2[10], mat[20][20] = {{0}};
	
	do {
	printf("Unesite broj tacaka: ");
	scanf ("%d", &n);
	
	if (n<=0 || n>10)
	printf ("Pogresan unos\n");
	} while (n<=0 || n>10);
	
	for (i=0; i<n; i++) {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &niz1[i], &niz2[i]);
		if (niz1[i]>19 || niz1[i]<0 || niz2[i]>19 || niz2[i]<0) {
			printf ("Pogresan unos\n");
			--i;
			continue;
		}
	}
	
	for (i=0; i<20; i++) {
	for (j=0; j<20; j++) {
	for (k=0; k<n; k++) {
		if (niz1[k]==i && niz2[k]==j)
		mat[i][j] = 1;
				}
			}
		}
		
	for (i=0; i<20; i++) {
	for (j=0; j<20; j++) {
		if (mat[j][i] == 1)
			printf ("*");
		else
			printf (" ");
		}	printf ("\n");
	}
	
	return 0;
	
}
