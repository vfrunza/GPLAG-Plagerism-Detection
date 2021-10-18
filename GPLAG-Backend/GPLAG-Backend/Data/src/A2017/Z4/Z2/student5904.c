#include <stdio.h>
int provjeri_duzine(const char* s,int niz[],unsigned vel) {
	int broj_rijeci = 0,duzina_rijeci=0;
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				duzina_rijeci++;
				s++;
			}
			if(duzina_rijeci!=*niz++)
				return 0;
			broj_rijeci++;
			duzina_rijeci=0;
		}
		else
			s++;
	}
	if(broj_rijeci!=vel)
		return 0;
	return 1;
}
int main() {
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 5 };
	printf("%d",provjeri_duzine(tekst,niz,5));
	return 0;
}
