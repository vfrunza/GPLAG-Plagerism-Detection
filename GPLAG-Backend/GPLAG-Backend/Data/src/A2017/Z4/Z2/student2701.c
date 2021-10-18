#include <stdio.h>

int provjeri_duzine(char* s, int niz[], int vel) {
	char *pok = NULL;
	int neslovo = 1, br_rijeci = 0;
	while (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0') s++;
	do {
		if(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
			if(neslovo == 0) {
				if(br_rijeci > vel) return 0;
				if((int)(s-pok) != niz[br_rijeci-1]) return 0; 
			}
			neslovo = 1;
		}
		else if(neslovo == 1) {
			neslovo = 0;
			pok = s;
			br_rijeci++;
		}
	} while (*s++ != '\0');
	if(br_rijeci < vel) return 0;
	return 1;
}

int main() {
	char tekst[] = "        ";
	int niz[] = {11, 3, 5, 7};
	
	printf("%d ", provjeri_duzine(tekst, niz, 0));
	printf("%d ", provjeri_duzine(tekst, niz, 3));
	return 0;
}
