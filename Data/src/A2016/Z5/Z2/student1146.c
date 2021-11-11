#include <stdio.h>
#include <string.h>

#define je_slovo(c) (c != EOF && (('A' <= (c) && (c) <= 'Z') || ('a' <= (c) && (c) <= 'z')))

typedef struct {
	int freq;
	char rijec[10]; /* 9 slova + '\0' */
} Rijec;

void kompresuj(char *ime_ulaz, char *ime_izlaz) {
	FILE *ulaz, *izlaz;
	Rijec rijeci[1000], *tablica[10];
	int n = 0, n_tablica = 0;

	ulaz = fopen(ime_ulaz, "r");
	if (!ulaz) {
		printf("Greska pri otvaranju ulazne datoteke\n");
		return;
	}
	izlaz = fopen(ime_izlaz, "w");
	if (!izlaz) {
		printf("Greska pri otvaranju izlazne datoteke\n");
		return;
	}
	
	{
		int i, c, found;
		char buf[10];
		c = fgetc(ulaz);
		while (1) {
			while (!je_slovo(c) && c != EOF) c = fgetc(ulaz); /* idemo do prve rijeci */
			if (c == EOF) break;

			for (i = 0; i < 9 && je_slovo(c); i++) { /* pisemo rijec u buffer */
				buf[i] = c;
				c = fgetc(ulaz);
			}
			buf[i] = '\0';
			
			if (i == 1) continue; /* rijec je prekratka (1 slovo) */
			if (je_slovo(c)) { /* ima jos slova u rijeci (duza od 9) */
				while (je_slovo(c)) c = fgetc(ulaz);
				continue;
			}
			
			found = 0;
			for (i = 0; i < n; i++) { /* ako smo vec zapisali tu rijec */
				if (!strcmp(rijeci[i].rijec, buf)) {
					rijeci[i].freq++; /* povecavamo ucestalost */
					found = 1;
					break;
				}
			}
			if (!found) { /* ako je nismo nasli dodajemo novu */
				if (n == 1000) {
					printf("Greska: previse razlicitih rijeci\n");
					return;
				}
				rijeci[n].freq = 0;
				strcpy(rijeci[n++].rijec, buf);
			}
		}
	}
	
	{
		int i, j, mjesto;
		for (i = 0; i < n; i++) {
			mjesto = 0;
			/* trazimo mjesto rijeci u top listi */
			for (j = 0; j < n_tablica; j++) {
				if (rijeci[i].freq < tablica[j]->freq) {
					mjesto++;
					continue;
				}
				if (rijeci[i].freq == tablica[j]->freq &&
					  strcmp(rijeci[i].rijec, tablica[j]->rijec) > 0) 
					mjesto++;
			}
			if (mjesto == 10 && n_tablica == 10) continue; /* tablica je puna */

			if (n_tablica < 10) n_tablica++;
			
			for (j = n_tablica - 1; j > mjesto; j--) /* guramo sve elemente ispod novog prema dole */
				tablica[j] = tablica[j - 1];
			tablica[mjesto] = &rijeci[i];
		}
	}
	
	rewind(ulaz);
	{
		int i, c, found;
		char buf[10];
		for (i = 0; i < n_tablica; i++) 
			fprintf(izlaz, "%s\n", tablica[i]->rijec);
		if (n_tablica < 10) fputc('\n', izlaz);
		
		c = fgetc(ulaz);
		while (1) {
			while (!je_slovo(c) && c != EOF) { /* ispisujemo sve znakove koje nisu rijeci */
				fputc(c, izlaz);
				c = fgetc(ulaz);
			}
			if (c == EOF) break;
			
			for (i = 0; i < 9 && je_slovo(c); i++) { /* pisemo rijec u buffer */
				buf[i] = c;
				c = fgetc(ulaz);
			}
			buf[i] = '\0';

			if (i == 1) { /* rijec je prekratka - idemo dalje */
				fputc(buf[0], izlaz);
				continue;
			}
			if (je_slovo(c)) { /* rijec duza od 9, ispisujemo je u file */
				fprintf(izlaz, "%s", buf);
				while (je_slovo(c)) {
					fputc(c, izlaz);
					c = fgetc(ulaz);
				}
				continue;
			}
			found = 0;
			for (i = 0; i < n_tablica; i++) { /* trazimo rijec u tablici i ispisujemo znak */
				if (!strcmp(tablica[i]->rijec, buf)) {
					found = 1;
					fputc(20 + i, izlaz);
					break;
				}
			}
			if (!found) 
				fprintf(izlaz, "%s", buf);
		}
	}
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");
}

int unesi_rijec_tablica(FILE *src, char buf[10]) {
	int i = 0, c;
	c = fgetc(src);
	for (i = 0; i < 9 && c != '\n'; i++) {
		buf[i] = c;
		c = fgetc(src);
		if (c == EOF) return 0; /* fajl sadrzi samo tablicu */
	}
	if (c != '\n') return -1; /* nismo dosli do kraja reda */
	buf[i] = '\0';
	return i;
}

void dekompresuj(char *ime_ulaz, char *ime_izlaz) {
	FILE *ulaz, *izlaz;
	char tablica[10][10];
	int i, c, duz;
	ulaz = fopen(ime_ulaz, "r");
	if (!ulaz) {
		printf("Greska pri otvaranju ulazne datoteke\n");
		return;
	}
	izlaz = fopen(ime_izlaz, "w");
	if (!izlaz) {
		printf("Greska pri otvaranju izlazne datoteke\n");
		return;
	}
	
	for (i = 0; i < 10; i++) { /* unos tablice rijec po rijec */
		duz = unesi_rijec_tablica(ulaz, tablica[i]);
		if (duz == 0) break;
		if (duz == -1) {
			printf("Greska: preduga rijec u tablici\n");
			return;
		}	
	}
	/* i je sada broj uspjesno unesenih rijeci */
	
	while ( (c = fgetc(ulaz)) > 0) { /* ispisujemo dekompresovani file znak po znak */
		if (c >= 20 && c <= 29) { /* znak predstavlja rijec iz tablice */
			c -= 20;
			if (c < i) fprintf(izlaz, "%s", tablica[c]);
			else printf("Nije unesena rijec %d\n", c);
		} else fputc(c, izlaz);
	}
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
}

void unesi(char buf[], int n) { /* unos sa stdin */
	int i;
	char c;
	c = getchar();
	while (c == '\n') c = getchar();
	for (i = 0; i < n - 1 && c != '\n'; i++) {
		buf[i] = c;
		c = getchar();
	}
	buf[i] = '\0';
}

int main() {
	int izbor;
	char ulaz[100], izlaz[100];
	while (1) {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &izbor);
		if (!izbor) break;
		if (izbor == 1 || izbor == 2) {
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulaz, 100);
			printf("Unesite ime izlazne datoteke: ");	
			unesi(izlaz, 100);
			if (izbor == 1) kompresuj(ulaz, izlaz);
			if (izbor == 2) dekompresuj(ulaz, izlaz);
			continue;
		}
		printf("Greska: pogresan izbor\n");
		return 0;
	}
	return 0;
}
