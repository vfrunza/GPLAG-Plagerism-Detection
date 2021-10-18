#include <stdio.h>

int provjeri_duzine(char *s,int niz[],int n) {

	int brojac;
	int i=0;

	while (*s!='\0') {
		brojac=0;
		while (((*s >= 'A' && *s <= 'Z') || (*s <= 'z' && *s >= 'a')) && (*s != '\0')) {
			brojac++;
			s++;
		}
		
		if (brojac != 0) {
		
			if (niz[i] != brojac) {
				return 0;
			}
			i++;
		}
		if (*s=='\0') break;
		s++;
	}
	if (n != i) return 0;
	return 1;
}

int main() {
	return 0;
}

