#include <stdio.h>

int provjeri_duzine (char *s, int *niz, int vel)
{
	int razmak=1;
	int	broj_rijeci=0, broj_slova=0, i;
	int *p=niz;

	char *r;
	char *poc=s;

	/*Prvjera da li broj cifara niza odgovara broju rijeci u recenici*/
	while(*s!='\0') {
		if(!(*s>='A'&&*s<='Z' ||(*s>='a'&&*s<='z')))
			razmak=1;
		else if(razmak==1) {
			razmak=0;
			broj_rijeci++;
		}
		s++;
	}
	if(broj_rijeci != vel) return 0;

	/*Provjeraa da li su neke cifre negativne (neispravno unesen niz cifara)*/
	while(p<niz+vel) {
		if(*p<=0) return 0;
		p++;
	}

	/*Provjera da li broj slova svake rijeci odgovara cifri koja je ista po redu*/
	i=0;
	razmak=1;
	s=poc;

	while (*s!='\0') {
		if(!((*s>='A'&&*s<='Z') ||(*s>='a'&&*s<='z')))
			razmak = 1;
		else if(razmak==1) {
			broj_slova=0;
			razmak=0;
			r=s;
			while((*r>='A' && *r<='Z') ||(*r>='a' && *r<='z')) {
				broj_slova++;
				r++;

			}
			if (niz[i] != broj_slova) return 0;
			else i++;
		}


		s++;
	}

	return 1;

}

int main()
{
	char tekst[] = "Kakav je ovo test!?!?";
	int niz2[] = {1,2.5,3,4};
	printf("%d ", provjeri_duzine(tekst, niz2, 4));
	return 0;
}
