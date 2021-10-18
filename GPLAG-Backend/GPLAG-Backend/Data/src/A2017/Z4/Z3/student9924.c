#include <stdio.h>

int ne_ponavlja(const char* s1, const char *s2) {
	char t1, t2 = *s2;
	if (t2 >= 'A' && t2 <= 'Z') t2 += 32;
	while (s1 != s2) {
		t1 = *s1++;
		if (t1 >= 'A' && t1 <= 'Z') t1 += 32;
		if (t1 == t2) return 0;
	}
	return 1;
}

void najduzi_bp(char* tekst, char* odr) {
	char *s = tekst, *pok1 = NULL, *pok2 = NULL, *najduzi = NULL;
	int br_slova = 0, max = 0, neslovo = 1;
	while (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0') s++;
	do {
		if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
			if (neslovo == 0) {
				while (pok1 != s) {
					pok2 = pok1;
					br_slova = 0;
					while (pok2 != s && ne_ponavlja(pok1, pok2++)) br_slova++;
					if (br_slova > max) {
						max = br_slova;
						najduzi = pok1;
					}
					pok1++;
				}
			}
			neslovo = 1;
		}
		else if (neslovo == 1) {
			neslovo = 0;
			pok1 = s;
		}
	} while (*s++ != '\0');
	if (najduzi) 
		while (max--) *odr++ = *najduzi++;
	*odr = '\0';
		
}

int main() {
    char niz[10];
    najduzi_bp ("       \n      ", niz);
    printf ("Niz: '%s'", niz);
	return 0;
}
