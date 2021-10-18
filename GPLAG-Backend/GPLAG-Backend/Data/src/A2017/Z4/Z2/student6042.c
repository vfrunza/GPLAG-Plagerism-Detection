#include <stdio.h>

int broj_rijeci(char *s){
	int brojac=0;
	if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) brojac++;
	while(*s!='\0'){
		if((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && ((*(s+1)>='A' && *(s+1)<='Z') || (*(s+1)>='a' && *(s+1)<='z'))) brojac++;
		s++;
	}
	return brojac;
}

int provjeri_duzine(char *s, int niz[], int velicina){
	int brojac=0, i=0, rijeci=broj_rijeci(s);
	char *kraj=s;
	if(rijeci!=velicina) return 0;
	while(*kraj!='\0') kraj++;
	while(*kraj<'A' || (*kraj>'Z' && *kraj<'a') || *kraj>'z') kraj--;
	*++kraj='\0';
	
	while(*s!='\0'){
		while(*s<'A' || (*s>'Z' && *s<'a') || *s>'z'){
			s++;
			if(*s=='\0') goto nastavi;
		}
		
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			brojac++;
			s++;
		}
		nastavi:
		if(brojac!=niz[i++]) return 0;
		if(*s=='\0') continue;
		s++;
		brojac=0;
	}
	return 1;
}

int main() {

char tekst[] = "Kakav je ovo test!?!?";
int niz[] = {5,2,3,4};
int niz2[] = {5,2,3,8};
int niz3[] = {5,2,3,4,0};


printf("%d ", provjeri_duzine(tekst, niz, 4));

	return 0;
}
