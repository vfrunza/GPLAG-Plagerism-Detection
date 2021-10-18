#include <stdio.h>

char *kodiraj(char *c , char *sifrarnik)
{
	char *pokazivac_stringa=c;
	char *pokazivac_tabele=sifrarnik;
	int znak=0;
	int i;
	int brojaci[95]= {0}; /* niz brojaca koji imaju pocetnu vrijednost nula */
	int brojac=0;
	int mjesto_stringa=0; /*pozicija na kojoj se nalazi*/

	while(*c!='\0') {
		brojaci[*c-32]++; /*pomjera vrijednost za 32 prema ascii tabeli */
		c++;
	}

	for(;;) {
		int postoji=0; /* pretpostavka da ne postoji slovo u tekstu */
		for(i=0; i<95; i++) {
			if(brojaci[i]>0) {
				postoji=1;
				break;
			}
		}

		if(postoji==1) {
			int max=0;
			for(i=0; i<95; i++) {
				if(brojaci[i]>max) {
					max=brojaci[i];
					znak=i;

				}
			}

			brojaci[znak]=-1;
			brojac++;
			*sifrarnik=znak+32;
			sifrarnik++;
		} else break;
	}

	*sifrarnik=' ';
	for(i=0; i<95; i++) {
		if(brojaci[i]==0) {
			*sifrarnik=i+32;
			sifrarnik++;
		}
	}
	sifrarnik++;
	*sifrarnik='\0';
	c=pokazivac_stringa;
	sifrarnik=pokazivac_tabele;

	while(*c) {
			for(i=0; i<brojac; i++) {
			if(*c==sifrarnik[i]) {
				mjesto_stringa=i;
				break;
			}
		}

		*c=126-mjesto_stringa;
		c++;
	}

	return pokazivac_stringa;
}

char *dekodiraj(char *c,char *sifrarnik)
{
	int mjesto_stringa;
	char *pokazivac_stringa=c;
	while(*c) {
		mjesto_stringa=126-*c;
		*c=sifrarnik[mjesto_stringa];
		c++;
	}
	return pokazivac_stringa;
}

int main()
{
	return 0;
}
