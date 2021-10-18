//zadaca 5 zadnji zadatak
#include <stdio.h>
#include <string.h>
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

int ucitaj_artikle (struct Artikal *niz, int kap) {
	FILE *dat = fopen("artikli.bin", "rb");
	if(!dat) return 0;
	int ucitaj = fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return ucitaj;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap) {
	FILE *dat = fopen("prodavnice.txt", "r");
	if(!dat) return 0;
	int i = 0, j = 0;
	char znak = fgetc(dat);
	while(znak != EOF && i < kap) {
		j = 0;
		while(j < 99 && znak != ',' && znak != EOF) {
			niz[i].naziv[j] = znak;
			znak = fgetc(dat);
			j++;
		}
		niz[i].naziv[j] = '\0';
		while(znak != ',') znak = fgetc(dat);
		if(fscanf(dat, " %d\n", &niz[i].ID) != 1) {
			fclose(dat);
			return i;
		}
		znak = fgetc(dat);
		i++;
	}
	fclose(dat);
	return i;
}

double prosjek_prodavnice (struct Prodavnica p, struct Artikal *a, int na) {
	int i, broj_artikala = 0;
	double prosjek = 0;
	for(i = 0; i < na; i++) {
		if(a[i].prodavnica == p.ID) {
			prosjek += a[i].cijena;
			broj_artikala++;
		}
	}
	prosjek /= broj_artikala;
	return prosjek;
}

int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na) {
	int i, j;
	double prosjek_svih = 0;
	for(i = 0; i < np; i++) prosjek_svih += prosjek_prodavnice(p[i], a, na);
	prosjek_svih /= np;
	for(i = 0; i < np; i++) {
		if(prosjek_prodavnice(p[i], a, na) > prosjek_svih) {
			for(j = i; j < np-1; j++) 
				p[j] = p[j+1];
				i--;
				np--;
		}
	}
	return np;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke) {
	FILE *dat = fopen(ime_datoteke, "wb");
	if(!dat) return 0;
	if(fwrite(p, sizeof(struct Prodavnica), n, dat) != n) return 0;
	if(ferror(dat)) return 0;
	fclose(dat);
	return 1;
}













/*
FILE* ar;
FILE* prod;
struct Artikal {
char naziv[100];
double cijena;
int prodavnica;
};
struct Prodavnica {
char naziv[100];
int ID;
};
int ucitaj_artikle(struct Artikal *niz, int kapacitet)
{
int artikli;
ar=fopen("artikli.bin","rb");
//ukoliko dodje do greske pri otvaranju
if(ar==NULL) exit(1);
artikli=fread(niz,sizeof(struct Artikal),kapacitet,ar);
fclose(ar);
//vraca broj uspjesno ucitanih artikla
return artikli;
}
int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
    int i=0,j=-1;
	prod=fopen("prodavnice.txt","r");
	
	if(prod==NULL) exit(1); //ukoliko dodje do greske pri otvaranju
	do{
		j=-1;
		do{
			
		if(j<99) j++;
		niz[i].naziv[j]=fgetc(prod);
		
	} while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF);
	
	
	niz[i].naziv[j]='\0';
	if(fscanf(prod,"%d\n",&niz[i].ID)==0) break;
	i++;
	} while(feof(prod)!=1 && i<kap);
	fclose(prod);
	return i;
	}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	ar=fopen(ime_datoteke,"wb");
	if(ar==NULL) return 0;
	fwrite(p,sizeof(struct Prodavnica),n,ar);
	if (ferror(ar)) return 0;
	fclose(ar);
	return 1;
	
}*/
int main() {

struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);


	return 0;
}