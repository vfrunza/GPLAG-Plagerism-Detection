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

int ucitaj_artikle (struct Artikal *niz, int kap)
{
	FILE *ulaz;
	char noviniz[100];
	ulaz = fopen("artikli.bin", "rb");
	int i;
	for(i=0;i<kap;i++){
		noviniz[i]=niz[i].naziv;
		printf("%d", noviniz[i]);
		
	}
	int ucitano = fread("artikli.bin", sizeof(struct Artikal), 100, ulaz);
	fclose(ulaz);

	return ucitano;
}
int main()
{
	struct Artikal niz[100];
	ucitaj_artikle(niz, 100);
	return 0;
}
