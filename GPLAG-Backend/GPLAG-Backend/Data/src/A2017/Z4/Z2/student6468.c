#include <stdio.h>

int duzinaRijeci(char* pocetak, char* kraj) {
	int pov=0;
	while(pocetak!=kraj) {
		pov++;
		pocetak++;
	}
	return pov;
}

int provjeri_duzine(char* tekst, int niz[], int duzinaNiza) {
	int trenutnaRijec=0;
	char* tmp=tekst;
	while(*tekst!='\0') {
		if((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')) {
			tmp=tekst;
			while((*tmp>='A' && *tmp<='Z') || (*tmp>='a' && *tmp<='z')) {
				tmp++;
			}

			if(duzinaRijeci(tekst,tmp)!=niz[trenutnaRijec]) 
				return 0;
			trenutnaRijec++;
			tekst=tmp;
		}
		else {
			tekst++;
		}
	}
	
	if(duzinaNiza != trenutnaRijec) 
		return 0;
	else
		return 1;
}

int main() {
char tekst[] = "Napravicemo jos jedan primjer";
int niz[] = {11, 3, 5, 7};

printf("%d ", provjeri_duzine(tekst, niz, 0));
printf("%d ", provjeri_duzine(tekst, niz, 3));
printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}