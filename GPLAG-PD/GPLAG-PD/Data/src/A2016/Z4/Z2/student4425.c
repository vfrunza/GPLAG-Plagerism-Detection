#include <stdio.h>
#define N 96
#define text_len 500
#define konstanta_sifrovanja 126

void unesi (char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

void make_default_table (char* tablica) {
	int i;
	for (i = 32; i <= 126; i++) { // ' ' to '~'
		*tablica = i;
		tablica++;
	}
	*tablica = '\0';
}

char* kodiraj (char* tekst, char* tablica) {
	char* vrati = tekst;
	
	make_default_table(tablica);
	int brojaci[N] = {0}; int i, indeks, var, j, flag;
	char tmp, tmp2;

	while (*tekst != '\0') {
		for (i = 0; i < N; i++) {
			if (*tekst == tablica[i]) {
				brojaci[i]++;
				break;
			}
		}
		tekst++;
	} //brojaci OK
	
	for (i = 0; i < N-1; i++) {
		var = i;
		for (j = i+1; j < N-1; j++) {
			if (brojaci[j] > brojaci[var]) var = j;
			else if (brojaci[j] == brojaci[var]) {
				if (tablica[j] < tablica[var]) var = j;
			}
		}
		
		tmp = tablica[i];
		tablica[i] = tablica[var];
		tablica[var] = tmp;

		tmp2 = brojaci[i];
		brojaci[i] = brojaci[var];
		brojaci[var] = tmp2;
	}
	
	tekst = vrati;
	while (*tekst != '\0') {
		for (i = 0; i < N; i++) {
			if (*tekst == tablica[i]) {
				*tekst = (char)(konstanta_sifrovanja - i); //126-i
				break;
			}
		}
		tekst++;
	}
	
	return vrati;
}

char* dekodiraj (char* tekst, char* tablica) {
	char* vrati = tekst;
	
	char tablica2[N];
	char* pkk = tablica2;
	int i;
	
	tablica2[N] = '\0';
	for (i = konstanta_sifrovanja; i >= konstanta_sifrovanja-N+2; i--) {
		*pkk = i;
		pkk++;
	}
	
	while (*tekst != '\0') {
		for (i = 0; i < N; i++) {
			if (*tekst == tablica2[i]) {
				*tekst = tablica[i];
				break;
			}
		}
		tekst++;
	}

	return vrati;
}

int main() {
	
	char tablica[N], tekst[text_len];
	unesi(tekst, text_len);
	kodiraj(tekst, tablica);
	dekodiraj(tekst, tablica);
	
	return 0;
}