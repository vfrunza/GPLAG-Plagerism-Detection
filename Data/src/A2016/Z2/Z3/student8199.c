#include <stdio.h>
#define size 20

int main() {
	int cox[size], coy[size], br, i = 0, j = 0, var = 0, tac = 0, k;
	
	/*Unos i provjera unosa*/
	
	do {
		printf("Unesite broj tacaka: ");
	scanf ("%d", &br);
	if (br > 10 || br <= 0) {
		printf ("Pogresan unos\n");
	}
	} while (br > 10 || br <= 0);
	
	for (i = 0; i < br; i++) {
		printf ("Unesite %d. tacku: ", i + 1);
		scanf ("%d %d", &cox[i], &coy[i]);
		if (cox[i] < 0 || cox[i] >= 20 || coy[i] < 0 || coy[i] >= 20) {
			printf ("Pogresan unos\n");
			i--;
		}
		
	}
	
	/*Provjera pozicije tacaka*/
	
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			for (k = 0; k < br; k++) {
				if (cox[k] == j && coy[k] == i && var == 0) {
					printf ("*");
					var++;
				}
				else {
					tac++;
				}
			}
			if (tac = (br - 1) && var == 0) {
				printf (" ");
			}
			var = 0;
			k = 0;
			tac = 0;
		}
		printf ("\n");
	}
	
	return 0;
}
