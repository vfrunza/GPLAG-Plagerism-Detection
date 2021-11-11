#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci,
                     char** zamjene, int broj_rijeci)
{
	char* reset=tekst;
	char* pocetak_r;
	char* pocetak_t;
	char* pocetak_z;
	int i, duzina_rijeci=0, brojac=0, duzina_zamjene=0;
	while(*tekst!='\0') {
		while((*tekst<'A' || *tekst>'z') && *tekst!='\0')
			tekst++;
		pocetak_t=tekst;
		for(i=0; i<broj_rijeci; i++) {


			if(*rijeci[i]!= *tekst)
				continue;
			pocetak_r=rijeci[i];
			while(*rijeci[i]!='\0') {
				duzina_rijeci++;
				rijeci[i]++;
			}
			rijeci[i]=pocetak_r;
			pocetak_t=tekst;
			while(*tekst==*rijeci[i] && *tekst!='\0' && *tekst!=' ' && *rijeci[i]!='\0') {
				tekst++;
				rijeci[i]++;
				brojac++;
			}
			if(brojac==duzina_rijeci && (*tekst==' ' || *tekst=='\0')) {
				tekst=pocetak_t;

				pocetak_z=zamjene[i];
				while(*zamjene[i]!=' ' && *zamjene[i]!='\0') {


					duzina_zamjene++;
					zamjene[i]++;
				}
				zamjene[i]=pocetak_z;
				if(duzina_rijeci>duzina_zamjene) {
					while(*(tekst+duzina_rijeci-duzina_zamjene)!='\0') {
						*tekst=*(tekst+duzina_rijeci-duzina_zamjene);
						tekst++;
					}
					*tekst='\0';
					tekst=pocetak_t;

				}

				else	 if(duzina_rijeci==duzina_zamjene) {
					while(*tekst!=' ' && *tekst!='\0' && *zamjene[i]!='\0' && *zamjene[i]!=' ') {
						*tekst=*zamjene[i];
						zamjene[i]++;
						tekst++;
					}
					tekst=pocetak_t;
				}


			}

			duzina_rijeci=0;
			duzina_zamjene=0;
			brojac=0;


		}
		while(*tekst!=' ' && *tekst!='\0')
			tekst++;

	}
	tekst=reset;

	return tekst;
}

int main()
{

	return 0;
}
