#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int n){
	int razmak = 1; /*Logička varijabla*/
	int brojac = 0; /*Broji koliko je puta došlo do poređenja između broja slova i elementa niza*/
	while(*s != '\0'){
		if(!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))){ /*Ovo treba da pojede sve što nije slov*/
			razmak = 1;
			s++;
		}else if(razmak){
			int broj_slova = 0;
			while((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')){/*Broji koliko ima slova*/
				s++;
				broj_slova++;
			}
			if(broj_slova == *niz){/*Upoređuje da li je broj slova jednak elementu nizaa*/
				if(brojac < n){
					niz++;
				}
			}else{
				return 0;
			}
			razmak  = 0;
			brojac++;
		}
	}
	if(brojac != n){/*Ako nije isti broj elemenata niza i riječi onda nema šanse da tvrdnja bude tačna, pa tako možemo isljučivati*/
		return 0;
	}else{
		return 1;
	}
}

int main() {
	/*Kod je napisan u 03:18, imajte malo milosti*/
	return 0;
}
