#include <stdio.h>

void unesite (char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i =0;
	while (i< velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';

}


int provjeri_duzine (char* s, int niz[], int br)
{
	int i, count=0, brojRijeci=0;
	char* poc=s;
	// Brojac rijeci
	while (*s!='\0') {
		while ((*s<'A' || *s>'Z') && (*s>'z' || *s<'a')) s++;
		while ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z' && *s!='\0')) s++;
		while ((*s<'A' || *s>'z') && (*s>'z' || *s<'a') && *s!='\0') s++;
		brojRijeci++;

	}
	s--;
	if (*s==' ') brojRijeci--;
	s=poc;

	//Provjeravamo da li je isti broj rijeci i broj elemenata u nizu
	if (brojRijeci!=br) return 0;

	//Glavna petlja za provjeru duzine
	else
		for (i=0; i<br; i++)

		{
			int broj=niz[i];
			while ((*s<'A' || *s>'Z') && (*s>'z' || *s<'a')) s++; //Prede preko svih znakova
			while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				count++;
				s++;
			}

			if (broj!=count) return 0;
			else if (broj==count) {
				count=0;
				s++;
			}

		}

	return 1;
}
int main()
{
	char recenica[1000];
	int br=0;
	printf("Unesite recenicu: ");
	unesite(recenica, 1000);
	int niz[9999], i;
	scanf("%d", &br);
	for (i=0; i<br; i++) {
		scanf ("%d", &niz[i]);
	}
	//Provjera koja mi je sluzila dok sam testirala program :D
	if (provjeri_duzine(recenica, niz, br) == 1) printf ("Tacno");
	else printf ("Netacno");
	return 0;
}
