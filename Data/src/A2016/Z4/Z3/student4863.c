#include <stdio.h>
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char* treset=tekst, *reset=*rijeci, *zreset=*zamjene, *pok, *pok2;
	char* reset1=rijeci, *zreset1=zamjene, *preset;
	char *zpok, *rpok, *kraj, *pkraj;
	int i, j, razlika=0, zduzina=0, rduzina=0;

	while(*tekst != '\0') {
		for(i=0; i<broj_rijeci; i++) {
			rduzina=0;
			zduzina=0;
			if(*tekst == **rijeci && (tekst == treset || (tekst != treset && *(tekst-1) == ' '))) {
				pok=tekst;
				rpok=*rijeci;
				while(*rpok != '\0' && *rpok == *pok && *pok != '\0') {
					rpok++;
					pok++;
					rduzina++;
				}
				if((*pok == ' ' || *pok == '\0') && *rpok == '\0') {
					zpok=*zamjene;
					
					while(*zpok != '\0') {
						zduzina++;
						zpok++;
					}
					razlika=zduzina-rduzina;
					zpok=*zamjene;
					kraj=pok;
					while(*kraj != '\0')
						kraj++;
					//ubacuje prazna mjesta ako je zamjenski string duzi od pocetne rijeci
					if(razlika > 0) {
						while(kraj+1 > pok) {
							*(kraj+razlika) = *kraj;
							kraj--;
						}
						while(*zpok != '\0') {
							*tekst = *zpok;
							zpok++;
							if(*zpok != '\0')
								tekst++;
						}//ako je zamjenska rijec kraca od pocetne rijeci, skracuje string
					} else if(razlika<0) {
						razlika+=-2*razlika;
						while(*zpok != '\0') {
							*tekst = *zpok;
							zpok++;
							tekst++;
						}
						kraj=tekst;
						while(*(kraj+razlika-1) != '\0') {
							*kraj=*(kraj+razlika);
							kraj++;
						}
						//samo zamjenjuje rijec ako je iste duzine kao zamjenska
					} else if(razlika == 0) {
						while(*zpok != '\0') {
							*tekst = *zpok;
							zpok++;
							tekst++;
						}
						tekst--;
					}
				}
			}
			if(i != broj_rijeci-1) {
				rijeci++;
				zamjene++;
			}

		}
		rijeci=reset1;
		zamjene=zreset1;
		tekst++;
	}

	tekst=treset;
	return tekst;

}
int main()
{
	
	return 0;
}
