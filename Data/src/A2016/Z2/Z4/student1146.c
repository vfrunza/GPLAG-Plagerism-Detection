#include <stdio.h>

int main() {
	int m, n, x, y, tep = 1, cir = 1;
	double a[100][100];

	do {
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if (m > 0 && n > 0 && m <= 100 && n <= 100) break;
		printf("Pogresan unos!\n");
	} while (1);

	printf("Unesite elemente matrice: ");
	for (y = 0; y < m; y++)
		for (x = 0; x < n; x++)
			scanf("%lf", &a[y][x]);
	
	for (y = 1; y < m; y++) {
		if (a[y-1][n-1] != a[y][0]) cir = 0;
		for (x = 1; x < n; x++) 
			if (a[y-1][x-1] != a[y][x]) tep = 0;
	}

	if (cir && tep) printf("Matrica je cirkularna\n");
	else if (tep) printf("Matrica je Teplicova\n");
	else printf("Matrica nije ni cirkularna ni Teplicova\n");
	return 0;
}
