#include <stdio.h>

#define broj_elem ('~' - ' ' + 1)

char *kodiraj(char *tekst, char *sifra) {
	int i, j, k, max, temp, frekvencija[broj_elem] = {0};
	char *p, tempc;
	
	for (i = 0; i < broj_elem; i++) sifra[i] = i + ' ';
	sifra[broj_elem] = '\0';
	
	for (p = tekst; *p; p++) 
		frekvencija[*p - ' ']++; /* brojanje ucestalosti slova */
	
	for (i = 0; i < broj_elem; i++) {
		max = i;
		for (j = i + 1; j < broj_elem; j++) 
			if (frekvencija[j] > frekvencija[max]) max = j;
			
		if (i != max) { /* stabilna varijanta selection sorta */
			temp = frekvencija[max];
			tempc = sifra[max];
			for (k = max - 1; k >= i; k--) { /* umjesto da zamijenimo elemente gurnemo ih sve nalijevo */
				frekvencija[k + 1] = frekvencija[k];
				sifra[k + 1] = sifra[k];
			}
			frekvencija[i] = temp;
			sifra[i] = tempc;
		}
	}
		
	for (p = tekst; *p; p++) /* sifriranje po postavci */
		for (i = 0; sifra[i]; i++)
			if (sifra[i] == *p) {
				*p = '~' - i;
				break;
			}
	
	return tekst;	
}

char *dekodiraj(char *tekst, char *sifra) {
	char *p;
	
	for (p = tekst; *p; p++) /* desifriranje po postavci */
		*p = sifra['~' - *p];
	
	return tekst;
}

int main() {
	char sifra[96], tekst[] = "LLMLNLNMONM";
	
	kodiraj(tekst, sifra);
	printf("Kodirani string: %s\nSifra: %s\n", tekst, sifra);
	
	dekodiraj(tekst, sifra);
	printf("Dekodirani string: %s\n", tekst);

	return 0;
}
