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
