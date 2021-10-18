#include <stdio.h>

int broj_rijeci(char* string)
{
	int slovo=1, br_rijeci=0;

	while(*string!='\0') {
		if(!(*string>='A' && *string<='Z') && !(*string>='a' && *string<='z'))
			slovo=1;
		else if(slovo==1) {
			slovo=0;
			br_rijeci++;
		}
		string++;
	}
	return br_rijeci;
}

int provjeri_duzine(char *s, int* niz, int duzina)
{
	char* poc=s;
	int*p=niz;
	int br_slova=0, ukupno_rijeci=broj_rijeci(poc);

	while(*s) {
		br_slova=0;

		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			s++;
			br_slova++;
		}

		if(duzina!=ukupno_rijeci)
			return 0;

		if(p-niz<duzina && br_slova==*p)
			p++;
		else if(!(*s>='A' && *s<='Z') && !(*s>='a' && *s<='z') && *s!='\0')
			s++;
		else
			return 0;
	}

	if(p-niz==duzina)
		return 1;
	else
		return 0;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
