#include <stdio.h>

int duzina_stringa (char* tekst) {
	int rezultat = 0;
	while(*tekst != '\0') {
		rezultat++;
		tekst++;
	}
	return rezultat;
}
char* napravi_razmak (char* broj) {
	char* kraj = broj;
	char* pomocni;
	char* pomocni2 = broj;
	char* pocetak = broj;
	while (*kraj != '\0') kraj++;
	kraj++;
	pomocni = kraj - 1;
	while (pomocni >= pocetak) {
		*kraj = *pomocni;
		pomocni--;
		kraj--;
	}
	*kraj = ' ';
	pomocni++;
while(1) {
		if(*pomocni2 == '\0') {
			*pomocni2 = ' ';
			pomocni2++;
			*pomocni2 = '\0';
			break;
		}
		pomocni2++;
	}
	return pocetak;
}
char* int_u_string (int broj, char* sbroj) {
	char* sb = sbroj;
	int tmp = broj;
	char* pocetak = sbroj;
	/* predznak */
	if (broj < 0) {
		broj = -broj;
		*sb++ = '-';
	}
	/* preborajavamo cifre */
	do {
		sb++;
		tmp /= 10;
	} while (tmp != 0);
	*sb-- = '\0';
	do {
		*sb-- = broj % 10 + '0';
		broj /= 10;
	} while (broj != 0);
	char* kraj = sbroj;
	int duzina = duzina_stringa(sbroj);
	while (*kraj != '\0') kraj++;
	while (kraj > sbroj) {
		*(kraj + duzina) = *kraj;
		kraj--;
	}
	return pocetak;
}
char* ubaci_broj (char* tekst, int broj) {
	
	char sbroj1[20];
	int_u_string(broj, sbroj1);
	char* sbroj = napravi_razmak(sbroj1);
	char* pocetak = tekst;
	int duzina = duzina_stringa(sbroj) - 1;
	while (*tekst != '\0') {
		if (tekst != pocetak && *(tekst-1) != ' ' && *tekst == ' ' && *(tekst+1) != ' ') {
			char* kraj = tekst;
			while (*kraj != '\0') kraj++;
			while (kraj > tekst) {
				*(kraj+duzina) = *kraj;
				kraj--;
			}
			char* p = sbroj;
			while (*p != '\0') {
				*tekst = *p;
				tekst++;
				p++;
			}
		}
		tekst++;
	}
	return pocetak;
}
int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
