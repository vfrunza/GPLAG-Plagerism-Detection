#include <stdio.h>

int main() {
	int m, n, i, j;
	double ma[110][110];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if (m <= 0 || m > 100 || n <= 0 || n > 100) printf("Pogresan unos!\n");
		
	} while (m <= 0 || m > 100 || n <= 0 || n > 100);
	printf("Unesite elemente matrice: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%lf", &ma[i][j]);
			

	int tacno, cirkularna, teplicova;
	cirkularna = teplicova = 1;
	for (i = 1; i < m; i++) {
		tacno = 1;
		for (j = 0; j < n; j++) {
			if (j == 0) {
				if (ma[i][0] != ma[i - 1][n - 1]) {
					tacno = 0;
					break;
				}
			}
			else {

				if (ma[i][j] != ma[i - 1][j - 1]) {
					tacno = 0;
					break;
				}
			}
		}
		if (tacno == 0) {
			cirkularna = 0;
			break;
		}
	}
	if (cirkularna) {
		printf("Matrica je cirkularna\n");
		return 0;
	}
	
	
	
	int poc_vri = n - 1;
	int nova_koordinata_reda = 0;
	while (1) {
		tacno = 1;
		//printf("Uporedjujem sa : %d, %d i to je element ", 1, poc_vri + 1);
		//printf("%g\n", ma[0][poc_vri]);
		nova_koordinata_reda = 0;
		for (j = poc_vri; j < n; j++) {
			if (ma[nova_koordinata_reda][j] != ma[0][poc_vri]) {
				tacno = 0;
				//printf("OVAJ SE RAZLIKUJE\n");
				break;
			}	
			//printf("%d,%d - element : %g\n", nova_koordinata_reda + 1, j + 1, ma[nova_koordinata_reda][j]);
			nova_koordinata_reda++;
			if (nova_koordinata_reda == m) break;
		}
		//printf("\n");
		if (tacno == 0) {
			teplicova = 0;
			break;
		}
		poc_vri--;
		if (poc_vri == -1) break;
	}
	
	poc_vri = 0;
	
	while (1) {
		nova_koordinata_reda = 0;
		tacno = 1;
		//printf("Uporedjujem sa : %d, %d i to je element ", poc_vri + 1, 1);
		//printf("%g\n", ma[poc_vri][0]);
		for (i = poc_vri; i < m; i++) {
			if (ma[i][nova_koordinata_reda] != ma[poc_vri][0] && poc_vri < m) {
				tacno = 0;
				//printf("OVAJ SE RAZLIKUJE\n");
				break;
			}
			//printf("%d, %d - element %g\n", i + 1, nova_koordinata_reda + 1, ma[i][nova_koordinata_reda]);
			nova_koordinata_reda++;
			if (nova_koordinata_reda == n) break;
		}
		//printf("\n");
		if (tacno == 0) {
			teplicova = 0;
			break;
		}
		poc_vri++;
		if (poc_vri == m - 1) break;
	}
	if (!teplicova) {
		printf("Matrica nije ni cirkularna ni Teplicova\n");
		return 0;
	}
	printf("Matrica je Teplicova\n");
	return 0;
}
