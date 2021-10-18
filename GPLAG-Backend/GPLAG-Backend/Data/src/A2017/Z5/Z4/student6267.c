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

int ucitaj_artikle(struct Artikal *niz, int kap)
{
	int ucitano;
	FILE* dat = fopen("artikli.bin", "rb");
	if (!dat) {
		printf("Neuspjesno otvaranje datoteke!");
		exit(1);
	}
	ucitano = fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return ucitano;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	FILE* dat = fopen("prodavnice.txt", "r");
	int j;
	char temp;
	if (!dat) {
		printf("Neuspjesno otvaranje datoteke!");
		exit(1);
	}
	int i=0;
	while (i<kap) {
		j=-1;
		do {
			if(j<99)
				j++;
			else {
				do {
					temp=fgetc(dat); // Ako dodje do 100tog elementa, pomjeramo pokazivac u datoteci do broja ne radeci nista vise sa nizom, da ne bi otisli van granica niza
				} while(temp!=',');
				break;
			}
			niz[i].naziv[j]=fgetc(dat);
		} while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF); // fgetc se koristi zbog moguceg postojanja razmaka
		niz[i].naziv[j]='\0';
		if (fscanf(dat, "%d\n", &niz[i].ID)!=1)
			break;
		i++;
	}
	fclose(dat);
	return i;
}
int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a,int na)
{
	float prosjecnacijenasvih=0, prosjecnacijenaprodavnice, sumasvih=0, sumaprodavnice;
	int i=0, brojartikala=0, brojartikalaprodavnice, j;
	for (i=0; i<na; i++) {
		sumasvih+=a[i].cijena;
		brojartikala++;
	}
	if (brojartikala>0) prosjecnacijenasvih=sumasvih/brojartikala;

	for (i=0; i<np; i++) {
		sumaprodavnice=0;
		brojartikalaprodavnice=0;
		prosjecnacijenaprodavnice=0;
		for(j=0; j<na; j++) {
			if (a[j].prodavnica==p[i].ID) {
				sumaprodavnice+=a[j].cijena; // Ako se ID podudara sa brojem prodavnice artikla, onda dodajemo na sumu, i trazimo prosjecnu cijenu
				brojartikalaprodavnice++;
			}
		}
		if (brojartikalaprodavnice>0) prosjecnacijenaprodavnice=sumaprodavnice/brojartikalaprodavnice;
		if (prosjecnacijenaprodavnice>prosjecnacijenasvih) {
			for (j=i; j<np-1; j++) // Standardni algoritam za izbacivanje iz niza
				p[j]=p[j+1];
			np--;
			i--;
		}
	}
	return np;
}
int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE* dat;
	dat=fopen(ime_datoteke, "wb");
	if (dat==NULL)
		return 0;
	int i;
	for(i=0; i<n; i++) {
		fwrite(&p[i], sizeof(struct Prodavnica), 1, dat);
		if (ferror(dat))
			return 0;
	}
	fclose(dat);
	return 1;
}
int main()
{
	int i, j;
	struct Prodavnica p[] = {
		{"Amko", 1},
		{"Bingo", 2},
		{"Konzum", 3},
	};
	struct Artikal a[] = {
		{"Kiseli kupus", 10, 4},
		{"Bickl", 1000, 5},
		{"Krastavci", 2, 4}
	};
	a[0].prodavnica=1;
	a[1].prodavnica=2;
	a[3].prodavnica=1;

	i = izbaci_skupe(p, 3, a, 3);
	for (j = 0; j < i; ++j)
		printf ("%s, ID: %d\n", p[j].naziv, p[j].ID);
	return 0;
}
