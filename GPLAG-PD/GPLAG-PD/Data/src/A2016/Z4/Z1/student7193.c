#include <stdio.h>

int slovo(char x) {
	return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}

char* izbaciRijeci (char* recenica, int* niz, int n) {
	char* pocetakRecenice = recenica, *pocetak, *kraj;
	int redniBroj = 0, x = 0;
	
	if (n == 0) 
		return recenica;
	
	while (*recenica != 0) {
		if (redniBroj == niz[x]) {
			pocetak = recenica;
			while (*recenica != 0 && slovo(*recenica) != 0) {
				recenica++;
			}
			if (*recenica == 0) {
				*pocetak = 0;
			} else {
				kraj = recenica;
				recenica = pocetak;
				while (*kraj != 0) {
					*pocetak++ = *kraj++;
				}
				*pocetak = 0;
			}
			x++;
			if (x == n) {
				return pocetakRecenice;
			}
		}
		
		if (slovo(*recenica) == 0) {
			redniBroj++;
			while (slovo(*(recenica+1)) == 0)
				recenica++;
		}
		
		if (*recenica != 0) {
			recenica++;
		}
	}
	return pocetakRecenice;
}

int isteRijeci(char* rijec1, char* rijec2) {
	while (*rijec1 != 0 && *rijec2 != 0) {
		if (!(*rijec1 == *rijec2 || *rijec1-32 == *rijec2 || *rijec1 == *rijec2-32)) 
			return 0;
		rijec1++;
		rijec2++;
	}
	if (*rijec1 == 0 && *rijec2 == 0)
		return 1;
	else 
		return 0;
}

void postavi(int* niz) {
	int i;
	for (i = 0; i < 1000; i++) {
		niz[i] = 0;
	}
}

char* izbaci_najcescu(char* s) {
	char* pocetak = s, rijeci[1000][1000];
	int brojRijeci = 0, x, i, j, max = 0, n = 0, istih;
	int ponavljanja[1000] = {0}, izbacivanja[1000] = {0};
	
	while (*s != 0 && slovo(*s) == 0 && slovo(*(s+1)) == 0)
		s++;
	while (*s != 0) {
		x = 0;
		
		while (*s != 0 && slovo(*s)) {
			rijeci[brojRijeci][x++] = *s++;
		}
		rijeci[brojRijeci][x] = 0;
		brojRijeci++;
		if (*s != 0 && slovo(*s) == 0) {
			while (slovo(*(s+1)) == 0)
				s++;
		}
		if (*s != 0) {
			s++;
		}
	}
	
	for (i = 0; i < brojRijeci; i++) {
		istih = 0;
		postavi(ponavljanja);
		for (j = 0; j < brojRijeci; j++) {
			if (isteRijeci(rijeci[i], rijeci[j])) {
				istih++;
				ponavljanja[j] = 1;
			}
		}
		if (istih > max) {
			max = istih;
			n = 0;
			for (j = 0; j < brojRijeci; j++) {
				if (ponavljanja[j] == 1) {
					izbacivanja[n++] = j;
				}
			}
		}
	}
	
	izbaciRijeci(pocetak, izbacivanja, n);
	return pocetak;
}

int main() {
	char tekst[100] = "a a a b b c c";
	printf(":%s:\n", izbaci_najcescu(tekst));
	return 0;
}
