#include <stdio.h>
#include <math.h>

char* ubaci_broj (char* tekst, int broj) {
	int duzina=0, a=broj, razmaci, dodatni=0, razmak=0, temp_duzina, n=0, temp_broj;
	char* pocetak=tekst, *kraj, *do_kraja;
	
	
	/* Ostavljamo mjesto za predznak negativnog broja: */
	if (broj<0) duzina++;
	do {
		a/=10;
		duzina++;
	} while (a!=0);
	
	while (*tekst!='\0') {
		if (*tekst!=' ') razmak=1;
		else if (*tekst==' ' && razmak==1) {
			
			razmaci=1;
			
			/* Provjeravamo da li se string završava razmakom: */
			do_kraja=tekst;
			while (*do_kraja!='\0') {
				if (*do_kraja!=' ') {
					razmaci=0;
					break;
				}
				do_kraja++;
			}
			if (razmaci==1) return pocetak;
			
			tekst++;
			kraj=tekst;
			razmak=0;
			dodatni=0;
			n=0;
			temp_duzina=duzina;
			temp_broj=broj;
			
			/* Ostavljamo mjesta ukoliko je potreban dodatni razmak: */
			if (*tekst!=' ') {
				temp_duzina++;
				dodatni=1;
			}
			while (*kraj!='\0') kraj++;
			while (kraj>=tekst) {
				*(kraj+temp_duzina)=*kraj;
				kraj--;
			}
			if (temp_broj<0) {
				*tekst++='-';
				temp_broj=-broj;
				temp_duzina--;
			}
			do {
				*(tekst-n+temp_duzina-dodatni-1)=(temp_broj%10)+48;
				n++;
				tekst++;
				temp_duzina--;
				temp_broj/=10;
			} while (temp_duzina-dodatni!=0);
			if (dodatni) *tekst=' '; 
		}
		tekst++;
	}
	return pocetak;
}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
