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

int ucitaj_artikle(struct Artikal *niz, int kap)
{
	int n = 0;
	FILE *f = fopen("artikli.bin", "rb");
	if (!f) return 0;
	n = fread(niz, sizeof(struct Artikal), kap, f);
	fclose(f);
	return n;
}
int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	int n = 0, i = 0, kraj = 0;
	char c=' ';
	FILE *f = fopen("prodavnice.txt", "r");
	if (!f) return 0;
	while (n < kap) {
		i = 0;
		do {
			c = fgetc(f);
			if(c==EOF) {
				fclose(f);
				return n;
			}
			if(c == ',') break;
			if (c == '\n') continue;
			//Ucitava znakove u naziv ako broj znakova nije veci od velicine stringa
			if (i < 99) {
				niz[n].naziv[i] = c;
				kraj = i+1;
			} else if (!kraj) kraj = i;
			i++;
		} while (1);
		niz[n].naziv[kraj] = 0;
		if (fscanf(f, "%d", &niz[n].ID) != 1) {
			fclose(f);
			return n;
		}
		n++;
	}
	fclose(f);
	return n;
}
//Prosjecna cijena svih artikala za jednu prodavnicu
double prosjecna_cijena(struct Prodavnica p, struct Artikal *a, int na)
{
	double t = 0;
	int i = 0, n = 0;
	for (i = 0; i < na; i++)
		if (a[i].prodavnica == p.ID) {
			n++;
			t += a[i].cijena;
		}
	return n == 0 ? 0 : t / n;
}
//Cijena svih artikala za jednu prodavnicu
int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int i, j;
	double prosjek = 0;
	//Racuna prosjecnu cijenu svih artikala za sve prodavnice
	for (i = 0; i < np; i++)
		prosjek += prosjecna_cijena(p[i], a, na);
	if (np) prosjek /= np;
	for (i = 0; i < np; i++)
		if (prosjecna_cijena(p[i], a, na) > prosjek) { //Izbacivanje prodavnica
			np--;
			for (j = i; j < np; j++)
				p[j] = p[j+1];
			i--;
		}
	return np;
}
int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE *f = fopen(ime_datoteke, "wb");
	if (!f) return 0;
	if (fwrite(p, sizeof(struct Prodavnica), n, f) != n || ferror(f)) {
		fclose(f);
		return 0;
	}
	fclose(f);
	return 1;
}
int main()
{
	return 0;
}