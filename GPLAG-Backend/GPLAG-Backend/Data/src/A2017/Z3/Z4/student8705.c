#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j;
	int el = matrica[0][0], pon = 1, lok_pon;
	for (i = 0; i < visina * sirina; i++) {
		lok_pon = 1;
		//Prebrojava koliko se puta clan ponavlja
		for (j = i + 1; j < visina * sirina; j++)
			if(matrica[j / sirina][j % sirina] == matrica[i / sirina][i % sirina])
				lok_pon++;
		//Ako se ponavlja cesce od prethodnog, ili ako se ponavlja isto puta kao prethodni ali je manji, postaje najucestaliji clan
		if (lok_pon > pon) {
			pon = lok_pon;
			el = matrica[i / sirina][i % sirina];
		} else if (lok_pon == pon && matrica[i / sirina][i % sirina] < el)
			el = matrica[i / sirina][i % sirina];
	}
	return el;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
	int i, j, k;
	for (j = 0; j < sirina; j++) {
		for (i = 0; i < visina; i++)
			if (matrica[i][j] == n) {
				sirina--;
				for (k = j; k < sirina; k++)
					for (i = 0; i < visina; i++)
						matrica[i][k] = matrica[i][k+1];
				j--;
				break;
			}

	}
	return sirina;
}

int main()
{
	int mat[100][100], i, j, m, n, n1, br = 1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for (j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
	n1 = n;
	while ((n1 = izbaci_kolone(mat, m, n1, max(mat, m, n1)))) {
		printf("\nNakon %d. prolaza matrica glasi:\n", br);
		for (i = 0; i < m; i++) {
			for (j = 0; j < n1; j++)
				printf("%5d", mat[i][j]);
			printf("\n");
		}
		br++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!", br);
	return 0;
}