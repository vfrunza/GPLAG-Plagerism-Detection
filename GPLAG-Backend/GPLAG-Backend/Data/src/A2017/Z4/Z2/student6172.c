#include <stdio.h>

int provjeri_duzine(char* s, int* niz, int vel) {
	int duzina_rijeci=0;
	int broj_rijeci=0;
	int brojac_niza=0;
	int* p=niz;
	int neslovo=1;
	char* klizeci=s;
	while (*klizeci) {
		if (!((*klizeci>='A' && *klizeci<='Z') || (*klizeci>='a' && *klizeci<='z'))) {
			neslovo=1;
		}
		else if (neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		klizeci++;
	}
	if (broj_rijeci!=vel) {
		return 0;
	}
	int pomocna=0;
	while (*s) {
		if (pomocna==0) {
			while (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z')) {
				s++;
			}
		}
		pomocna=1;
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			duzina_rijeci++;
		}
		else {
			if (duzina_rijeci!=*(p+brojac_niza)) {
				return 0;
			}
			brojac_niza++;
			while (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				s++;
				if (*s==0) {
					if (duzina_rijeci!=*(p+brojac_niza-1)) {
						return 0;
					}
					else {
						return 1;
					}
				}
			}
			duzina_rijeci=0;
			s--;
		}
		s++;
	}
	if (duzina_rijeci!=*(p+brojac_niza)) {
		return 0;
	}
	return 1;
}
//nadijina verzija
#include <stdio.h>
//fja za prebrojavanje rijeci u stringu
int broj_rijeci(char*s)
{
	int slovo=0;
	int br_rijeci=0;
	while(*s) {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			slovo=0;
		else if(slovo==0) {
			slovo=1;
			br_rijeci++;
		}
		s++;
	}
	return br_rijeci;
}
int provjeri_duzine(char *s, int* niz, int duzina)
{
	char*poc=s;
	int br_slova=0;
	int*p=niz;
	while(*s) {
		br_slova=0;
		//brojimo slova, da bismo poredili te brojac vracamo na 0
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			s++;
			br_slova++;
		}
		if(p-niz < duzina && br_slova==*p) {
			if(p-niz<broj_rijeci(poc)) {
				p++;
			} else return 0;
		}
		else if(duzina < broj_rijeci(poc)) return 0;
		//naredna linija preskace sve sto nije slovo ukljucujuci i \0 zato ga moramo navesti u if uslovu 
		else if(*s && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) s++;
		else return 0;
	}
	if(p-niz==duzina) return 1;
	else return 0;
}
int main()
{
	return 0;
}

