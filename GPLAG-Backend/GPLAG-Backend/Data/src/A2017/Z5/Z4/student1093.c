#include <stdio.h>
#include <stdlib.h>

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_artikle( struct Artikal *niz, int kap)
{

	FILE *ulaz = fopen("artikli.bin", "rb");
	if(ulaz == NULL) {
		printf("Greska pri otvaranju datoteke artikli.bin!\n");
		return 0;
	}

	int ucitano = fread(niz, sizeof(struct Artikal), kap, ulaz);
	if(ferror(ulaz)) {
		printf("Greska prilikom citanja iz datoteke");
	}
	fclose(ulaz);
	return ucitano;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	int i = 0, j = 0, id = 0;
	FILE *ulaz = fopen("prodavnice.txt", "r");
	if(ulaz == NULL) {
		printf("Greska pri otvaranju datoteke prodavnice.txt");
		return 0;
	}
	int c = 0;
	while(!feof(ulaz) && i < kap) {
		j = 0;
		while(c != ',') {
			c = getc(ulaz);
			if(c == ',') break;
			niz[i].naziv[j] = c;
			j++;
			if(j == 99) break;
		}
		niz[i].naziv[j] = '\0';
		if(c != ',') while( c != ',') c = getc(ulaz);

		if( c == ',') {
			while( c != '\n' && c != EOF) {

				c = getc(ulaz);
				if(c == '\n' || c == EOF) break;
				id = id * 10 + (c - '0');
			}
			niz[i].ID = id;
			id = 0;
			i++;
		}
	}
	fclose(ulaz);
	return i;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE *dat = fopen(ime_datoteke, "wb");
	if(dat == NULL) {
		printf("Greska pri otvaranju datoteke %s", ime_datoteke);
		return 0;
	}
	int zapisano = fwrite(p, sizeof(struct Prodavnica), n, dat);
	if(zapisano != n) return 0;
	else return 1;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	//OVA FJA NIJE DOVRSENA
	int prosjek = 0, i;
	for(i = 0; i < na; i++) {
		prosjek += a[i].cijena;
	}
	if (na == 0) prosjek = 0;
	else
	prosjek /= na;
	

}



int main()
{
	struct Prodavnica p[] = {
		{"Amko", 1},
		{"Amko", 2},
		{"Amko", 3},
		{"Bingo Tuzla", 10},
		{"Bingo Konjic", 11},
		{"Bingo Pofalici", 12},
		{"Konzum", 20},
		{"Konzum ZG", 21},
	}, v[12];
	printf ("Uspjesno: %d\n", sacuvaj(p, 8, "prod1.bin"));
	printf ("Uspjesno: %d\n", sacuvaj(p, 4, "prod2.bin"));
	printf ("Spaseno:\n");


	FILE *fa = fopen ("prod1.bin", "rb"), *fb = fopen ("prod2.bin", "rb");
	int i;
	for (i = 0; i < 12; ++i)
		fread (v + (i < 8 ? i : i), sizeof *v, (i > 8 ? 1 : (i < 8 ? 1 : 1)), i < 8 ? fa : fb);
	for (i = 0; i < 12; ++i)
		printf ("'%s', ID: %d\n", (v + i)->naziv, v[i].ID);
	fclose (fa);
	fclose (fb);
	return 0;
}
