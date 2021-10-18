#include <stdio.h>

int main() {
	int n = 0, i, j, k, nizx[10] = {}, nizy[10] = {}, naso;
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if ((n <= 0 || n > 10)) printf ("Pogresan unos\n"); 
		
	}
	while (n < 0 || n > 10);
	for ( i = 0; i < n; i++) {
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &nizy[i], &nizx[i]);
		if (nizy[i] < 0 || nizy[i] > 19 || nizx[i] < 0 || nizx[i] > 19) {
			printf ("Pogresan unos\n");
			i--;
		}
	}
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			naso = 0;
			for (k = 0; k < n; k++) {
				if (i == nizx[k] && j == nizy[k]) {
					printf ("*");
					naso = 1 ;
					break ;
			}
		}
		if (naso == 0) printf (" ");
	}
	printf ("\n");
	
}
return 0;
}