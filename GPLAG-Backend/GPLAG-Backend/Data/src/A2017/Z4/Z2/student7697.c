#include <stdio.h>
int provjeri_duzine(char *recenica, int *niz, int vel) {
	int broj_slova, broj_elementa=0, istina=1;
	while (*recenica!='\0') {
		broj_slova=0;
		while(*recenica<'A' || *recenica>'z' || (*recenica>'Z' && *recenica<'a')) recenica++;
		while((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z')) {
			broj_slova++;
			recenica++;
		}
		if (niz[broj_elementa]!=broj_slova) {
			istina=0;
			break;
		}
		broj_elementa++;
		if(broj_elementa>vel) {
			istina=0;
			break;
		}
		
	}
	if(broj_elementa<vel)
	istina=0;
	return istina;
}
int main() {
	return 0;
}
