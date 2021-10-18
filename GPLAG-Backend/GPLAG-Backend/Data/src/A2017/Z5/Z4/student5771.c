#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
FILE*artikli;
FILE*prodavnice;

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
	int ucitani;
	artikli=fopen("artikli.bin","rb");

	if(!artikli) /* Greska u otvaranju? artikli - NULL*/
		exit(1);

	ucitani=fread(niz,sizeof(struct Artikal),kap,artikli);
	fclose(artikli);
	return ucitani;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	int i=0;
	int j=-1;
	prodavnice=fopen("prodavnice.txt","r");

	if(!prodavnice) /* Greska u otvaranju? prodavnice - NULL */
		exit(1);

	do {

		j=-1;
		do {
			if(j<99) j++;
			niz[i].naziv[j] = fgetc(prodavnice);
		} while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF);

		niz[i].naziv[j]='\0';
		if(fscanf(prodavnice,"%d\n",&niz[i].ID)==0) break;
		i++;

	} while(!feof(prodavnice) && i<kap);

	fclose(prodavnice);
	return i;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	double suma_svih=0.0, prosjek_svih;
	double suma_temp=0.0, prosjek_temp;
	int i=0,j=0,k=0;
	int valid=0;

	do {
		j=0;

		do {
			if(p[i].ID==a[j].prodavnica) {  /* Da li je izbacivanje uopste potrebno? */
				valid=1;  /* ID-ovi prodavnica odgovaraju ID-u kod artikala */
				break;
			}
			j++;
		} while(j<na);

		i++;
	} while(i<np);

	if(!valid) return np;

	i=0;
	j=0;
	do {
		suma_svih+=a[i].cijena;
		j++;
		i++;
	} while(i<na);

	prosjek_svih=suma_svih/j;

	i=0;
	j=0;
	do {
		do {
			if(p[i].ID==a[j].prodavnica) {
				suma_temp+=a[j].cijena;
				k++;
			}
			j++;
		} while(j<na);

		prosjek_temp=suma_temp/k;
		if(prosjek_temp>prosjek_svih) {
			for(k=i; k<np-1; k++) {
				p[k]=p[k+1];
			}
			i--;
			np--;
		}

		k=0;
		j=0;
		i++;
		suma_temp=0.0;
	} while(i<np);

	return np;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	artikli=fopen(ime_datoteke,"wb");

	if(!artikli) return 0;

	fwrite(p,sizeof(struct Prodavnica),n,artikli);
	if(ferror(artikli)) return 0;
	fclose(artikli);

	return 1;
}


int main()
{
	FILE *fa, *fb;
	int i;
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

	fa = fopen ("prod1.bin", "rb");
	fb = fopen ("prod2.bin", "rb");

	for (i = 0; i < 12; ++i)
		fread (v + (i < 8 ? i : i), sizeof *v, (i > 8 ? 1 : (i < 8 ? 1 : 1)), i < 8 ? fa : fb);
	for (i = 0; i < 12; ++i)
		printf ("'%s', ID: %d\n", (v + i)->naziv, v[i].ID);
	fclose (fa);
	fclose (fb);

	return 0;
}