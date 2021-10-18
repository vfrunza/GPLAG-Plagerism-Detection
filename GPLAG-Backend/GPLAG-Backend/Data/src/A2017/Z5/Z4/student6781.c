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
int ucitaj_prodavnice(struct Prodavnica *niz,int kap)
{
	FILE *ulaz=fopen("prodavnice.txt","r");
	int i,brojac=0;
	int k;
	if (ulaz==NULL) {
		printf ("Greska prilikom otvaranja datoteke prodavnice.txt!");
		return 0;
	}
	/* Nakon otvaranja datoteke, citamo podatke u niz, s tim sto string citamo karakter po karakter,zbog potencijalnih ramzaka*/
	for (i=0; i<kap; i++) {
		k=-1;
		do {
			if (k<99) k++;
			niz[i].naziv[k]=fgetc(ulaz);
		} while (niz[i].naziv[k]!=',' && niz[i].naziv[k]!=EOF);
		niz[i].naziv[k]='\0';
		if (fscanf(ulaz,"%d\n",&niz[i].ID)!=1) {
			fclose(ulaz);
			break;
		}
		brojac++;
	}
	return brojac;
}
int izbaci_skupe (struct Prodavnica *p,int np,struct Artikal *a,int na)
{
	int i,j;
	double prosjek_u,suma_u=0,prosjek_p,suma_p=0;
	int brojac=0,brojac_p=0;
	/*Prvom petljom trazimo ukupni prosjek svih prodavnica*/
	for (i=0; i<np; i++) {
		for (j=0; j<na; j++) {
			if (p[i].ID==a[j].prodavnica) {
				suma_u+=a[j].cijena;
				brojac++;
			}
		}
	}
	prosjek_u=suma_u/brojac;
	/*Drugom petljom trazimo pojedinacni prosjek,a ako je veci od prosjeka svih prodavnica, izbacujemo tu prodavnicu iz niza*/
	for (i=0; i<np; i++) {
		for (j=0; j<na; j++) {
			if (p[i].ID==a[j].prodavnica) {
				suma_p+=a[j].cijena;
				brojac_p++;
			}
		}
		prosjek_p=suma_p/brojac_p;
		if (prosjek_p>prosjek_u) {
			for (j=i; j<np-1; j++)
				p[j]=p[j+1];
			np--;
		}
		suma_p=0;
		brojac_p=0;
	}
	return np;
}
int ucitaj_artikle (struct Artikal* niz,int kap)
{
	FILE* dat;
	int vrati;
	dat=fopen("artikli.bin","rb");
	if (dat==NULL)
		return 0;
	vrati=fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return vrati;
}
int sacuvaj (struct Prodavnica *p,int n, const char* ime_datoteke)
{
	FILE *dat=fopen(ime_datoteke,"wb");
	int sacuvaj;
	if (dat==NULL)
		return 0;
	sacuvaj=fwrite(p,sizeof(struct Prodavnica),n,dat);
	if (ferror(dat))
		return 0;
	fclose(dat);
	return 1;
}

int main()
{
	return 0;
}
