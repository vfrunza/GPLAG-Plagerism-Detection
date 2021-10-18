#include <stdio.h>
//oblici.dat je binarna dat 
// dodaj_oblik-dodaje na kraj dat vrijednost struct Oblik 
//izbaaci_duple-pronalazi u dat oblike koji imaju isti nazim i izbacuje sve osim prvog 
// daj_najveci- vraca Oblik koji ima najveci obim 

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
	//double cijena;

};

int ucitaj_artikle(struct Artikal *niz, int kap)
{
	int i = 0;
	FILE *dat=fopen("artikli.bin", "rb");
	if(dat==NULL) {
		printf("greska");
		return 0;	//ako dodje do greske vracamo 0 ucitanih artikala
	}
	while(i<kap && fread(&niz[i], sizeof(struct Artikal), 1, dat))
		i++;	//petlju koristimo jer ne znamo koliko artikala treba ucitati, ali znamo da nece biti ucitano vise od "kap" artikala

	fclose(dat);
	return i; //i nam pokazuje koliko je artikala ucitano
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	int i = 0;
	FILE *dat=fopen("prodavnice.txt", "r");
	if(dat==NULL) {
		printf("greska");
		return 0; //ako je doslo do greske 0 osoba je ucitano
	}
	while(i<kap) { //kapacitet je maksimum prodavnica koje mozemo ucitati
		
		int vel = 0;
		do {
		
			char x = fgetc(dat); //ucitavamo znak po znak jer naziv prodavnice moze sadrzavati i razmake
			if(x != ',')
				niz[i].naziv[vel++]=x;
			else break;

		} while(!(feof(dat)));
		niz[i].naziv[vel]='\0';
		niz[i].naziv[99] = '\0';	//treba ucitati samo prvih 99 znakova u nazivu prodavnice, ostale ignorisemo
		if(fscanf(dat, "%d\n", &niz[i].ID) == 0) break; //ucitavamo numericki podatak, ako fscanf vrati 0 doslo je do greske
		i++;
		if(feof(dat)) break;
	}

	fclose(dat);
	return i;
}

double pom_fun(int broj, struct Artikal *a, int na)  //pomocna funkcija koja racuna prosjecnu cijenu artikala jedne prodavnice
{
	int i, br=0;
	double suma=0;
	for(i=0; i<na; i++) {
		if(a[i].prodavnica==broj) {
			br++;
			suma+=a[i].cijena;
		}
	}
	if(br == 0) return -1;
	return suma/br;
}


int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	double veliki_prosjek=0, prosjek=0;
	int spasi=np, br=0, i, j, k;
	for(i = 0; i<na; i++) veliki_prosjek+=a[i].cijena; //racunamo prosjek cijena svih artikala za sve prodavnice
	if(na != 0)	//sprjecavamo moguce eventualno dijeljenje nulom koje dovodi do nedefinisanog ponasanja
		veliki_prosjek/=na;
	else veliki_prosjek = 0;
	for(k=0; k<np; k++) {
		if(pom_fun(p[k].ID, a, na)>veliki_prosjek) {
			br++;
			for(j=k; j<np-1; j++)
				p[j]=p[j+1];
			np--;
			k--;
		}
	}
	return spasi-br;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE *dat=fopen(ime_datoteke, "wb");
	if(dat==NULL) {
		printf("greska");
		return 0;
	}
	fwrite(p, sizeof(struct Prodavnica), n, dat);
	if(ferror(dat)) {
		return 0;
	}
	fclose(dat);
	return 1;
}


int main()
{
	struct Artikal artikli[10];
	int i = ucitaj_artikle(artikli, 10);


	return 0;
}
