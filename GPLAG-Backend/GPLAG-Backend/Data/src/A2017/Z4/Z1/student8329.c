#include <stdio.h>
#include <ctype.h>

int daj_duzinu(int broj);
char* ubaci_broj(char* tekst, int broj);
int napravi_mjesta(char* tekst, int pocetak, int duzina, int kraj_stringa);

int main() {
	char s[66] = "a sada i primjer koji se zavrsava razmacima       ";
	printf("\"%s\"", ubaci_broj(s, 1));
	
	return 0;
}

int daj_duzinu(int broj) {
	int duz = 0;
	
	if (broj < 0) {
		duz += 1;
		broj = -broj;
	}
	
	while (broj > 0) {
		duz += 1;
		broj /= 10;
	}
	
	return duz;
}

int napravi_mjesta(char* tekst, int pocetak, int duzina, int kraj_stringa) {
	int i;
	
	for (i = kraj_stringa + duzina; i > pocetak; i--)
		tekst[i] = tekst[i - duzina];
	
	for (i = pocetak; i < pocetak + duzina; i++)
		tekst[i] = '@';
	
	return kraj_stringa + duzina;
}

char* ubaci_broj(char* tekst, int broj) {
	int i, j;
	int duzina_broja, kraj_stringa, temp_broj;
	int poceo_tekst = 0;
	
	duzina_broja = daj_duzinu(broj);
	
	for (kraj_stringa = 0; tekst[kraj_stringa] != '\0'; kraj_stringa++);
	
	for (i = 0; tekst[i] != '\0'; i++) {
		if (isalnum(tekst[i]))
			poceo_tekst = 1;
			
		if (poceo_tekst && isspace(tekst[i])) {
			j = i + 1;
			
			while (isspace(tekst[j]))
				j += 1;
				
			if (j == kraj_stringa)
				break;
			
			if (isspace(tekst[i + 1]))
				kraj_stringa = napravi_mjesta(tekst, i + 1, duzina_broja, kraj_stringa);
			else
				kraj_stringa = napravi_mjesta(tekst, i + 1, duzina_broja + 1, kraj_stringa);
			
			i += duzina_broja + 1;
			
			while (!isalnum(tekst[i]))
				i += 1;
		}
	}
	
	for (i = 0; tekst[i] != '\0'; i++) {
		if (tekst[i] == '@') {
			if (broj < 0) {
				tekst[i] = '-';
				temp_broj = -broj;
			} else {
				temp_broj = broj;
			}
			
			tekst[i + duzina_broja] = ' ';
			
			for (j = i + duzina_broja - 1; temp_broj > 0; j--) {
				tekst[j] = '0' + (temp_broj % 10);
				temp_broj /= 10;
			}
		}
	}
	
	return tekst;
}