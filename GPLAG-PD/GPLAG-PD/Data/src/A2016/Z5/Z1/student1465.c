#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Student 
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*Funkcija koja računa prosjek datog studenta*/
double prosjek(struct Student student) {
	double suma = 0;
	int i;
	if(student.br_ocjena == 0) return 5;
	for(i = 0; i < student.br_ocjena; i++) {
		suma += student.ocjene[i];
		if(student.ocjene[i] == 5) return 5;
	}
	return suma / student.br_ocjena;
}
/*Funckija koja izbacuje element*/
void izbaci(struct Student* niz, int brElem, int indeks)
{
	int i;
	for(i = indeks; i < brElem - 1; i++)
		niz[i] = niz[i + 1];
}

/*Funckija koja prima dva realna broja i poredi da li su isti*/
int istiReal(double a, double b)
{
	return fabs(a - b) < 0.0001;
}

/*Funkcija koja prima dva stringa, vraca nulu ako su identicni, 1 ako je a leksigrafski ispred b, -1 ako je b ispred a*/
int mojStrcmp(char* a, char* b)
{
	while( *a != '\0')
	{
		if(*b == '\0') return 1;
		if(*b > *a) return -1;
		if(*a < *b) return 1;
		a++;
		b++;
	}
		if(*b != '\0') return -1;
		return 0;
}

/*Funckija koja prima dva studenta, vrati jedan ako je a ispred b, u protivnom nulu*/
int leksigrafsko_poredjenje(struct Student a, struct Student b)
{
	int poImenu = mojStrcmp(a.ime, b.ime);
	int poPorezimenu = mojStrcmp(a.ime, b.ime);
	if(poImenu != 0) return poImenu;
	return poPorezimenu;
}
int genijalci(struct Student* niz, int brElem, double granicniProsjek)
{
	int i;
	int prvi, drugi, treci;
	for(i = 0; i < brElem; i++) {
		if(prosjek(niz[i]) < granicniProsjek) {
			izbaci(niz, brElem, i);
			brElem--;
			i--;
		}
	}
	if(brElem != 0) {
		prvi = 0;
		for(i = 0; i < brElem; ++i) {
			if(!istiReal(prosjek(niz[prvi]), prosjek(niz[i])) && prosjek(niz[prvi]) < prosjek(niz[i])) {
				prvi = i;
		}
		if(istiReal(prosjek(niz[prvi]), prosjek(niz[i]))) {
			if(leksigrafsko_poredjenje(niz[prvi], niz[i]) == 0) {
				prvi = i;
			}
		}
	}
	printf("%s %s\n", niz[prvi].prezime, niz[prvi].ime);
	if(brElem != 1) {
		drugi = 0;
		if(prvi == drugi) {
			drugi++;
		}
		for(i = 0; i < brElem; ++i) {
			if(i == prvi) continue;
			if(!istiReal(prosjek(niz[drugi]), prosjek(niz[i])) && prosjek(niz[drugi]) < prosjek(niz[i])) {
				drugi = i;
			}
			if(istiReal(prosjek(niz[drugi]), prosjek(niz[i]))) {
				if(leksigrafsko_poredjenje(niz[drugi], niz[i]) == 0) {
					drugi = i;
				}
			}
		}
	printf("%s %s\n", niz[drugi].prezime, niz[drugi].ime);
	if(brElem != 2) {
		treci = 0;
		while(treci == prvi || treci == drugi) treci++;
		for(i = 0; i < brElem; ++i) {
			if(i == drugi || i == prvi) continue;
			if(!istiReal(prosjek(niz[treci]), prosjek(niz[i])) && prosjek(niz[treci]) < prosjek(niz[i])) {
				treci = i;
			}
			if(istiReal(prosjek(niz[treci]), prosjek(niz[i]))) {
				if(leksigrafsko_poredjenje(niz[treci], niz[i]) == 0) {
					treci = i;
				}
			}
		}
		printf("%s %s\n", niz[treci].prezime, niz[treci].ime);
		}
	}
}

return brElem;

}
int main() {

	return 0;
}
