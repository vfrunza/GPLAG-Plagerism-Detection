#include <stdio.h>
#include <ctype.h>

void najduzi_bp(char* s1, char* s2){
	char slovo;
	int u_rijeci = 0; /* 0 = nisam u rijeci trenutno, 1 = jesam u rijeci trenutno */
	char *pocetak_teksta = s1;
	char *pocetak_rijeci;
	char *pozicija;
	
	int trenutna_duzina_rijeci;
	int duzina_najduze_rijeci = 0;
	char *pozicija_najduze_rijeci;
	
	/* Ovo je neki primjer teksta */
	while (*s1 != '\0') {
		if ( isalpha(*s1) ) {
			slovo = tolower(*s1);
			if (u_rijeci == 0) {
				u_rijeci = 1;
				pocetak_rijeci = s1;
			} else {
				// provjera duplikata
				for (pozicija = pocetak_rijeci; pozicija < s1; pozicija++) {
					if (slovo == tolower(*pozicija)) {
						trenutna_duzina_rijeci = pozicija - pocetak_rijeci + 1;
						if (trenutna_duzina_rijeci > duzina_najduze_rijeci) {
							duzina_najduze_rijeci = trenutna_duzina_rijeci;
							// ovo je pocetak_rijeci prije pomjeranja udesno, odnosno sa lijevim dijelom
							pozicija_najduze_rijeci = pocetak_rijeci;
						}
						pocetak_rijeci = pozicija + 1;
						break;
					}
				}
			}

			trenutna_duzina_rijeci = s1 - pocetak_rijeci + 1;
			if ( trenutna_duzina_rijeci > duzina_najduze_rijeci ) {
				duzina_najduze_rijeci = trenutna_duzina_rijeci;
				pozicija_najduze_rijeci = pocetak_rijeci;
			}
			
		} else {
			if (u_rijeci == 1) {
				u_rijeci = 0;
			}
		}
		
		s1++;
	}
	
	/* printf("Duzina najduze rijeci je %d\n", duzina_najduze_rijeci); */
	/* printf("Pozicija najduze rijeci pocinje na %d\n", pozicija_najduze_rijeci - pocetak_teksta); */
	for (pozicija = pozicija_najduze_rijeci; pozicija < (pozicija_najduze_rijeci + duzina_najduze_rijeci); pozicija++) {
		*s2 = *pozicija;
		s2++;
	}
	*s2 = '\0';
	
}


int main() {
	char *recenica = "Ovo je neki primjer teksta";
	char najveci[100];
	
	najduzi_bp(recenica, najveci);
	
	return 0;
}
