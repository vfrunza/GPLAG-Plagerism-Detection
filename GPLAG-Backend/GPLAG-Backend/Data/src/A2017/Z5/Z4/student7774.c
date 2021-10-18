#include <stdio.h>
struct Prodavnica{
	char naziv[100];
	int ID;
};
struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;
};
int ucitaj_artikle(struct Artikal *niz, int kap){
	FILE *dat=fopen("artikli.bin", "rb");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke artikli.bin!\n");
		return 0;
	}
	int i,brojac=0;
for ( i = 0; i < kap; i++) {
	int ucitan=fread(&niz[i],sizeof(struct Artikal),1,dat);
	fread(niz[i].naziv,sizeof(niz[i].naziv[0]),sizeof(niz[i].naziv),dat);
	fread(&niz[i].cijena,sizeof(niz[i].cijena),1,dat);
	fread(&niz[i].prodavnica,sizeof(niz[i].prodavnica),1,dat);
	if(ucitan) brojac++;
	else break;
}
	
	fclose(dat);
	return brojac;
	
}
int main() {
	/* AT1: Provjera funkcije ucitaj_artikle (datoteka je data na serveru) */
struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);
	return 0;
}
