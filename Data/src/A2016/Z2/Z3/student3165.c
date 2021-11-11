#include <stdio.h>

int main() {
	int mat[20][20] = {0}, niz_x[10] = {0}, niz_y[10] = {0}, i = 0, j = 0, k = 0, br_tacaka = 0, brejk = 0;
	for (;;) {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &br_tacaka);
		if (br_tacaka > 10 || br_tacaka < 1) printf ("Pogresan unos\n");
		else break;
	}	
	for (i = 0; i < br_tacaka; i++) {
		do {
			printf ("Unesite %d. tacku: ", i+1);
			scanf ("%d %d", &niz_x[i], &niz_y[i]);
			if (niz_x[i] < 0 || niz_x[i] > 19 || niz_y[i] < 0 || niz_y[i] > 19) printf ("Pogresan unos\n");
		} while ((niz_x[i] < 0 || niz_x[i] > 19 || niz_y[i] < 0 || niz_y[i] > 19));
	}
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++) {
				for (k = 0; k < br_tacaka; k++) {
					if (i == niz_y[k] && j == niz_x[k]) {
						printf ("*");
						break;
					}
				}
				if (k == br_tacaka) printf (" ");
			}
			printf ("\n");
		}
	return 0;
}