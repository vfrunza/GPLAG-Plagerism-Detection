#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Datum  {
	int dan;
	int mjesec;
	int godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};


void unesi (char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int ukupan_broj_dana (struct Datum d)
{
	int ukupno_dana;

	ukupno_dana = 365* d.godina + d.godina/4 - d.godina/100 + d.godina/400 + d.dan + (153*d.mjesec+8)/5;
	return ukupno_dana;

}

int odgovara(char* kandidat, char* direktor)
{

	char* p;

	while(strchr(kandidat, ' ') != NULL) {
		kandidat = strchr (kandidat, ' ');
		kandidat++;
	}

	while(strchr(direktor, ' ') != NULL) {
		direktor = strchr(direktor,' ');
		direktor++;
	}

	if(strchr(kandidat, '-') == NULL) {
		if(strchr(direktor, *kandidat) != NULL) return 1;
	}

	else {
		p = strchr(kandidat, '-');
		p++;
		kandidat[p-kandidat-1] = '\0';
		if(strchr(direktor,*p)!= NULL) {
			kandidat[p - kandidat - 1] = '-';
			return 1;
		}
		if(strchr(direktor,*kandidat) != NULL) {
			kandidat[p - kandidat -1] = '-';
			return 1;
		}
	}
	return 0;
}

int izbaci(struct Uposlenik* kandidati, int vel, int broj)
{
	while (broj < vel -1) {
		*(kandidati + broj) = *(kandidati + broj + 1);
		broj++;
	}
	vel-=1;
	return vel;
}

int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana);

int main()
{	
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1978} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1979 } },
    { "Pero Peric", { 1, 2, 1979 } },
    { "Sara Sarac", { 2, 2, 1979 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1978 } },
    { "Suljo Suljic", { 15, 1, 1982 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, 29);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);

/* Ispravka za funkcije koje ne rade nista */
kandidati[2].datum_rodjenja.godina = 1977;
novi_br = suzi_listu(kandidati, 7, direktor, 29);
printf("Novi broj: %d\n", novi_br);

return 0;
}


int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i = 0, dir_datum, kan_datum;
	dir_datum = ukupan_broj_dana(direktor.datum_rodjenja);
	kan_datum = ukupan_broj_dana(kandidati[i].datum_rodjenja);
	
	for (i = 0; i < vel; i++) {
		kan_datum = ukupan_broj_dana(kandidati[i].datum_rodjenja);
		if ((dir_datum - kan_datum) > broj_dana) {
			if(odgovara(kandidati[i].ime_prezime, direktor.ime_prezime)!= 1) {
				vel = izbaci(kandidati,vel,i);
				i--;
			}

		}
		
		i++;
	}
	return vel;
}
