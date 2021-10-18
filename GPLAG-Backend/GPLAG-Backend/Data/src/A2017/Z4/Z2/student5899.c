#include <stdio.h>
#define MAX 100

int provjeri_duzine( char *s, int niz[MAX], int velicina)
{

	int neslovo=1,broj_rijeci=0,duzina=0;
	char *spok=s;
	while (*s!='\0') {

		if(!(((*s>='A' && *s<='Z') ) || ((*s>='a' && *s<='z') ))) {
			neslovo=1;
		} else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		s++;
	}
	if(broj_rijeci!=velicina) return 0;
	while(*spok!='\0') {
		if ( (!((*spok>='A' && *spok<='Z') || (*spok>='a' && *spok<='z')) && *spok!='\0')) duzina=0;

		while(( *spok!='\0') && ((*spok>='A' && *spok<='Z') || (*spok>='a' && *spok<='z'))) {
			duzina++;
			spok++;
		}
	if (duzina!=0) {
		if (duzina == *niz ) {
				niz++;
				spok--;
			} else if(duzina != *niz) {

				return 0;
			}

	}



		spok++;
	}

	return 1;

}

int main()
{
	char s[]=".Ovo je jedan";
	int niz[]= {3,2,5};
	int velicina=0,brojac=0,i=0;
	for(i=0; i<3; i++) {
		brojac++;
	}
	velicina=brojac;
	printf("%d",provjeri_duzine(s,niz,velicina));
	return 0;
}
