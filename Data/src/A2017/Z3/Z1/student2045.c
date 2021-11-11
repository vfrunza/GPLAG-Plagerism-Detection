#include <stdio.h>
int dva_od_tri(int niz1[],int l1, int niz2[],int l2, int niz3[],int l3) /* Prototip funkcije */
{
	int i=0,j,c,broj = 0,isti=0,cc;

	if(l1!=0 && l2!=0 && l3!=0) { /* Uslov: Ako su duzine razlicite od nule, onda radi sljedece: */

		while(i<l1) { /* Uzimamo pojedinacne clanove prvoga niza i poredimo sa ostala dva */
			if (i>0) { /* Ispitaj ovo akko je i>0 jer nema smisla u suprotnom */
				for(c=0; c<i; c++) {
					if(niz1[i]==niz1[c]) /* Ako su prethodni clan i njegov sljedbenik jednaki u prvom nizu, prelazi se na taj sljedbenik */
						goto kraj;
				}
			}
			/* Odvojeno radi preglednosti */
			for(j=0; j<l2; j++) { /* Poredimo sada i-ti clan prvog niza sa drugim cijelim nizom */
				if(niz1[i]==niz2[j]) { /* Ukoliko su isti brojevi ne ispituj vise */
					isti++; /* Dodaj +1 varijabli isti*/
					goto next;
				}
			}
next:
			for(j=0; j<l3; j++) { /* Sada poredimo i-ti clan prvog niza sa clanovima treceg niza, princip isti kao i prije */
				if(niz1[i]==niz3[j]) {
					isti++;
					goto nexte;
				}
			}
nexte:
			if(isti==1) {
				broj++; /* Ako je varijabla isti == 1, to znaci da imamo broj koji se ponavlja u dva niza i dodaje se varijabli broj +1  */
			}
kraj:
			isti=0;
			i++;
		}

		isti=0; /* Resetuje obje vrijednosti isti i i na nulu */
		i=0;

		while(i<l2) { /* Sada poredimo drugi i treci niz, tako ako imaju isti brojevi u ta dva niza, da ispita da li se taj isti broj nalazi i u prvome nizu */
			if (i>0) {
				for(c=0; c<i; c++) {
					if(niz2[i]==niz2[c])
						goto krajj;
				}
			}
			for(j=0; j<l3; j++) {
				if(niz2[i]==niz3[j]) {
					isti++;
					for(c=0; c<l1; c++) {
						if(niz3[j]==niz1[c]) {
							isti++;
						}
					}
				}
			}

			if(isti==1) broj++;
krajj:
			isti=0;
			i++;
		}
	}	/* kraj glavnog IF-a */

	else { /* Ukoliko ima neki prazan niz onda ce se porediti dva niza koja nisu prazna */

		for(c=0; c<l1; c++) {
			for(cc=0; cc<l2; cc++) {
				if(niz1[c] == niz2[cc]) {
					broj++;
					goto novi;

				}
			}
novi:
			; /* Nakon Labela mora slijediti ';' ukoliko nema nekih drugih struktura */
		}

		for(c=0; c<l1; c++) {
			for(cc=0; cc<l3; cc++) {
				if(niz1[c] == niz3[cc]) {
					broj++;
					goto novii;

				}
			}
novii:
			;
		}

		for(c=0; c<l2; c++) {
			for(cc=0; cc<l3; cc++) {
				if(niz2[c] == niz3[cc]) {
					broj++;
					goto noviii;
				}
			}
noviii:
			;
		}
	}
	return broj; /* Funkcija vraca ovu vrijednost */
}

int main() /* int main se koristila u ovom primjeru samo kao proba */
{
	int niz1[] = {0};
	int niz2[] = {0};
	int niz3[] = {0};
	int rez = dva_od_tri(niz1, 0, niz2, 0, niz3,0);
	printf("%d", rez);
	return 0;
}