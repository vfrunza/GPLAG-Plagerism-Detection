#include <stdio.h>

int provjeri_duzine(char* s, int niz[], int duzina)
{

	int i=-1, brojac = 0; /* Varijablom i "hodamo" po naseme nizu */
	int j = 0, brojach = 0, provjeri = 0;
	char *p=s; /* Pamtimo pocetak stringa pomocu pokazivaca */

	/* Provjeri koliko ima rijeci u recenici i da li se broj rijeci poklapa sa duzinom niza brojeva */
	while(*s != '\0') {
		if (((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (*s != ' ')) {
			brojach++;
			s++;
			provjeri = 1;
		} else if  ((*s<'A' || *s>'Z') || (*s<'a' && *s>'z')) {
			brojach = 0;
			if(provjeri == 1) j++;
			provjeri = 0;
			s++;
		}
	}

	/* Ako je prethodni znak slovo, ispitaj da li je "j" jednak duzini brojeva u nizu, ako nije vrati nulu */
	s--;
	if (((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') ) && (*s != ' ')) j++;
	if(j!=duzina) return 0;
	provjeri = 1;

	/* Dodaji vrijednost brojacu sve dok je ASCII znak slovo, ukoliko nije, ispitaj da li je brojac razlicit od broja brojeva u nizu i vrati 0 ako je taj uslov ispunjen */
	while(*p != '\0') {

		if (((*p>='A' && *p<='Z') || (*p>='a' && *p<='z') ) && (*p != ' ')) {
			brojac++;
			p++;
			if (provjeri == 1) {
				i++;
			}
			provjeri = 0;
		} else if  ( (*p<'A' || *p>'Z') || (*p<'a' && *p>'z') ) {
			if(provjeri==0) {
				p--;
			}
			if (((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))
				if(brojac != niz[i]) return 0;
			if(provjeri==0) {
				p++;
			}
			brojac = 0;
			provjeri = 1;
			p++;
		}
	}
	return 1;
}

int main()
{
	/* Nema nista ovdje */
}