#include <stdio.h>

int provjeri_duzine(char* s, int niz1[], int velicina) {
	char* p=s;
	int brojac;
	int i=0;
	int provjera=0;
	
	while(*p!='\0') {
		while(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) p++;
		brojac=0;
		while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
			brojac++;
			p++;
		}
		if(brojac==niz1[i]) provjera=1;
		else {
			break;
			provjera=0;
		};
		i++;
	}
	if(i!=velicina) provjera=0;
	return provjera;
}

int main() {
	char tekst[] = "Neko.vrlo`nepismen'je_otkucao~ov@j{tekst";
	int niz[] = {4,4,8,2,7,2,1,5};
	int niz2[] = {4,12,2,7,2,1,5};
	int niz3[] = {4,4,8,2,7,4,5};

	printf("%d ", provjeri_duzine(tekst, niz, 8));
	printf("%d ", provjeri_duzine(tekst, niz2, 7));
	printf("%d", provjeri_duzine(tekst, niz3, 7));

	return 0;
}
