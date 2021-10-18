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
	FILE* ulaz;
	int ucitano;
	
	ulaz=fopen("artikli.bin", "rb");
	if (ulaz==NULL) return 0;
	
	while(fread(niz, sizeof(struct Artikal), kap, ulaz)==) {
		
	}
	fclose(ulaz);
	return ucitano;
}



int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
