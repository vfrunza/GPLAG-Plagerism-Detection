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
int ucitaj_artikle (struct Artikal *niz, int kap){
	FILE* ulaz=fopen("artikli.bin","rb");
	if(ulaz==NULL)
	{printf("Greska!"); return 1;}
	int velicina;
	velicina=fread(niz,sizeof(struct Artikal),kap,ulaz);
	printf("%d   ",velicina);
	return velicina;
}

int main() {
/* AT1: Provjera funkcije ucitaj_artikle (datoteka je data na serveru) */
struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; i++)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);

	return 0;
}
