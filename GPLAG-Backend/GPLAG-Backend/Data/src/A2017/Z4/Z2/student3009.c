#include<stdio.h>
int broj_rijeci(char*tekst)
{
	char*s=tekst;
	int prekidac=0,broj=0;
	while(*s!='\0') {
		prekidac=0;
		while ((*s>='A' && *s<='Z')||(*s>='a'&&*s<='z') ) {
			s++;
			prekidac=1;
		}
		if (prekidac==1) {broj++;
		s--;}
		s++;
	}
	return broj;
}
int provjeri_duzine(char*tekst,int* niz[],int velicine)
{
	int brojac=0,prekidac;
	int * pok;
	pok=niz[0];
	int broj;
	broj = broj_rijeci(tekst);
	if (broj!=velicine) {
		return 0;
	} else {
		while (*tekst!='\0') {
			prekidac=0;
			brojac=0;
			while ((*tekst>='A' && *tekst<='Z')||(*tekst>='a'&&*tekst<='z') ) {
				brojac++;
				prekidac=1;
				tekst++;

			}

			if (prekidac==1) {
				int a;
				a=*pok;
				if (brojac!=a) return 0;
				pok++;
				tekst--;
			}
			tekst++;
		}
	}

	return 1;
}
int main()
{
	/* AT1: Primjer iz zadatka */
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	int bezveze_niz[] = {1, 2, 3, 4, 5};

	printf("%d ", provjeri_duzine(tekst, niz, 5));
	printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));
	return 0;
}

