#include <stdio.h>

int provjeri_duzine(char* s, int* niz, int vel) {
	int duzina_rijeci=0;
	int broj_rijeci=0;
	int brojac_niza=0;
	int* p=niz;
	int neslovo=1;
	char* klizeci=s;
	while (*klizeci) {
		if (!((*klizeci>='A' && *klizeci<='Z') || (*klizeci>='a' && *klizeci<='z'))) {
			neslovo=1;
		}
		else if (neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		klizeci++;
	}
	if (broj_rijeci!=vel) {
		return 0;
	}
	int pomocna=0;
	while (*s) {
		if (pomocna==0) {
			while (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z')) {
				s++;
			}
		}
		pomocna=1;
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			duzina_rijeci++;
		}
		else {
			if (duzina_rijeci!=*(p+brojac_niza)) {
				return 0;
			}
			brojac_niza++;
			while (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				s++;
				if (*s==0) {
					if (duzina_rijeci!=*(p+brojac_niza-1)) {
						return 0;
					}
					else {
						return 1;
					}
				}
			}
			duzina_rijeci=0;
			s--;
		}
		s++;
	}
	if (duzina_rijeci!=*(p+brojac_niza)) {
		return 0;
	}
	return 1;
}

int main() {
	char s[20]="Ovo je tekst neki sada";
	int niz[5]={3, 2, 5, 4};
	printf("%d", provjeri_duzine(s, niz, 3));
	return 0;
}
