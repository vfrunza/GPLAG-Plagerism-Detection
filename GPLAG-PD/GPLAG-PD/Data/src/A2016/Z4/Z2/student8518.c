#include <stdio.h>

int uslov(int* niz)
{
	int i;
	for (i = 0; i < 96; i++)
		if (niz[i] != -1) return 1;
	return 0;
}

char* kodiraj(char* tekst, char* niz)
{
	char* pocetak = tekst;
	char* tmp1 = niz;
	char* tmp2 = niz;
	int brojPonavljanja[96] = {0};
	char staPonavlja[96];
	char slovo = ' ';
	int i = 0, max, indeksMax = 0;
	while (slovo != 127) {
		tekst = pocetak;
		staPonavlja[i] = slovo;
		while (*tekst != '\0') {
			if (*tekst == slovo)
				brojPonavljanja[i]++;
			tekst++;
		}
		i++;
		slovo++;
	}
	while (uslov(brojPonavljanja)) {
		max = brojPonavljanja[0];
		indeksMax = 0;
		for (i = 0; i < 96; i++) {
			if (brojPonavljanja[i] > max) {
				max = brojPonavljanja[i];
				indeksMax = i;
			}
		}
		*niz++ = staPonavlja[indeksMax];
		brojPonavljanja[indeksMax] = -1;
	}
	*--niz = '\0';
	niz--;
	tekst = pocetak;
	while (*tekst != '\0') {
		for (i = 0; i < 96; i++) {
			if (*tekst == *tmp2) {
				*tekst = 126 - i;
				break;
			}
			tmp2++;
		}
		tmp2 = tmp1;
		tekst++;
	}
	return pocetak;
}

char* dekodiraj(char* tekst, char* niz)
{
	char* pocetak = tekst;
	char* tmp2 = niz;
	int i;
	while (*tekst != '\0') {
		for (i = 0; i < 96; i++) {
			if (*tekst == *tmp2) {
				*tekst = *(niz + 94 - i);
				break;
			}
			tmp2++;
		}
		tmp2 = niz;
		tekst++;
	}
	return pocetak;
}

int main()
{
	char tekst[100] = "LLMLNLNMONM";
	char niz[100];
	printf("%s\n", kodiraj(tekst, niz));
	printf("%s", dekodiraj(tekst, niz));
	return 0;
}
