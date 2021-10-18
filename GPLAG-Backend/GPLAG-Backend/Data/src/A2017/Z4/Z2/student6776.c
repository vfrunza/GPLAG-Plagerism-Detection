#include <stdio.h>

void unesi( char *s, int velicina)
{
	char znak=getchar(), *p=s;
	if(znak=='\n') znak=getchar();
	while(p<s+velicina-1 && znak!='\n') {
		*p=znak;
		znak=getchar();
		p++;
	}
	*p='\0';
}

/* brojimo rijeci u tekstu, brojac povecavamo za jedan ako naidjemo na slovo nakon kojeg slijedi neki znak koji nije slovo */
int broj_rijeci(char *s)
{
	int broj=0;
	while(*s!='\0') {
		if(((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) && !((*(s+1)>='a' && *(s+1)<='z') || (*(s+1)>='A' && *(s+1)<='Z'))) broj++;
		s++;
	}
	return broj;
}

int provjeri_duzine(char *recenica, int *niz, int broj_elemenata)
{
	int brojac, *p;

	/* ako je broj rijeci u tekstu razlicit od broja elemenata u nizu onda se program zavrsava */
	if(broj_rijeci(recenica)!=broj_elemenata) return 0;

	p=niz;
	while(p<niz+broj_elemenata) {
		brojac=0;

		/* ako znakovi u stringu nisu slova onda ih preskacemo */
		while(!((*recenica>='a' && *recenica<='z') || (*recenica>='A' && *recenica<='Z'))) recenica++;

		/* brojimo koliko rijec ima slova */
		while((*recenica>='a' && *recenica<='z') || (*recenica>='A' && *recenica<='Z')) {
			brojac++;
			recenica++;
		}

		/* ako broj slova u rijeci nije jednak odgovarajucem elementu u nizu onda se program prekida */
		if(!(brojac==*p)) return 0;
		p++;
	}

	return 1;
}

int main()
{
	char recenica[1000];
	int niz[100], i, n;
	printf("Unesi recenicu: ");
	unesi(recenica, 1000);
	printf("Unesite broj elemenata: ");
	scanf("%d", &n);
	printf("Unesite niz: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}
	printf("%d", provjeri_duzine(recenica, niz, n));
	return 0;
}
