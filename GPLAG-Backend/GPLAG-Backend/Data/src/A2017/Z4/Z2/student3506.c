#include <stdio.h>

int provjeri_duzine(char *s, int niz[], int vel) {
	int brojac_slova, broj_rijeci=0;
	char *pocetak=s;
	while(*s!='\0') {
		if((s!=pocetak && (((*(s-1)>'z' || *(s-1)<'a') && (*(s-1)<'A' || *(s-1)>'Z')) || *(s+1)=='\0') && ((*s<='z' && *s>='a') || (*s>='A' && *s<='Z'))) || (s==pocetak && ((*s<='z' && *s>='a') || (*s>='A' && *s<='Z')))) {
			brojac_slova=0;
	        while((*s<='z' && *s>='a') || (*s>='A' && *s<='Z')) {
	            brojac_slova++;
	            s++;
	        }
	        s--;
	        if(brojac_slova!=niz[broj_rijeci]) return 0;
	        broj_rijeci++;
		}
		s++;
	}
	if(broj_rijeci==vel) return 1;
	else return 0;
}

int main() {
/*	printf("Zadaća 4, Zadatak 2");*/
	return 0;
}
