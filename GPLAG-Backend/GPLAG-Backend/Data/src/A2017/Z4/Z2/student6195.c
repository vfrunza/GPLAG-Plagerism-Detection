#include <stdio.h>
int provjeri_duzine(char *s, int niz[], int vel)
{

	int razmak=1;
	int duzina = 0;
	int brojac_rijeci = 0;
	while(*s != '\0') {
		/* brojanje rijeci u stringu, petlja sa predavanja..*/
		if(*s < 'A' || *s > 'Z' && *s < 'a' || *s>'z') {
			razmak=1;
			s++;
		} else if(razmak==1) {
			duzina=0;
			razmak=0;
			brojac_rijeci++;
			/* koliko slova ima rijec */
			while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s<='z')) {
				duzina++;
				s++;
			}
			/* ako je broj slova u nekoj rijeci, razlicit od broja iz niza zavrsi, izbacivanje nije uspjesno */
			if(duzina != niz[brojac_rijeci-1])
				return 0;
		} else
			/* ako je duzina rijeci jednaka  broju iz niza, idemo dalje, sve radi, ako nigdje ne returna 0, izbacivanje uspjesno, return 1 */
			s++;
	}
	/* ako je velicina niza razlicita od broja rijeci, nemoj ih ni porediti */
	if (vel != brojac_rijeci) return 0;

	return 1;
}
int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
