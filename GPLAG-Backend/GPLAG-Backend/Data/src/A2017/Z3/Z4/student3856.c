//nadijina verzija
#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int niz[10000], i, j, z=0, br1=0, br2=0, broj;
	//Pretvaramo matricu u niz, radi jednostavnijeg pronalaska trazenog clana
	for(i = 0; i<visina; i++) {
		for(j = 0; j<sirina; j++) {
			niz[z] = matrica[i][j];
			z++;
		}
	}
	//poredimo fiksno n[i] sa svakom clanom niza, te brojac povecavamo ukoliko naidjemo na istu vrijednost, 
	//zatim u pomocni brojac smjestamo vrijednost trenutnog brojaca samo ukoliko je on veci od vrijednosti na pomocnome brojacu, 
	//te promjenljivoj broj dodijelimo odgovarajucu vijednost niz[i]
	for(i = 0; i<z; i++) {
		br1 = 0;
		for(j = 0; j<z; j++) {
			if(niz[i] == niz[j]) br1++;
		}
		if(br2 < br1) {
			br2 = br1;
			broj = niz[i];
		} else if(br2 == br1) {
			if(niz[i] < broj)
				broj = niz[i];
		}
	}
	return broj;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	//standardan kod za izbacivanje kolona iz matrice
	int i, j, z, k;
	for(i = 0; i<visina; i++) {
		for(j = 0; j<sirina; j++) {
			if(matrica[i][j] == N) {
				for(z = 0; z<visina; z++) {
					for(k = j; k<sirina-1; k++) {
						matrica[z][k] = matrica[z][k+1];
					}
				}
				sirina--;
				j--;
				i = 0;
			}

		}

	}

	return sirina;
}
int main()
{
	int sirina, visina, matrica[100][100], i, j, broj, nova_sirina, z;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i = 0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	for(z = 0; z<visina; z++) {
		broj = max(matrica, visina, sirina);
		nova_sirina = izbaci_kolone(matrica, visina, sirina, broj);
		if(nova_sirina == 0) break;
		printf("\nNakon %d. prolaza matrica glasi: \n", z+1);
		for(i = 0; i<visina; i++) {
			for(j = 0; j<nova_sirina; j++) {
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
		sirina = nova_sirina;
	}
	printf("\nNakon %d. prolaza matrica je prazna!", z+1);

	return 0;
}
