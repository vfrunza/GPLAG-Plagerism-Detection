#include <stdio.h>
int broj_rijeci(char *s)
{
	int broj=1,broj2=0;
	if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) broj=0;
	while(*s!='\0')
	{
		if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) && ((*(s+1)>='a' && *(s+1)<='z') || (*(s+1)>='A' && *(s+1)<='Z')) && *(s+1)!='\0')broj++;
		
		s++;
		broj2++;
	}
	s-=broj2;
	return broj;
}
int prebroji(char* s, int n) 
{
	int broj=1;
	int brojslova=0;
	while(*s!='\0')
	{
		
		if(broj==n && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) brojslova++; //nasli smo koja je rijec, brojimo slova
		if(((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) && !((*(s+1)>='a' && *(s+1)<='z') || (*(s+1)>='A' && *(s+1)<='Z'))) broj++;
		s++;
	}
	return brojslova;
}

int provjeri_duzine(char *tekst, int niz[], int n)
{
	int i;
	if(broj_rijeci(tekst)!=n) return 0;
	else
	{
		for(i=0;i<n;i++)
		{
			if(niz[i]!=prebroji(tekst,i+1)) return 0;
		}
	}
	return 1;
}

int main() {
/* AT5: Ne-slova na pocetku stringa */
char tekst[] = "...i tako smo dosli do petog testa..";
int niz[] = {1,4,3,5,2,5,5};
int niz2[] = {4,4,3,5,2,5,5};
int niz3[] = {0,1,4,3,5,2,5,5};

printf(" ", provjeri_duzine(tekst, niz3, 8));
printf(" ", provjeri_duzine(tekst, niz2, 7));
printf(" ", provjeri_duzine(tekst, niz, 7));
	return 0;
}
