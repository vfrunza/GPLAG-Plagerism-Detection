#include <stdio.h>

int main() {
	
	int asterix[20][20]={0}; int broj_tacaka, i, j, x, y;
	
	Ponovi:
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &broj_tacaka);
	if (broj_tacaka>10 || broj_tacaka<=0) {
		printf("Pogresan unos\n");
		goto Ponovi;
	}
	
	for (i=0; i<broj_tacaka; i++) {
		Ponovo:
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &x, &y);
		if (x > 19 || x < 0 || y > 19 || y < 0) {
			printf ("Pogresan unos\n");
			goto Ponovo;
		}
		asterix[y][x] = 69;
	}
	
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			if (asterix[i][j] == 69) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	
	return 0;
}