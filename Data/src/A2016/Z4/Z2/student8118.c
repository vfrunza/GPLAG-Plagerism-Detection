#include <stdio.h>
char* kodiraj (char* unos, char* sifra) {
	int niz[180], br=0, i, max=0, j, brojac=0;
	char* reset1, *reset2;
	reset1=unos;
	reset2=sifra;
	for (i=0; i<127; i++) {
		niz[i]=0;
	}
	while (*unos!='\0') {
		br=*unos;
		niz[br]++;
		unos++;
	}
	/*Odredjujemo koji clan niza se ponavlja najvise puta*/
	for (i=32; i<127; i++) {
		if (niz[i]>max)
			max=niz[i];
	}
	/*U sifrarnik se upisuju znakovi, redom, od znaka koji se ponavlja najveci broj puta, pa do onih koji se ne pojavljuju*/
	for (j=32; j<127; j++) {
		for (i=32; i<127; i++) {
			if (niz[i]==max) {
				*sifra=i;
				sifra++;
			}
		}
		max=max-1;
		if (max<0) break;
	}
	unos=reset1;
	sifra=reset2;
	while (*unos!='\0') {
/*Kodiramo tekst*/
		while (*sifra!='\0') {
			if (*unos==*sifra) {
				*unos=126-brojac;
				break; 
			}
			brojac++;
			sifra++;
		}
		unos++;
		brojac=0;
		sifra=reset2;
	   }
	unos=reset1;
	return unos;
}
/*Na osnovu sifrovanog stringa i tablice sifrovanja vrsimo dekodiranje*/	
char* dekodiraj (char* unos ,char* sifra) {
	char *reset3; 
	int brojac=0;
	reset3=unos;
	while (*unos!='\0') {
		brojac=0;
		while (*unos!=126-brojac) {
			brojac++;
		}
		*unos=*(sifra+brojac);
		unos++;
	}
    unos=reset3;
	return unos;
} 

int main() {

	return 0;
}
