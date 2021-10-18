#include <stdio.h>
int duzinaTeksta(char* tekst) {
	int duzina = 0;
	while(*tekst != '\0') {
		duzina++;
		tekst++;
	}
	return duzina;
}
char* ubaci_broj (char* tekst, int broj){
	char sbroj[12];
	char* sb = sbroj;
	int tmp=broj;
	if (broj < 0) {
		broj = -broj;
		*sb++ = '-';
	}
	do {
		sb++;
		tmp /= 10;
	} while (tmp != 0);
	*sb-- = '\0';
	while (broj != 0) {
		*sb-- = broj % 10 + '0';
		broj /= 10;
	} 
	int duzina = duzinaTeksta(sbroj) + 1;
	char* s = tekst;
	while(*s == ' ') s++;
	while (*s != '\0') {
		char* kraj = s;
		while(*kraj == ' ') kraj++;
		if(*kraj != '\0') {
			if (*s == ' ') {
		    kraj = s;
			while (*kraj != '\0') kraj++;
			while (kraj > s) {
				*(kraj+duzina) = *kraj;
				kraj--;
			}
			*s = ' ';
			s++;
			char* p = sbroj;
			while (*p != '\0') *s++ = *p++;
			
		
				kraj = s;
				kraj++;
				if(*s == ' ' && *kraj == ' ') {
					char* pomocni = s;
					while(*kraj != '\0') *pomocni++ = *kraj++;
					*pomocni = '\0';
				}
				if(*s != ' ') *s = ' ';
	
			while(*s == ' ') s++;
		}
		}
		s++;
	}
	return tekst;
}

int main() {
	char niz[] = "amila  i adna.";
	printf("%s", ubaci_broj(niz,75));
	return 0;
}
