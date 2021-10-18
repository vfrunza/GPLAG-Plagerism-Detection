#include <stdio.h>

int provjeri_duzine(char *tekst, int *broj, int duzina)
{
    int brojac=0;
	while (*tekst!='\0') {
		if ((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')) {
			if (!duzina)
				return 0;
			brojac=0;
			while ((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')) {
				brojac++;
				tekst++;
			}
			if (brojac!=*broj++)
				return 0;
			duzina--;
			tekst--;
		}
		tekst++;
	}
	if (!duzina)
		return 1;
	return 0;
}

int main()
{
	char tekst [] = "Ovo je neki primjer teksta";
	int brojevi [] = {3,2,4,7,6,4};
	printf("%d", provjeri_duzine(tekst,brojevi,6));
	return 0;
}
