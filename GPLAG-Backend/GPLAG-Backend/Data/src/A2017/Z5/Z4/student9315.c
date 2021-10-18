#include <stdio.h>

struct Prodavnica {
	char naziv[100];
	int ID;				
};
struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;		
};		

int ucitaj_artikle (struct Artikal *niz, int kap) {
	FILE* ulaz = fopen("artikli.bin", "rb");
	int br = fread(niz, sizeof(struct Artikal), kap, ulaz);
	fclose(ulaz);
	return br;
}

void zapisi_artikle(struct Artikal* niz, int vel) {
	FILE* izlaz = fopen("artikli.bin", "wb");
	fwrite(niz, sizeof(struct Artikal), vel, izlaz);
	fclose(izlaz);
}

int main() {
	struct Artikal artikli[1000] = {
		{ "Brasno", 5.2, 1},
		{ "Ulje", 2, 1},
		{ "Secer", 1.5, 1},
		{ "Brasno", 5.2, 2},
		{ "Ulje", 2.1, 2},
		{ "Secer", 2.2, 2},
		{ "Brasno", 5.2, 3},
		{ "Ulje", 1.1, 3},
		{ "Secer", 1.2, 3},
		{ "Grah", 5, 3},
	};
	/*zapisi_artikle(artikli, 10);
	return 0;
	*/
	int vel = ucitaj_artikle(artikli, 1000);
	int i;
	for (i=0; i<vel; i++) {
		printf("%s %g %d\n", artikli[i].naziv, artikli[i].cijena, artikli[i].prodavnica);
	}
}