#include <stdio.h>


int provjeri_duzine(char *s, int niz[], int broj){
	int i,duzina_rijeci,broj_rijeci;
	broj_rijeci=0;
	i=0;
	while(*s<'A' || (*s>'Z' && *s<'a') || *s>'z'){
		s++;
	}
	while(*s!='\0'){
		duzina_rijeci=0;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			duzina_rijeci++;
			s++;
		}
		if(duzina_rijeci!=niz[i]){
			return 0;
		}
		broj_rijeci++;
		if(*s=='\0') break;
		
		i++;
		s++;
		while((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && *s!='\0'){
			s++;
			
		}
		
	}
	if(broj!=broj_rijeci) return 0;
	return 1;
}
int main() {
	char string[30]="Ovo je neki primjer teksta";
	int niz[5]={3,2,4,7,10};
	int vrijednost;
	vrijednost=provjeri_duzine(string,niz,5);
	printf("Konacna vrijednost je: %d", vrijednost);
	return 0;
}
