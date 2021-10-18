#include <stdio.h>

int provjeri_duzine(char *pok, int niz[], int vel){
	int duzina_trenutne = 0;
	int indeks_niza = 0;
	
	while(*pok != '\0'){
			if((*pok >='a' && *pok <='z') || (*pok >='A' && *pok <='Z')){
				duzina_trenutne++;
			} else {
				if(duzina_trenutne != 0){
					if(indeks_niza > vel) return 0;
					if(duzina_trenutne != niz[indeks_niza]) return 0;
					indeks_niza++;
				}
				duzina_trenutne = 0;
			
		}
		pok++;
	}
	
	if(duzina_trenutne != 0){
		if(indeks_niza > vel) return 0;
		if(duzina_trenutne != niz[indeks_niza]) return 0;
		indeks_niza++;
	}

	if(indeks_niza != vel)
		return 0; 
		else return 1;
	
}
int main() {
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	printf("%d", provjeri_duzine(tekst, niz, 5));
	return 0;
}
