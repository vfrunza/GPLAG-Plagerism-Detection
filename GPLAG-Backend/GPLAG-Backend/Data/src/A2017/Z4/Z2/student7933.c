#include <stdio.h>

int provjeri_duzine(char *s, int *brojevi, int vel){
	int wordCnt = 0;
	int duzina = 0;
	
	while(*s != '\0'){
		/*Ako je slovo*/
		if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
			//Prodji kroz rijec i odredi duzinu rijeci
			duzina = 0;
			while( ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0'){
				duzina++;
				s++;
			}
			/*Povecaj broj rijeci za 1*/
			wordCnt++;
			/*Ako ima vise rijeci nego duzina u nizu ili ako duzina
			ne odgovara odgovarajucoj rijeci, prekini program*/
			if(wordCnt > vel || brojevi[wordCnt-1] != duzina) return 0;
		}
		
		if(*s == '\0') break;
		
		s++;
	}
	
	/*Ako ima visak elemenata*/
	if(vel > wordCnt) return 0;
	
	return 1;
}

int main() {
	
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	
	printf("%d", provjeri_duzine(tekst, niz, 5));
	
	return 0;
}