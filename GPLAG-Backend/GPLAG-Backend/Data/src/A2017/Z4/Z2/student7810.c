#include <stdio.h>

int provjeri_duzine(char *tekst, int niz[], int vel)
{
	char *pok=tekst;
	int br=0;
	while(*pok!='\0') { //prebrojavamo koliko zadati string ima rijeci
		if(((*pok>='a' && *pok<='z') || (*pok>='A' && *pok<='Z')) && !( (*(pok+1)>='a' && *(pok+1)<='z') || (*(pok+1)>='A' && *(pok+1)<='Z')))
			br++;
		pok++;
	}
	if(br!=vel) return 0; //ako broj rijeci u stringu nije isti kao velicina porosljedenog niza vracamo 0 (npr u prosljedjenom nizu moze se nalaziti viska elemenata)

	int i=0;
	while(*tekst!='\0') {
		if((*tekst>='a' && *tekst<='z') || (*tekst>='A' && *tekst<='Z')) {
			char *pom=tekst;
			while((*pom>='a' && *pom<='z') || (*pom>='A' && *pom<='Z')) { //sve dok pom pokazuje na slovo krecemo se kroz string
				pom++;
			}				//pom ce pokazivati na mjesto iza kraja rijeci, a tekst pokazuje na pocetak rijeci
			int duzina=pom-tekst; //razlika ova dva pokazivaca daje duzinu rijeci
			if(duzina==niz[i]) { //ako je duzina rijeci ista odgovarajucem elementu prosljedenog niza pokazivac tekst premjestamo na mjesto iza kraja rijeci da bismo nastavili postupak za sljedecu rijec
				tekst=pom;
				i++;	//uvecavamo i da bismo duzinu sljedece rijeci poredili sa sljedecim elementom iz niza
			} else if(duzina!=niz[i]) return 0;	//cim duzina rijeci nije ista odgovarajucem elementu niza vracamo 0
		}
		if(*tekst!='\0') //da bismo sprijecili memorijsku gresku
			tekst++;
	}
	return 1;	//ako je sve proslo kako treba, vracamo 1
}


int main()
{
	char string[]="ovo je neki primjer teksta";
	int niz[5]= {3,7,4,7,6};
	int d=provjeri_duzine(string, niz, 5);
	printf("%d", d);
	return 0;
}
