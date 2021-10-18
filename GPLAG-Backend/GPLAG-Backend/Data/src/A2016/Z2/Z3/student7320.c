#include <stdio.h>

int main() {
	int n, i, j;
	int x[20], y[20];
	char ma[20][20];
	for (i = 0; i < 20; i++)
	for (j = 0; j < 20; j++) ma[i][j] = ' ';
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if (n <= 0 || n > 10) printf("Pogresan unos\n");
	} while (n <= 0 || n > 10);
	
	for (i = 0; i < n; i++) {
		do {
			printf("Unesite %d. tacku: ", i + 1);
			scanf("%d %d", &x[i], &y[i]);
			if (x[i] < 0 || x[i] >= 20 || y[i] < 0 || y[i] >= 20)  printf("Pogresan unos\n");
		} while (x[i] < 0 || x[i] >= 20 || y[i] < 0 || y[i] >= 20);
		ma[y[i]][x[i]] = '*';
	}
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++)
			printf("%c", ma[i][j]);
		printf("\n");
	}
	return 0;
}
