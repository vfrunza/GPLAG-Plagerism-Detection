#include <stdio.h>

int dva_od_tri (int *pok1, int n1, int *pok2, int n2, int *pok3, int n3)
{
	int broj=0, brojac, niz[1000], n=0, i;
	int *vel1=pok1+n1, *vel2=pok2+n2, *vel3=pok3+n3;
	int *pocetak1=pok1, *pocetak2=pok2, *pocetak3=pok3;

	/* poredjenje clanova prvog niza sa drugim i trecim */
	for (; pok1<vel1; pok1++) {
		for (i=0; i<n; i++) { /* petlja provjerava da li je vec posmatran clan *pok1 (da se izbjegne ponavljanje), ako jeste pomjera pokazivac na slj. clan niza, do vel1 */
			if (pok1==vel1) break;
			if(niz[i]==*pok1) {
				pok1++;
				i=-1;
			}
		}
		if (pok1==vel1) break; /* ako je pok1 dosao do kraja niza koji se poredi sa ostala 2, prekida se petlja */
		niz[n]=*pok1; /* svaki clan koji se posmatra se stavlja u "niz" kako bi kasnije mogli vidjeti da li je on posmatran */
		n++;
		
		brojac=1; /* svaki clan se sigurno pojavljuje jednom */
		
		for (; pok2<vel2; pok2++)
			if (*pok1==*pok2) {
				brojac++;
				break;
			}
		pok2=pocetak2;
			
		for (; pok3<vel3; pok3++)
			if (*pok1==*pok3) {
				brojac++;
				break;
			}
		pok3=pocetak3;
		
		if (brojac==2) broj++; /* ako se clan pojavi u jos samo jednom nizu onda je u 2 od 3 niza */
	}
	pok1=pocetak1;

	/* poredjenje clanova drugog niza sa prvim i trecim */
	for (; pok2<vel2; pok2++) {
		for (i=0; i<n; i++) {
			if (pok2==vel2) break;
			if(niz[i]==*pok2) {
				pok2++;
				i=-1;
			}
		}
		if (pok2==vel2) break;
		niz[n]=*pok2;
		n++;
		
		brojac=1;
		
		for (; pok1<vel1; pok1++)
			if (*pok2==*pok1) {
				brojac++;
				break;
			}
		pok1=pocetak1;
		
		for (; pok3<vel3; pok3++)
			if (*pok2==*pok3) {
				brojac++;
				break;
			}
		pok3=pocetak3;
		
		if (brojac==2) broj++;
	}
	pok2=pocetak2;

	/* poredjenje clanova treceg niza sa prvim i drugim */
	for (; pok3<vel3; pok3++) {
		for (i=0; i<n; i++) {
			if (pok3==vel3) break;
			if(niz[i]==*pok3) {
				pok3++;
				i=-1;
			}
		}
		if (pok3==vel3) break;
		niz[n]=*pok3;
		n++;
		
		brojac=1;
		
		for (; pok1<vel1; pok1++)
			if (*pok3==*pok1) {
				brojac++;
				break;
			}
		pok1=pocetak1;
		
		for (; pok2<vel2; pok2++)
			if (*pok3==*pok2) {
				brojac++;
				break;
			}
		pok2=pocetak2;
		
		if (brojac==2) broj++;
	}
	pok3=pocetak3;

	return broj;
}


int main(void)
{
	int niz1[] = {1, 2, 3, 5};
	int niz2[] = {1, 2, 4, 6, 7};
	int niz3[] = {1, 3, 4, 8, 9, 10};
	int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);

	return 0;
}