#include <stdio.h>
#include <string.h>

int iste_rijeci (char* r1, char* r2) {
	while (*r1 != 0 && *r2 != 0) {
		if (*r1 != *r2) {
			return 0;
		}
		r1++;
		r2++;
	}
	if (*r1 == 0 && *r2 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int ima_li_istih(char* r, char (*rijeci)[19], int brojRijeci) {
	int i;
	for (i = 0; i < brojRijeci; i++) {
		if (iste_rijeci(r+8, rijeci[i]+8)) {
			return i;
		}
	}
	return -1;
}

int slovo (char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int broj (char c) {
	return (c >= '0' && c <= '9');
}


void zamijeni(char* r1, char* r2) {
	char x;
	int i;
	for (i = 0; i < 19; i++) {
		x = r1[i];
		r1[i] = r2[i];
		r2[i] = x;
	}
}

int min (int x, int y) {
	if (x < y) {
		return x;
	} else {
		return y;
	}
}

int poredi (char* r1, char* r2) {
	while (*r1 != 0 && *r2 != 0) {
		if (broj(*r1) && broj((*r2))) {
			if (*r1 < *r2) {
				return -1;
			} else if (*r1 > *r2){
				return 1;
			}
		} else {
			if (*r1 > *r2) {
				return -1;
			} else if (*r1 < *r2){
				return 1;
			}
		}
		r1++;
		r2++;
	}
	
	if (*r1 == 0 && *r2 == 0) {
		return 0;
	} else if (*r1 == 0) {
		return -1;
	} else {
		return 1;
	}
}

void kompresuj (char *ime_ulaz, char *ime_izlaz) {
	FILE *ulaz = fopen(ime_ulaz, "r");
	FILE *izlaz = fopen(ime_izlaz, "w");
	char x, rijeci[1001][19], pom[20000] = {0};
	int brojRijeci = 0, brojSlova = 0, i, j, iste[1001] = {0}, n, m, f = 10000000;
	
	if (ulaz == NULL || izlaz == NULL) {
		return;
	} 
	
	do {
		brojSlova = 0;
		x = fgetc(ulaz);
		while (x != EOF && slovo(x) == 0) { /* pojedem znakove izmedju rijeci */
			x = fgetc(ulaz);
		}
		
		while (x != EOF && slovo(x) == 1) {
			rijeci[brojRijeci][brojSlova+8] = x;
			brojSlova++;
			x = fgetc(ulaz);
		}
		rijeci[brojRijeci][brojSlova+8] = 0;
		
		if (brojSlova > 1 && brojSlova < 10) {
			n = ima_li_istih(rijeci[brojRijeci], rijeci, brojRijeci);
			if (n != -1) { 
				iste[n]++;
			} else {
				iste[brojRijeci]++;
				brojRijeci++;
			}
		}
	} while (x != EOF);
	
	for (i = 0; i < brojRijeci; i++) {
		f = 10000000;
		n = iste[i];
		for (j = 0; j < 8; j++) {
			rijeci[i][j] = n/f+48;
			n -= n/f * f;
			f /= 10;
		}
	}
	
	for (i = 1; i < brojRijeci; i++) {
		for (j = 0; j < brojRijeci-1; j++) {
			if (poredi(rijeci[j], rijeci[j+1]) < 0) {
				zamijeni(pom, rijeci[j]);
				zamijeni(rijeci[j], rijeci[j+1]);
				zamijeni(rijeci[j+1], pom);
			}
		}
	}
	
	fclose(ulaz);
	ulaz = fopen(ime_ulaz, "r");
	
	for (i = 0; i < 10 && i < brojRijeci; i++) {
		fprintf(izlaz, "%s\n", rijeci[i]+8);
	}
	fprintf(izlaz, "\n");
	
	do {
		x = fgetc(ulaz);
		while (x != EOF && slovo(x) == 0) {
			fprintf(izlaz, "%c", x);
			x = fgetc(ulaz);
		}
		n = 0;
		while (x != EOF && slovo(x) == 1) {
			pom[n+8] = x;
			n++;
			x = fgetc(ulaz);
		}
		pom[n+8] = 0;
		
		m = ima_li_istih(pom, rijeci, min(brojRijeci, 10));
		
		if (m != -1) {
			fprintf(izlaz, "%c", m + 20);
		} else {
			for (i = 0; i < n; i++) {
				fprintf(izlaz, "%c", pom[i+8]);
			}
		}
		if (x != EOF) {
			fprintf(izlaz, "%c", x);
		}
	} while (x != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");
	return;
}

void dekompresuj (char *ime_ulaz, char *ime_izlaz) {
	char rijeci[10][10], x, y, *r;
	
	FILE *ulaz = fopen(ime_ulaz, "r");
	FILE *izlaz = fopen(ime_izlaz, "w");
	int brojRijeci = 0, n = 0;
	
	if (ulaz == NULL || izlaz == NULL) {
		return;
	}
	
	do { /* petlja za rijeci, pravi break ako nadje \n jedan do drugog */
		if (n != 1)
			n = 0;
		x = fgetc(ulaz);
		while (x != EOF && x != '\n') {
			rijeci[brojRijeci][n++] = x;
			x = fgetc(ulaz);
		}
		rijeci[brojRijeci][n] = 0;
		brojRijeci++;
		y = fgetc(ulaz);
		if (y == '\n') {
			brojRijeci--;
			break;
		}
		rijeci[brojRijeci][0] = y;
		n = 1;
	} while (1);
	
	do {
		x = fgetc(ulaz);
		if (x >= 20 && x <= 29) {
			r = rijeci[x-20];
			while (*r != 0) {
				fprintf(izlaz, "%c", *r);
				r++;
			}
		} else if (x != EOF) {
			fprintf(izlaz, "%c", x);
		}
		
	} while (x != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
	
	return;
}

int main() {
	
	int izbor;
	char ulazna[100], izlazna[100];
	
	do {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &izbor);
		if (izbor == 0) {
			break;
		}
		printf("Unesite ime ulazne datoteke: ");
		scanf("%s", &ulazna);
		printf("Unesite ime izlazne datoteke: ");
		scanf("%s", &izlazna);
		if (izbor == 1) {
			kompresuj(ulazna, izlazna);
		}
		else if(izbor == 2) {
			dekompresuj(ulazna, izlazna);
		}
	} while (izbor != 0);
	
	//kompresuj("ulaz.txt", "izlaz.txt");
	//dekompresuj("izlaz.txt", "ulaz.txt");
	return 0;
}
