#include <stdio.h>

int provjeri_duzine(char*s, int niz[], int duzina)
{
	/*provjeravam koliko ima rijeci i da li je broj rijeci poklapa sa duzinom niza*/
	char* pocetak =s;
	int broj_slova;
	int neslovo=1;
	int broj_rijeci=0;
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			neslovo=1;
		else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;

		}
		s++;
	}
	if(broj_rijeci!=duzina)
		return 0;

	/*prebrojavam slova u rijeci i poredim sa odgovarajucim clanom u nizu*/
	int trenutna_rijec=0;
	s=pocetak;
	while(*s!='\0') {
		broj_slova=0;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			broj_slova++;
			s++;
		}
		if(broj_slova!=0 && broj_slova!=niz[trenutna_rijec])
			return 0;
		else if (broj_slova!=0) trenutna_rijec++;
		/*petlja za preskakanje svih drugih znakova*/
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && *s!='\0') s++;
	}
	
	return 1;
}



int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
