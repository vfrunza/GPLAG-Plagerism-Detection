#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int vel)
{
	int duzina_rijeci=0;
	int broj_rijeci=0;
	char *a=s, *p1=s, *p2=s;
	int i=0;
	while(*s!='\0')
	{
		if((*s>='a' && *s<='z')||( *s>='A' && *s<='Z'))
		{
			broj_rijeci++;
			while((*s>='a' && *s<='z')||( *s>='A' && *s<='Z')) s++;
		}
		if(*s!='\0')s++;
	}
	if(broj_rijeci!=vel) return 0;
	s=a;
	while(*s!='\0')
	{
		duzina_rijeci=0;
		if((*s>='a' && *s<='z')||( *s>='A' && *s<='Z'))
		{
			p1=s;
			while((*s>='a' && *s<='z')||( *s>='A' && *s<='Z')) s++;
			p2=s;
			while(p1!=p2) { duzina_rijeci++; p1++;}
			if(niz[i]!=duzina_rijeci) return 0;
			else i++;
		}
		if(*s!='\0')s++;
	}
	return 1;
}

int main() {
	/* AT1: Primjer iz zadatka */
char tekst[] = "Ovo je neki primjer teksta";
int niz[] = {3, 2, 4, 7, 6};
int bezveze_niz[] = {1, 2, 3, 4, 5};

printf("%d ", provjeri_duzine(tekst, niz, 5));
printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));

	return 0;
}
