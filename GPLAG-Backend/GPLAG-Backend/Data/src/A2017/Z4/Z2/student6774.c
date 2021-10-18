#include <stdio.h>

int provjeri_duzine(char niz[],int broj[],int brojrjeci){
	int istina=1;
	int brojac1=0;
	int brojac=0;
	char *pomocnipokazivac=niz;
	/*PROVJERAVA BROJ RJECI*/
		while(*niz!='\0'){
		while(!((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z')))
		{
			if(*niz=='\0')break;
			niz++;
			if(*niz=='\0')break;
		}	
		if((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z')){
			if(*niz=='\0')break;
			while((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z'))
			{
				if(*niz=='\0')break;
				niz++;
				if(*niz=='\0')break;
			}	
			brojac1++;
			if(*niz=='\0')break;
		}
	}
	
	if(brojac1!=brojrjeci)return 0;

	niz=pomocnipokazivac;
	while(*niz!='\0'){
		brojac=0;
		while(!((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z')))niz++;
		if((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z')){
			while((*niz>='A'&&*niz<='Z')||(*niz>='a'&&*niz<='z')){
				brojac++;
				niz++;
			}
		if(brojac!=*broj)return 0;	
		}
		broj++;
	}
	return istina;
}

int main() {
char tekst[] = "Ovo je neki primjer teksta";
int niz[] = {3, 2, 4, 7, 6};


printf("%d ", provjeri_duzine(tekst, niz, 5));
return 0;
}
