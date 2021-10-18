#include <stdio.h>

int main()
{
	int a[150][150], b[150][150];
	int aWidth, bWidth, aHeight, bHeight;
	int i, j;

	/* Unos dimenzija i clanove matrice A */
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &aWidth, &aHeight);

	printf("Unesite clanove matrice A: ");
	for (i = 0; i < aHeight; i++)
		for (j = 0; j < aWidth; j++)
			scanf("%d", &a[i][j]);

	/* Unos dimenzija i clanove matrice B */
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &bWidth, &bHeight);

	printf("Unesite clanove matrice B: ");
	for (i = 0; i < bHeight; i++)
		for (j = 0; j < bWidth; j++)
			scanf("%d", &b[i][j]);

	/* Nekompatibilne matrice (formati im se ne podudaraju) */
	/* Nisu formata NxM i MxN, te time rotiranjem je nemoguce dobiti istu */
	if (aHeight != bWidth || aWidth != bHeight) {
		printf("NE\n");
		return 0;
	}

	/* Provjera svakih clanova */
	/* Clan A u i-tom redu i j-toj koloni mora biti jednak
	   clanu B u j-tom redu i i-toj koloni sa lijeva */
	for (i = 0; i < aHeight; i++)
		for (j = 0; j < aWidth; j++)
			if (a[i][j] != b[j][bWidth - i - 1]) {
				printf("NE\n");
				return 0;
			}

	/* Ukoliko su obje petlje izvrsene do kraja,
	   tj. ako nije nasao niti jedan jedini clan koji im je razlicit,
	   ispisujemo DA */
	printf("DA\n");

	return 0;
}
