#include <stdio.h>
#define MAX_DIM 100

int main() {
	int a[MAX_DIM][MAX_DIM], b[MAX_DIM][MAX_DIM], c[MAX_DIM][MAX_DIM];
	int n, m;
	int i, j, im1, jm1, im2, jm2, tmp;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &m, &n);
	}
	while (n < 0 || n > 100 || m < 0 || m > 100);
	
	/* Unos matrica */
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
			
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
			
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	
	/* Ako su dimenzije 0x0, 0xn ili mx0, po defaultu su sve matrice prazan
	   skup, cime su u isto vrijeme jednake, cime ovaj slucaj zavrsava */
	if (n == 0 || m == 0) {
		printf("DA\n");
		return 0;
	}
			
	/* Da bi provjerili da li se sastoje od istih elemenata matrice
	   mozemo ih sve tri sortirati, te potom gledati da li su im elementi na
	   poziciji [i][j] jedanki */
	
	/* BUBBLE SORT */
	/* Posto su sve tri matrice istih dimenzija, mozemo ih sortirati
	   u jednom 'cugu'*/
	/* Sortiranje se vrsi tako sto se matrica posmatra kao niz, koji se pravi
	   tako sto red stavljamo poslije prethodnog i dijelovi od n elemenata su
	   redovi, a i % n predstavlja broj kolone u kojoj se prvobitno nalazio,
	   ako je i index elementa u tom novonastalom nizu*/
	for (i = 0; i < n * m; i++) {
		im1 = i / n;
		jm1 = i % n;
		
		for (j = i + 1; j < n * m; j++) {
			im2 = j / n;
			jm2 = j % n;
			
			/* Sortiranje niza A */
			if (a[im1][jm1] > a[im2][jm2]) {
				tmp = a[im1][jm1];
				a[im1][jm1] = a[im2][jm2];
				a[im2][jm2] = tmp;
			}
			
			/* Sortiranje niza B */
			if (b[im1][jm1] > b[im2][jm2]) {
				tmp = b[im1][jm1];
				b[im1][jm1] = b[im2][jm2];
				b[im2][jm2] = tmp;
			}
			
			/* Sortiranje niza C */
			if (c[im1][jm1] > c[im2][jm2]) {
				tmp = c[im1][jm1];
				c[im1][jm1] = c[im2][jm2];
				c[im2][jm2] = tmp;
			}
		}
		
		/* Poslije svih izmjena i-ti element u novonastalom nizu je u finalnoj
		   poziciji, sto znaci ako su oni razliciti za neke dvije matrice
		   mozemo prekinuti egzikuciju sortiranja i pretpostaviti da nisu
		   sastavljene od istih elemenata */
		if (a[im1][jm1] != b[im1][jm1] || b[im1][jm1] != c[im1][jm1])
			break;
	}
	
	/* Ukoliko je petlja izvrsena do kraja
	   onda su matrice sastavljene od istih elemenata */
	if (i == n * m)
		printf("DA\n");
	else
		printf("NE\n");

	return 0;
}
