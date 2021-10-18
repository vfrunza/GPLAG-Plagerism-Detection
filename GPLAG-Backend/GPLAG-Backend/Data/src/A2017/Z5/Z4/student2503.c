#include <stdio.h>
#include <stdlib.h>
/* Strukture koje se koriste u zadatku*/
struct Prodavnica {
	char naziv[100];
	int ID;
};
struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};
/* Funkcija koja ucitaje artikle iz binarne datoteke*/
int ucitaj_artikle (struct Artikal *niz, int kap)
{
	int i=0;
	FILE * ulaz=fopen("artikli.bin","rb");
	if (ulaz == NULL) {
		exit (1);
	}
	/* Petlja radi dok je brojac manji od zadanog broja "kap" i dok se artikli pravilno ucitavaju, tj. funkcija fread vraca odgovarajuci broj*/
	while(i<kap && fread(niz,sizeof *niz,1,ulaz)==1) {
		niz++;
		i++; /* Brojac koji broji koliko arikala se ucitalo*/
	}
	fclose(ulaz);
	return i;
}
/* Funckija koja ucitaje prodavnice iz tekstualne datoteke*/
int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	int i=0,k=0;
	FILE *ulaz=fopen("prodavnice.txt","r");
	if (ulaz == NULL) {
		exit (1);
	}
	for(i=0; i<kap; i++) {
		char temp=fgetc(ulaz); /*Ucitajemo element po element tipa char*/
		if(temp==EOF) return i;
		while(temp!=',' && k<99) { /*Charove ucitajemo dok ne dođemo do chara zarez i dok je broj ucitanih charova manji od odgovarajuceg ogranicenja, tada se petlja prekida, te smo time ucitali naziv prodavnice*/
			niz[i].naziv[k]=temp;
			k++;
			temp=fgetc(ulaz);
		}
		while(temp!=',') /*Ovom petljom pomjeramo kursor dok ne naleti na zarez, a ovaj dio se koristi ukoliko je prethodna petlja prekinuta zbog duzine*/
			temp=fgetc(ulaz);
		niz[i].naziv[k]='\0'; /*Obiljezavamo kraj ucitane rijeci*/
		k=0;
		fscanf(ulaz,"%d\n",&niz[i].ID); /*Ucitavamo ID prodavnice, tj. broj tipa int*/
	}
	fclose(ulaz);
	return i;
}
int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	int i=0;
	FILE* ulaz=fopen(ime_datoteke,"wb");
	if(ulaz==NULL) {
		return 0;
	}
	for(i=0; i<n; i++) {
		fwrite (p , sizeof *p, 1 , ulaz);
		p++;
		if(ferror(ulaz)) return 0;
	}
	fclose(ulaz);
	return 1;
}
int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int i=0,j=0,k=0,broj=0;
	double prosjek=0,prosjek_svih=0;

	for(i=0; i<na; i++) {
		prosjek_svih+=a[i].cijena; /*Prolazimo kroz niz i u međuvremenu sabiremo cijene svih artikala*/
	}
	prosjek_svih/=na; /*Prosjek je ukupna suma svih artikala podjeljena sa brojem artikala*/
	for(i=0; i<np; i++) {
		for(j=0; j<na; j++) {
			if(p[i].ID==a[j].prodavnica) { /* Prolazeci kroz petlju trazimo odgovarajuci artikal za neku prodavnicu*/
				prosjek+=a[j].cijena; /*Kada smo pronasli odgovarajuci artikal, njegovu cijenu dodajemo na sumu cijena artikala odgovarajuce prodavnice*/
				broj++; /*Brojimo broj artikala jedne prodavnice*/
			}
		}
		if(broj==0) continue; /*Ako prodavnica nema artikala prelazimo na sljedecu prodavnicu*/
		prosjek/=broj; /*Racunamo prosjek tako sto sumu cijena artikala jedne prodavnice dijelimo s brojem artikala te prodavnice*/
		/*Petlja koja izbacuje prodavnicu koja ima prosjecnu cijenu svojih artikala vecu od prosjecne cijene svih artikala svih prodavnica*/
		if(prosjek>prosjek_svih) {
			for(k=i; k<np-1; k++)
				p[k]=p[k+1];
			i--; /* Brojac smanjujemo kako bi se ispitala i prodavnica koja je dosla na mjesto izbacene, tj. kako ne bi bila preskocena*/
			np--; /*Broj prodavnica smanjujemo*/
		}
		prosjek=0;
		broj=0;
	}
	return np;
}
int main()
{
	return 0;
}
