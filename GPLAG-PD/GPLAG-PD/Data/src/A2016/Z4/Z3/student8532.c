#include <stdio.h>

char* zamjena_rijeci (char *tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char rijectemp[100], zamjenatemp[100], temp[500];
	char *rijecpok = rijectemp, *zamjenapok = zamjenatemp;
	char *resetTXT = tekst, *glavni = tekst, *glavnialt = tekst;
	char *PocRijec = tekst, *KrajRijec = tekst;
	char *Izbaci1 = tekst, *Izbaci2 = tekst, *Ubaci1 = tekst, *Ubaci2 = tekst;
	char *Test = tekst, *rijeciV, *zamjeneV;
	int i = 0, j = 0, brojac = 0, pomjeraj = 0, duzinarijeci = 0, duzinazamjena = 0, slova = 0, petlja = 0;
	
	/* for petlja za svaku rijec i zamjenu iz niza pokazivaca */
	for (i=0; i<broj_rijeci; ++i) {
		
		/* Kopiram u rijectemp i brojim duzinu rijeci */
		duzinarijeci = 0;
		rijecpok = rijectemp;
		rijeciV = (*(rijeci+i));
		while (*rijeciV != '\0') {
			*rijecpok = *rijeciV;
			rijecpok++;
			rijeciV++;
			duzinarijeci++;
		}	*rijecpok = '\0';
		
		/* Kopiram u zamjenatemp i brojim duzinu zamjenske rijeci */
		duzinazamjena = 0;
		zamjenapok = zamjenatemp;
		zamjeneV = (*(zamjene+i));
		while (*zamjeneV != '\0') {
			*zamjenapok = *zamjeneV;
			zamjenapok++;
			zamjeneV++;
			duzinazamjena++;
		}	*zamjenapok = '\0';
		
		glavni = resetTXT;
		while (*glavni != '\0') {
			
			pomjeraj = 0;
			PocRijec = glavni;
			glavnialt = glavni;
			while (*glavnialt != ' ' && *glavnialt != '\0') {
				glavnialt++;
				pomjeraj++;
			}	KrajRijec = glavnialt;
			
			/* Provjera */
			slova = 0;
			petlja = 0;
			Test = PocRijec;
			rijecpok = rijectemp;
			while (Test < KrajRijec) {
				
				if (*Test == *rijecpok)
				slova++;
				petlja++;
				
				Test++;
				if (*rijecpok != '\0')
				rijecpok++;
			}
			
			/* Izbacivanje i ubacivanje */
			if (slova == duzinarijeci && petlja == duzinarijeci) {
				
				/* Izbacivanje stare rijeci */
				Izbaci1 = PocRijec;
				Izbaci2 = PocRijec + duzinarijeci;
				while (*Izbaci2 != '\0') {
					*Izbaci1 = *Izbaci2;
					Izbaci1++;
					Izbaci2++;
				}	*Izbaci1 = '\0';
				
				/* Prosirivanje stringa (korak Ubacivanja) */
				Ubaci1 = PocRijec;
				Ubaci2 = temp;
				brojac = 0;
				while (*Ubaci1 != '\0') {
					*Ubaci2 = *Ubaci1;
					Ubaci1++;
					Ubaci2++;
					brojac++;
				}	*Ubaci2 = '\0';
				
				/* Pomicanje vrijednosti */
				Ubaci1 = PocRijec;
				Ubaci2 = temp;
				for (j=0; j<(duzinazamjena+brojac); ++j) {
					if (j<duzinazamjena)
						*Ubaci1 = ' ';
					else {
						*Ubaci1 = *Ubaci2;
						Ubaci2++;
					}
					++Ubaci1;
				}
				
				/* Prava rijec iz zamjenskog niza u prosireni */
				Ubaci1 = PocRijec;
				zamjenapok = zamjenatemp;
				for (j=0; j<duzinazamjena; ++j) {
					*Ubaci1 = *zamjenapok;
					zamjenapok++;
					Ubaci1++;
				}
				
				if (duzinazamjena>duzinarijeci)
				glavni += duzinazamjena;
				else if (duzinazamjena<=duzinarijeci)
				glavni += duzinarijeci;
			}
			else {
				glavni += pomjeraj+1;
			}
		}
	}
	return resetTXT;
}

int main() {
	char *rijeci[2] = {"auto", "stop"};
	char *zamjene[2] = {"vozilo", "start"};
	char tekst[100] = "auto-stop auto. stop auto kj stop";
	printf ("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}