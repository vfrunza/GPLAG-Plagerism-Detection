#include <stdio.h>

int prebroji_rijec(char *s1)
{
	int broj_rijeci = 0;

	while(*s1 != '\0') {
		if(((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) && !((*(s1+1)>='A' && *(s1+1)<='Z') || (*(s1+1)>='a' && *(s1+1)<='z'))) {
			broj_rijeci++;
		}
		s1++;
	}
	return broj_rijeci;
}


int provjeri_duzine(char *s, int niz[],int velicina)
{	
	char *pok2;
	char *q = s;
	char *pok1 = s;
	char *pok3 = s;
	char *a;
	
	int brojac1 = 0, brojac2=0;
	int *n1 = niz;

	while(*pok1 < 'A' || (*pok1 > 'Z' && *pok1 < 'a') || *pok1 > 'z'){
		pok1++;
	}
	pok2 = pok1;
	
	while(*pok3 != '\0'){
		pok3++;
	}
	while(*pok3 < 'A' || (*pok3 > 'Z' && *pok3 < 'a') || *pok3 > 'z'){
		pok3--;
	}
	a = pok3;

	
	if(velicina != prebroji_rijec(s)) {
		return 0;
	}


	while(*q != '\0') {
		brojac1 = 0;
		while (((*pok2>='A' && *pok2<='Z') || (*pok2>='a' && *pok2<='z')) && *pok2 != '\0') {
			brojac1++;
			pok2++;
			q++;
		}
		brojac2++;
		if(pok2 != a)
		pok2++;
		q++;


		if(brojac1 != *n1) {
			return 0;
		}
		if(brojac2==prebroji_rijec(s)) break;
		n1++;


	}

	return 1;
}

int main()
{

	return 0;
}
