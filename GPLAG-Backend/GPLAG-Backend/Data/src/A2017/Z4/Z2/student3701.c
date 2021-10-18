#include <stdio.h>

int provjeri_duzine(char*tekst,int *niz,int vel)
{
	int brojslova=0,i=0;
	while(*tekst!='\0' ) {

		brojslova=0;
		/*petljom prolazimo kroz string sve dok ne naidjemo na velika ili mala slova*/

		while((*tekst!='\0')&&((*tekst>=65&&*tekst<=90)||(*tekst>=97&&*tekst<=122))) {
			brojslova++; //ako je uslov ispunjen povecavamo brojac i pomjeramo pokazivac
			tekst++;
		}
		if(brojslova==0) {
			tekst++; //pomjeramo pokazivac ukoliko nismo naisli na slovo
			continue;
		} else if(brojslova!=*niz) { //ako br.slova i clan niza nisu isti vracamo nulu
			return 0;
		}

		else {

			i++;
			niz++;
		}
	}
	if(i<vel || i>vel) return 0;//ako broj rijeci(i) nije jednak broju clanova niza vracamo nulu
	return 1;
}

int main()
{

	char tekst[] = "Na jos jedan primjer";
	int niz[] = {2, 3, 5, 7};

	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
