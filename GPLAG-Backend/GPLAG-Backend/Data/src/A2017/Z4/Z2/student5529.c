#include <stdio.h>

int provjeri_duzine(char* s, int niz[], int velicina){
	int duzina = 0, broj_rijeci=0;
	
	/* preskacemo sve znakove koji nisu slova na pocetku recenice*/
			while (!((*s>='a' && *s<='z') || (*s>'A' && *s<='Z'))) {
					s++;
			}
	
	while(*s != '\0' && broj_rijeci <= velicina) {
		duzina = 0;
		broj_rijeci++;
		/* racunamo duzinu rijeci*/
		while((*s>='a' && *s<='z') || (*s>'A' && *s<='Z')){
	 		duzina++;
			s++;
		}
		/* preskacemo sve znakove koji nisu slovo*/
		while((!(*s>='a' && *s<='z') || (*s>'A' && *s<='Z')) && (*s != '\0')){
			s++;
		}
		/*poredimo duzinu rijeci sa brojem iz niza*/
		if (duzina != niz[broj_rijeci-1]) return 0;
	}
	/* provjeravamo je li velicina niza odgovara broju rijeci*/
	if (broj_rijeci != velicina) return 0;
	return 1;
}

int main(){
	/* primjer sa autotesta*/
	char tekst[] = "Napravicemo jos jedan primjer";
	int niz[] = {11, 3, 5, 7};
	
	printf("\n1.  z%d ", provjeri_duzine(tekst, niz, 0));
	printf("\n2.  z%d ", provjeri_duzine(tekst, niz, 3));
	printf("\n3.  z%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}