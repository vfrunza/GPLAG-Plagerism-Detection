#include <stdio.h>

int  provjeri_duzine( char* s,int niz1[],int broj)

{

	int d=0;
	int i =0;
	int brojac=0;

	int slovo=1;
	int broj_rijeci=0;
	while(*s!='\0') {
		if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z') ) {




			s++;
			brojac++;
			if(slovo==1) broj_rijeci++;
			slovo=0;

		}

		else {
			if(brojac!=niz1[i]) return 0;
			s++;
			brojac=0;
			i++;
			slovo=1;
		}

	}
	if(broj_rijeci!=broj) return 0;
	return 1;


	return 1;
}

int main()
{

	char tekst[1000]=". Ovo je neki primjer teksta";
	int niz[]= {0,3,2,4,7,6};
	printf("%d: ",provjeri_duzine(tekst,niz,5));

	return 0;
}
