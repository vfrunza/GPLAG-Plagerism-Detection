#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina)
{
	if((godina%4==0 && godina%100!=0) || godina%400==0) return 1;
	return 0;
}

int pretvori_u_dane(struct Datum d)
{
	int suma = 0, i = 1;
	while(d.godina>i) {
		if(prestupna(i)) suma += 366;
		else suma += 365;
		i++;
	}
	i = 0;
	for(i=1; i<d.mjesec; i++) {
		if(i<=7) {
			if(i%2!=0) suma+=31;
			else if(i == 2) {
				if(prestupna(d.godina)) suma += 29;
				else suma += 28;
			} else suma += 30;
		} else {
			if(i%2 != 0) suma += 30;
			else suma += 31;
		}
	}

	suma += d.dan;
	return suma;
}

int poklapa(char *kandidat, char *direktor)
{

	while(strchr(kandidat, ' ') != NULL) {
		kandidat = strchr(kandidat, ' ');
		kandidat++;
	}
	while(strchr(direktor, ' ') != NULL) {
		direktor = strchr(direktor, ' ');
		direktor++;
	}
	if(strchr(kandidat, '-') == NULL) {
		if(strchr(direktor, kandidat) != NULL) return 1;
	} else {
		char *pom;
		pom = strchr(kandidat, '-');
		pom++;
		kandidat[pom-kandidat-1] = '\0';
		if(strstr(direktor, pom) != NULL) {
			kandidat[pom - kandidat - 1] = '-';
			return 1;
		}
		if(strstr(direktor, kandidat) != NULL) {
			kandidat[pom - kandidat - 1] = '-';
			return 1;
		}
	}

	return 0;
}

int izbaci(struct Uposlenik* kandidati, int vel, int index)
{
	while(index < vel - 1) {
		*(kandidati + index) = *(kandidati + index + 1);
		index++;
	}
	vel--;
	return vel;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i = 0;
	int godine = pretvori_u_dane(direktor.datum_rodjenja);
	while(i<vel) {
		if(godine - pretvori_u_dane(kandidati[i].datum_rodjenja) > broj_dana) {
			if(poklapa(kandidati[i].ime_prezime,direktor.ime_prezime) != 1) {
				vel += izbaci(kandidati, vel, i);
				i--;
			}
		}
		i++;
	}

	return vel;
}

int main()
{
	int novi_broj;
	int i;
	struct Uposlenik direktor = {"Mujic-Fatic", {3, 3, 1992}};
	struct Uposlenik kandidati[7] = {
		{ "Meho Mehic", { 31, 1, 1990 } },
		{ "Pero Peric", { 1, 2, 1990 } },
		{ "Sara Sarac", { 2, 2, 1990 } },
		{ "Fata Mujic", { 1, 2, 1986 } },
		{ "Jozo Jozic", { 1, 10, 1990 } },
		{ "Mijo Mijic", { 4, 3, 1989 } },
		{ "Suljo Suljic", { 31, 12, 1991 } },
	};
	novi_broj = suzi_listu(kandidati, 7, direktor, 3);
	printf("Kandidati nakon suzenja liste: ");
	for(i = 0 ; i < novi_broj ; i++);
	printf("%s\n", kandidati[i].ime_prezime);

	return 0;
}
