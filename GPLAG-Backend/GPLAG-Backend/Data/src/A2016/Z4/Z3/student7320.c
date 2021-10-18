#include <stdio.h>

int duzina_stringa(char *s) {
	int ret = 0;
	while (*s != '\0') {
		ret++;
		s++;
	}
	return ret;
}
char veliko(char c) {
	if (c >= 'A' && c <= 'Z') return c;
	else return c - 'a' + 'A';
}
int slovo(char c) {
	c = veliko(c);
	return (c >= 'A' && c <= 'Z');
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	int i, j;
	//*(tekst + duzina_stringa(tekst)) = ' ';
	*(tekst + duzina_stringa(tekst) + 1) = '\0';
	char *s = tekst;
	
	
	for (i = 0; i < broj_rijeci; i++) {
		char *text = s; // prolaz kroz string
		int length = 0;
		char *word = rijeci[i];
		while (*text != '\0') {
			if (*text != ' ') length++;
			else {
				if (length == duzina_stringa(word)) {
					text -= length;
					int jesu_iste = 1;
					for (j = 0; j < length; j++)
						if (text[j] != word[j]) {
							jesu_iste = 0;
							break;
						}
					if (jesu_iste) {
						char *exchange = zamjene[i];
						if (duzina_stringa(word) == duzina_stringa(exchange)) {
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
						}
						else if (duzina_stringa(word) < duzina_stringa(exchange)) {
							int add = duzina_stringa(exchange) - duzina_stringa(word);
							int for_loop = duzina_stringa(text);
							char *remember = text;
							while (*text != '\0') text++;
							text--;
							while (--for_loop) {
								*(text + add) = *text;
								text--;
							}
							text = remember;
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
						}
						else if (duzina_stringa(word) > duzina_stringa(exchange)) {
							int add = duzina_stringa(word) - duzina_stringa(exchange);
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
							char *remember = text;
							while (*text != '\0') {
								*text = *(text + add);
								text++;
							}
							text = remember;
						}
					}
				}
				length = 0;
			}
			text++;
		}
		
		if (length == duzina_stringa(word)) {
					text -= length;
					int jesu_iste = 1;
					for (j = 0; j < length; j++)
						if (text[j] != word[j]) {
							jesu_iste = 0;
							break;
						}
					if (jesu_iste) {
						char *exchange = zamjene[i];
						if (duzina_stringa(word) == duzina_stringa(exchange)) {
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
						}
						else if (duzina_stringa(word) < duzina_stringa(exchange)) {
							int add = duzina_stringa(exchange) - duzina_stringa(word);
							int for_loop = duzina_stringa(text);
							char *remember = text;
							while (*text != '\0') text++;
							text--;
							while (--for_loop) {
								*(text + add) = *text;
								text--;
							}
							text = remember;
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
						}
						else if (duzina_stringa(word) > duzina_stringa(exchange)) {
							int add = duzina_stringa(word) - duzina_stringa(exchange);
							while (*exchange != '\0') {
								*text = *exchange;
								text++;
								exchange++;
							}
							char *remember = text;
							while (*text != '\0') {
								*text = *(text + add);
								text++;
							}
							text = remember;
						}
					}
				}
				length = 0;
		
	}
	
	
	return tekst;
	
}



/*
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char *p = tekst;
	if (*p == '\0') return p;
	*(tekst + duzina_stringa(tekst)) = ' ';
	*(tekst + duzina_stringa(tekst) + 1) = '\0';
	int i;
	
	while (*p != '\0') {
		char *trenutna_rijec = p;
		int duzina_trenutne_rijeci = 0;
		
		while (*trenutna_rijec != '\0') {
			duzina_trenutne_rijeci++;
			//printf("%c", *trenutna_rijec);
			trenutna_rijec++;
			if (*trenutna_rijec == ' ') break;
			
		}
		
		char *za_provjeru = trenutna_rijec - duzina_trenutne_rijeci;
		for (i = 0; i < broj_rijeci; i++) {
			if (duzina_stringa(rijeci[i]) != duzina_trenutne_rijeci) continue;
			else {
				char *q = za_provjeru; // pokazivac za provjeravanje *q sa rijeci[i]
				char pret = *(trenutna_rijec);
				if (pret >= 'A' && pret <= 'Z' || pret >= 'a' && pret <= 'z') continue;
				char *w = rijeci[i];
				int jednaki = 1;
				while (*w != '\0') {
					if (*w != *q) {
						jednaki = 0;
						break;
					}
					w++;
					q++;
				}
				if (jednaki) {
					char *q = za_provjeru;
					char *w = zamjene[i];
					
					if (duzina_stringa(rijeci[i]) == duzina_stringa(zamjene[i])) {
						int len = duzina_stringa(rijeci[i]);
						while (len--) {
							*q = *w;
							w++;
							q++;
						}
					}
					else if (duzina_stringa(rijeci[i]) > duzina_stringa(zamjene[i])) {
						int len = duzina_stringa(zamjene[i]);
						w = zamjene[i];
						
						while (*w != '\0') {
							*q = *w;
							w++;
							q++;
						}
						len = duzina_stringa(rijeci[i]) - duzina_stringa(zamjene[i]);
						w = q + len;
						
						while (*w != '\0') {
							*q = *w;
							q++;
							w++;
						}
						*q = '\0';
					}
					else {
						int len = duzina_stringa(zamjene[i]) - duzina_stringa(rijeci[i]);
						while (*q != '\0') q++;
						while (q > za_provjeru + duzina_stringa(rijeci[i])) {
							*(q + len) = *q;
							q--;
						}
						q -= duzina_stringa(rijeci[i]);
						len = duzina_stringa(zamjene[i]);
						while (len--) {
							*q = *w;
							q++;
							w++;
						}
						*q = ' ';
					}
				}
			}
		}
		while (*trenutna_rijec == ' ') trenutna_rijec++;
		p = trenutna_rijec;
	}
	p = tekst;
	return p;
}*/
int main() {
	char* rijeci[2] = { "r1", "r2" };
	char* zamjene[2] = { "z1", "z2" };
	char tekst[100] = "aaa aa r1 aaa aaaa";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));

	return 0;
}
