/*#include <stdio.h>
int provjeri_duzine(char *s1,int *n,int vel)
{
	char *s=s1;
	int brojac=0, rijeci=0;
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			rijeci++;
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				s++;
			}
		} else s++;
	}
	if(rijeci!=vel) return 0;
	s=s1;
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				brojac++;
				s++;
			}
			if(brojac!=*n) return 0;

			brojac=0;
			n++;
		} else
			s++;
	}
	return 1;
}

int main()
{
	char s[]="Kakav je ovo test";
	int n[]= {5,2,3,4};
	printf("%d",provjeri_duzine(s,n,4));
	return 0;
}*/ //bro, ima i ovdje jedan nacin rjesavanja ovog zadatka, just show it heh
#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int vel)
{

	int neslovo = 1, i = 0, duzina = 0, broj_rijeci = 0;
	char *pom = s;

	while(*s != '\0') {
		if(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) neslovo = 1;
		else if(neslovo == 1) {
			neslovo = 0;
			broj_rijeci++;
		}
		s++;
	}
	if(broj_rijeci != vel) return 0;
	s = pom;
	neslovo = 1;
	while(*s != '\0') {
		if(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) neslovo = 1;
		else if(neslovo == 1) {
			pom = s;
			neslovo = 0;
			duzina = 0;
			while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
				s++;
				duzina++;
			}
			if(duzina != niz[i]) return 0;
			else {
				i++;
				s = pom--;
			}
		}
		s++;
	}
	return 1;
}
int main()
{
	/* AT2: Manjka elemenata u nizu, prazan niz */
	char tekst[] = "Napravicemo jos jedan primjer";
	int niz[] = {11, 3, 5, 7};

	printf("%d ", provjeri_duzine(tekst, niz, 0));
	printf("%d ", provjeri_duzine(tekst, niz, 3));
	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
