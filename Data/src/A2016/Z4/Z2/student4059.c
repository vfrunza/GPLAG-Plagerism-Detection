#include <stdio.h>

char *kodiraj(char *tekst, char *tabela) {
	char *pocetak = tekst, *pocetakTabele = tabela;
	int ponavljanja[126 - 32 + 1] = {0}; /*94*/
	int prethodni = -1, trenutni = -1, i;
	
	while(*tekst != '\0') {
		ponavljanja[(int)*tekst - 32]++;
		tekst++;
	}
	tekst = pocetak;
	
	/* generisanje tabele */
	while(trenutni != 0) {
		for(i = 0; i < 126 - 32 + 1; i++) {
			if((ponavljanja[i] > trenutni && ponavljanja[i] < prethodni) || (ponavljanja[i] > trenutni && prethodni == -1) || trenutni == -1)
				trenutni = ponavljanja[i];
		}
		for(i = 0; i < 126 - 32 + 1; i++) {
			if(ponavljanja[i] == trenutni) {
				*tabela = (char)i+32;
				tabela++;
			}
		}
		prethodni = trenutni;
		if(trenutni == 0)
			break;
		trenutni = -2;
	}
	*tabela = '\0';
	
	/* kodiranje */
	while(*tekst != '\0') {
		tabela = pocetakTabele;
		for(i = 0; i < 126 - 32 + 1; i++) {
			if(tabela[i] == *tekst) {
				*tekst = (char)126 - i;
				break;
			}
		}
		tekst++;
	}
	
	return pocetak;
}

char *dekodiraj(char *tekst, char *tabela) {
	char *pocetak = tekst, *pocetakTabele = tabela;
	int i;
	
	/* dekodiranje */
	while(*tekst != '\0') {
		for(i = 0; i < 126 - 32 + 1; i++) {
			if(*tekst == (char)126 - i) {
				*tekst = tabela[i];
				break;
			}
		}
		tekst++;
	}
	
	return pocetak;
}

int main() {
	char tekst[] = "Ovo je neki testni tekst";
	char sifrarnik[100] = "";
	int i;
	kodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(tekst, sifrarnik);
	printf("%s", tekst);

	return 0;
}
