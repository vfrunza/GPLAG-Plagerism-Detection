#include <stdio.h>

/**
 char c => slovo koje ispitujemo
 return int => 1 ako je slovo, 0 ako nije
 */
int slovo(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); //vraca 1 ako je slovo
}

char * sljedeca_rijec(char * tekst, int * duzina) { 
	*duzina = 0;
	while (! slovo(*tekst) && *tekst != '\0') tekst++; //ako nije slovo tekst++
    while (*tekst != '\0' && slovo(*tekst)) { // ako je slovo 
    	tekst++;
    	*duzina += 1; 
    }
    return tekst; 
}

int broj_rijeci(char * tekst) {
	int n = 0;   //duzina rijeci
	int broj_rijeci = 0;
	tekst = sljedeca_rijec(tekst, &n);
	while (n > 0) {
		broj_rijeci++;
		tekst = sljedeca_rijec(tekst, &n); // pomjeram na sljedecu rijec
	}
	return broj_rijeci;
}


int provjeri_duzine(char * recenica, int niz[], int vel) {
	int duzina = 0, i = 0, ispravno;
	if (broj_rijeci(recenica) != vel) return 0; //ako je broj rijeci recenice razlicit od vel (u atu stoji da vraca 0 ako je ovo slucaj)

	/** @var int ispravno => sve dok se duzina odgovarajuce rijeci poklapa
	 * 		sa odgovarajucim elementom u nizu ova varijabla ima vrijednost 1
	 */
	ispravno = 0;  //   neka logicka varijabla  
	recenica = sljedeca_rijec(recenica, &duzina);   // recenica sad pokazuje na prvu rijec
	while (i < vel) {
		if (! (ispravno = (duzina == niz[i]))) break; //prekini onda kad duzina rijeci ne bude ista kao niz[i]
		recenica = sljedeca_rijec(recenica, &duzina); //pomjeram na sljedecu rijec
		i++;
	}
	return ispravno;
}

int main() {
	char recenica[100] = "  Ovo       je neki  primjer  teksta ";
	int niz[10] = {3, 2, 4, 7, 6};
	printf("%s\n", provjeri_duzine(recenica, niz, 5) ? "dobar" : "los");  
	return 0;                                                               
}                          

