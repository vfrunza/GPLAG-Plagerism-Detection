#include <stdio.h>


struct Datum {
	int dan, mjesec, godina;
};


struct Uposlenik {
	char ime_prezime [50];
	struct Datum datum_rodjenja;
};


void unesi (char niz[], int velicina) {
	char znak=getchar();
	int i=0;
	if (znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int ISTO (char* s1, char* s2) {			/* uporedjuje prezimena */
	while (*s1!=' ') s1++;
	while (*s2!=' ') s2++;
	while (*s1!='\0' && *s2!='\0') {
		if (*s1 == *s2) {
			s1++;
			s2++;
		}
		else return 0;
	}
	return 1;
}

int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	
	int i=0, j=0;

	
	for (i=0; i<vel; i++) {
		if (ISTO(direktor.ime_prezime, kandidati[i].ime_prezime)==0) {			/*sta poslati u funkciju*/
			for (j=i; j<vel-1; j++) {
				/* izbacivanje kandidata iz niza */
				*(kandidati+j) = *(kandidati+j+1);
			}
			vel--;
			i--;
		}
	}
	
	return (vel-1);			/* zato sto brojimo od 0 i ne ukljucujemo niz[vel] */			/* 3 6 7*/
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
