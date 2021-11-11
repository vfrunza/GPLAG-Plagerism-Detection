#include <stdio.h>

#define SIZE 20

int main() {
	int n, i, x, y, a[SIZE][SIZE] = {}, ymax = 0;
	
	while (1) {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if (n <= 10 && n > 0) break;
		printf("Pogresan unos\n");
	}
	
	for (i = 0; i < n; i++) {
		while (1) {
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d%d", &x, &y);
			if ( x>-1 && x<20 && y>-1 && y<20) break;
			printf("Pogresan unos\n");
		}
		a[y][x] = 1;
		ymax = y > ymax ? y : ymax;
	}
	
	for (y = 0; y < ymax + 1; y++) {
		for (x = 0; x < SIZE; x++) 
			printf(a[y][x] ? "*" : " ");
		printf("\n");
	}
	return 0;
}
