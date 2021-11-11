#include <stdio.h>

int max_element(int *niz){
	int i = 1, max = niz[0], index = 0;
	for(; i < 95; ++i)
		if(niz[i] > max){
			max = niz[i];
			index = i;
		}
	return index;
}

int vrati_poziciju(char *kodiranje, char znak){
	int i = 0;
	for(; kodiranje[i] != '\0'; ++i)
		if(kodiranje[i] == znak)
			return i;
	return -1;
}


char *kodiraj(char *tekst, char *kodiranje){
	int niz[95] = {0}, i = 0;
	for(; tekst[i] != '\0'; ++i)
		++niz[tekst[i] - 32];
	for(i = 0; ; ++i){
		int pozicija = max_element(niz);
		if(niz[pozicija] == 0)
			break;
		kodiranje[i] = pozicija + 32;
		niz[pozicija] = -1;
	}
	int j = 0;
	for(; j < 95; ++j)
		if(niz[j] == 0)
			kodiranje[i++] = j + 32;
	kodiranje[i] = '\0';
	for(j = 0; tekst[j] != 0; ++j)
		tekst[j] = 126 - vrati_poziciju(kodiranje, tekst[j]);
	return tekst;
}

char *dekodiraj(char *kod, char *kodiranje){
	int j = 0;
	for(; kod[j] != '\0'; ++j)
		kod[j] = kodiranje[126 - kod[j]];
	return kod;
}

int main() {
	char tekst[] = "Ovo je neki testni tekst";
	char sifrarnik[100] = "";
	printf("%s\n", kodiraj(tekst, sifrarnik));
	printf("%s", dekodiraj(tekst, sifrarnik));
	return 0;
}
