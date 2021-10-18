#include <stdio.h>
int duzinapodniza (char *niz) {
	int brojac=1, i, logicka=0;
	char *pok=niz+1; /* Krecemo od prvog sljedeceg elementa */
	while ((*pok>='A' && *pok<='Z') || (*pok>='a' && *pok<='z')) {
		logicka=0;
		if (*pok>='A' && *pok<='Z') {
			for (i=0;i<pok-niz;i++) {
				if (*pok==*(niz+i) || *pok+32==*(niz+i)) {
					logicka=1;
					break; /* Dvostruka petlja koja poredi trenutni element sa svim prijasnjim */
				}
			}
		}
		if (*pok>='a' && *pok<='z') {
			for (i=0;i<pok-niz;i++) {
				if (*pok==*(niz+i) || *pok-32==*(niz+i)) {
					logicka=1;
					break;
				}
			}
		}
		if (logicka)
			break; /* Logicka promjenljiva se koristila kao efikasan nacin da se izadje iz unutrasnje for i vanjske while petlje */
		pok++; /* Ako unutrasnje petlje nisu nasle identicne elemente, povecavamo brojac za 1 i pomjeramo pokazivac za jedno mjesto */
		brojac++;
	}
	return brojac;
}
void najduzi_bp(char *s1, char *s2) {
	int duzinaPodniza, maxDuzina, i;
	char *pokNaPocetak;
	while (!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')))
		s1++; /* Pomjeramo pocetni pokazivac do prvog slova */
	pokNaPocetak=s1; /* Uzimamo kao pocetnu vrijednost najveceg podniza prvo slovo u recenici */
	maxDuzina=1;
	while (*(s1+1)) {
		if (!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) {
			s1++;
			continue; /* Preskace brojanje podniza od charactera koji nisu slova */
		}
		duzinaPodniza=duzinapodniza(s1);
		if (duzinaPodniza>maxDuzina) {
			maxDuzina=duzinaPodniza;
			pokNaPocetak=s1; /* Ako nadje neki podniz koji je veci od dosadasnjeg, postavlja pokazivac na prvo slovo i azurira duzinu najveceg podniza */
		}
		s1++;
	}
	for (i=0;i<maxDuzina;i++) {
		*s2++=*pokNaPocetak++; /* Kopiranje pronadjenog najveceg podniza u s2 */
	}
	*s2='\0';
}

int main() {
	char niz[10];
	najduzi_bp(" a", niz);
	printf("%s", niz);
	return 0;
}
