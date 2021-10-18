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

int ucitaj_artikle (struct Artikal *niz, int kap)
{
	int ucitano;
	FILE *ulaz=fopen("artikli.bin", "rb");

	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke artikli.bin.\n");
		return 0;
	}

	ucitano=fread(niz, sizeof(struct Artikal), kap, ulaz);
	fclose(ulaz);
	return ucitano;
}

int upis (char *tmp, char  *pr)
{
	char *p=tmp, *s=pr;
	int id=0, i=0;

	while(*p++!='\0') {
		if(*p=='\n') *p='\0';
	}

	p=tmp;
	while (*p!='\0' && i<100) {
		if(*p!=',') {
			*s=*p;
			s++;
			p++;
			i++;
		}
		if(*p==',') break;
	}
	*s='\0';
	p++;
	while(*p!='\0')
		id=id*10 + *p++-'0';
	return id;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	char tmp[1000];
	int i=0;
	FILE *ulaz=fopen("prodavnice.txt", "r");

	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke prodavnice.txt.\n");
		return 0;
	}

	while(fgets(tmp, 1000, ulaz) && i<kap) {
		niz[i].ID=upis(tmp, niz[i].naziv);
		i++;
	}

	return i;

}



int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	double prosjek_svih=0, prosjek_prodavnice=0;
	int i, j , k=0;

	for(i=0; i<na; i++) {
		prosjek_svih+= a[i].cijena;
	}

	prosjek_svih/=na;

	for(i=0; i<np; i++) {
		prosjek_prodavnice=0;
		k=0;
		for(j=0; j<na; j++) {
			if(a[j].prodavnica==p[i].ID) {
				prosjek_prodavnice+=a[j].cijena;
				k++;
			}
		}
		prosjek_prodavnice/=k;

		if(prosjek_prodavnice>prosjek_svih) {
			for(k=i; k<np-1; k++) {
				p[k]=p[k+1];
			}
			i--;
			np--;
		}

	} 

	return np;
}

int sacuvaj ( struct Prodavnica *p, int n, const char *ime_datoteke)
{
	int zapisano;
	FILE *izlaz=fopen (ime_datoteke, "wb");
	if(izlaz==NULL) {
		printf("Greska pri otvaranju datoteke %s.bin.\n", ime_datoteke);
		return 0;
	}


	zapisano= fwrite(p, sizeof(struct Prodavnica), n, izlaz);
	if (ferror(izlaz)) {
		printf("Greska prilikom pisanja u datoteku %s.bin.\n", ime_datoteke);
		printf("Zapisano je samo %d prodavnica.\n", zapisano);
	}

	fclose(izlaz);
	return 1;

}

int main()
{

	return 0;
}
