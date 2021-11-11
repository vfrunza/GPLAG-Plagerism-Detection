#include <stdio.h>

int main() {
	int broj, i, j, matrica[20][20] = {{0}}, x, y;
	
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj);
		if (broj < 1 || broj > 10) {
			printf("Pogresan unos\n");
		}
			
	} while (broj < 1 || broj > 10);
	
	i = 1;
	do {
		printf("Unesite %d. tacku: ", i);
		scanf("%d %d", &x, &y);
		if (x < 0 || x > 19 || y < 0 || y > 19) {
			printf("Pogresan unos\n");
		} else {
			matrica[y][x] = 1;
			i++;
		}
	} while (i < broj + 1);
	
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
			if (matrica[i][j] == 0) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}
