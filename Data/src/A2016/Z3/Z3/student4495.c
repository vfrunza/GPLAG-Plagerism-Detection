#include <stdio.h>

int main() {
	int M, N;
	int matr[200][200];
	int visina, slj_vrsta, pom_vrsta, sirina, slj_kolona, pom_kolona;
	int brojac1=0;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		
		if (M < 1 || M > 200 || N < 1 || N > 200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while (M < 1 || M > 200 || N < 1 || N > 200 );
	
	printf("Unesite elemente matrice: ");
	
	for (visina = 0; visina < M; visina++) {
		for (sirina = 0; sirina < N; sirina++) {
			scanf("%d", &matr[visina][sirina]);
		}
	}
	
	//Izbacivanje vrste iz matrice
	
	
	for (visina = 0; visina < M; visina++) {
		for (slj_vrsta = visina + 1; slj_vrsta < M; slj_vrsta++) {
			for (sirina = 0; sirina < N; sirina++) {
			if ( matr[visina][sirina] == matr[slj_vrsta][sirina])
				brojac1++;
			}
			if (brojac1 == N) {
				for (pom_vrsta = slj_vrsta; pom_vrsta < M-1; pom_vrsta++) {
					for (pom_kolona = 0; pom_kolona < N; pom_kolona++) {
						matr[pom_vrsta][pom_kolona] = matr[pom_vrsta+1][pom_kolona];
					}
				}
				M--;
				slj_vrsta--;
			}
			brojac1=0;
		}
	}
	
	//Izbacivanje kolone iz matrice
	
	for (sirina = 0; sirina < N; sirina++) {
		for (slj_kolona = sirina + 1; slj_kolona < N; slj_kolona++) {
			for (visina = 0; visina < M; visina++) {
				if (matr[visina][sirina] == matr[visina][slj_kolona])
					brojac1++;
			}
			if (brojac1 == M) {
				for (pom_kolona = slj_kolona; pom_kolona < N-1; pom_kolona++ ) {
					for (pom_vrsta = 0; pom_vrsta < M; pom_vrsta++) {
						matr[pom_vrsta][pom_kolona] = matr[pom_vrsta][pom_kolona+1];
					}
				}
				N--;
				slj_kolona--;
			}
			brojac1=0;
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (visina = 0; visina < M; visina ++) {
		for (sirina = 0; sirina < N; sirina++) {
			printf("%5d", matr[visina][sirina]);
		}
		printf("\n");
	}
	
	
	return 0;
}
