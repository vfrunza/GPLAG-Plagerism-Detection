#include <stdio.h>

int broj_slova(char* s){
	int brojac=0;
	while(*s!='\0'){
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) brojac++;
		s++;
	}
	return brojac;
}

int provjeri_duzine(char *s, int niz[], int velicina){
	int i=0, slova=0, suma=0, brojac=0;
	for(i=0; i<velicina; i++){
		suma+=niz[i];
	}
	i=0;
	slova=broj_slova(s);
	if(slova==suma){
		while(*s!='\0' && i<velicina){
			brojac=0;
			if(niz[i]==0) return 0;
			if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
				while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
					brojac++;
					s++;
				}
				if(brojac!=niz[i]) return 0;
				i++;
				if(*s=='\0') break;
			}
			s++;
		}
		return 1;
	}
	else return 0;
}

int main() {
char tekst[] = "...i tako smo dosli do petog testa";
int niz[] = {1,4,3,5,2,5,5};
int niz2[] = {4,4,3,5,2,5,5};
int niz3[] = {0,1,4,3,5,2,5,5};

printf("%d ", provjeri_duzine(tekst, niz3, 8));
printf("%d ", provjeri_duzine(tekst, niz2, 7));
printf("%d ", provjeri_duzine(tekst, niz, 7));
	return 0;
}
