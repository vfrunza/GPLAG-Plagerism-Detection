#include <stdio.h>

int provjeri_duzine(char* tekst,int niz[],int vel)
{
	int i=0,brojac=0,broj_rijeci=0;
	while(!((*tekst>='a' && *tekst<='z') || (*tekst>='A' && *tekst<='Z')) && *tekst!='\0') tekst++;
	while(*tekst!='\0') {
		brojac=0;
		while(((*tekst>='a' && *tekst<='z') || (*tekst>='A' && *tekst<='Z')) && *tekst!='\0') {
			tekst++;
			brojac++;
		}
		if(i>vel) return 0;
		if(brojac>0)
			if(brojac!=niz[i]) return 0;
		if(brojac!=0) {
			i++;
			broj_rijeci++;
		}
		if(*tekst=='\0') break;
		tekst++;
	}
	if(broj_rijeci!=vel) return 0;
	return 1;
}

int main()
{
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};
	int niz2[] = {5,2,3,8};
	int niz3[] = {5,2,3,4,0};
	printf("%d ", provjeri_duzine(tekst, niz3, 5));
	printf("%d ", provjeri_duzine(tekst, niz2, 4));
	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
