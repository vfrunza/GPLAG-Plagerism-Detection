#include <stdio.h>
/* 1. (0,5 bodova) Napisati funkciju sa prototipom:

char* izbaci_najcescu(char* s)

Funkcija treba iz primljenog stringa koji predstavlja neki tekst izbaciti riječ koja se u tekstu ponavlja najviše puta. 
Treba izbaciti sva ponavljanja te riječi u stringu. Riječ se definiše kao niz velikih i malih slova. 
Tako npr. tekst "auto-stop" posmatramo kao dvije riječi jer se u sredini nalazi znak minus koji nije slovo. 
Funkcija ne treba praviti razliku između velikih i malih slova (riječi "primjer", "PRIMJER" i "Primjer" se trebaju brojati kao 
tri ponavljanja iste riječi).

Funkcija treba vratiti pokazivač na početak primljenog stringa radi lakšeg lančanog pozivanja. 
Ukoliko se u tekstu nalazi više riječi koje se ponavljaju isti broj puta, funkcija treba izbaciti onu od najčešćih riječi 
koja je najbliža početku stringa. Prilikom izbacivanja riječi ne treba izbacivati okolne razmake i ostale znakove. 
Ukoliko primljeni string ne sadrži niti jednu riječ funkcija ne treba uraditi ništa.

Pri rješavanju zadatka nije dozvoljeno koristiti funkcije iz biblioteka string.h, stdlib.h kao ni funkcije sprintf i sscanf 
iz biblioteke stdio.h.*/

void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i = 0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* izbaci_najcescu(char* s) {
	char* reset=s, *p=s, *kraj_rijeci;
	
	int neslovo=1, broj_rijeci=0, i=0, j=0;
	
	char niz_rijeci[10][100];
	
	while (*s != '\0') {
		if  (*s < 'A' || (*s > 'Z' && *s < 'a') || *s > 'z')
		neslovo = 1;
		else if (neslovo == 1) {
			neslovo = 0;
			
			/*Pronasli smo rijec, ubacimo je u niz stringova*/
			
				kraj_rijeci=s;
				while ((*kraj_rijeci >='A' && *kraj_rijeci <= 'Z') || (*kraj_rijeci >= 'a' && *kraj_rijeci <= 'z') ) {
					kraj_rijeci++;
				}
				
				/* p klizeci pokazivac od pocetka do kraja rijeci*/
				
				p=s;
				i=0;
				while (p != kraj_rijeci) {
					niz_rijeci[broj_rijeci][i]=*p;
					p++;
					i++;
				}
				niz_rijeci[broj_rijeci][i]='\0';
				
				for (j=0; j<=i; j++) {
					printf ("%c", niz_rijeci[broj_rijeci][i]);
					
				}


		
			broj_rijeci++;
		}
		s++;
		
	}
	
	return reset ;
}

int main() {
	char s1[100];
	printf("Unesite tekst: ");
	unesi (s1, 100);
	printf ("%s", izbaci_najcescu(s1));
	return 0;
}
