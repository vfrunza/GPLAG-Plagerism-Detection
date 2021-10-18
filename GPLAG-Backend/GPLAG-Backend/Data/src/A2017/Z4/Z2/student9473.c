#include <stdio.h>

int prebroji_slova(char *p,char *q){
	int brojac=0;
	while(p<q){
		brojac++;
		p++;
	}
	return brojac;
}
int prebroji_rijeci(char *p){
	int brojac=0,razmak=1;
	while(*p!='\0'){
		if(!((*p>='A'  && *p<='Z') || (*p>='a' && *p<='z'))) razmak=1;
		else if(razmak==1){
			razmak=0;
			brojac++;
		}
		p++;
	}
	return brojac;
}

int provjeri_duzine(char *s,int niz[],int vel){
	char *pocetak=s;
	char *kraj=s;
	char *tmp=s;
	int broj_slova=0,i=0,broj_rije=0;
   broj_rije=prebroji_rijeci(tmp);
	while(*s!='\0'){
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			while((!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) && *s!='\0') s++;
		}
		pocetak=s;
		while(((*s>='A' && *s<='Z') ||(*s>='a' && *s<='z')) && *s!='\0') s++;
		kraj=s;
		broj_slova=prebroji_slova(pocetak,kraj);
		if(*pocetak==*kraj) break;
		if(broj_slova!=niz[i]) return 0;
		else {
		if(i<vel) i++;
		}
	if(*s!='\0') s++;
	}
	if(broj_rije==vel) return 1;
	else return 0;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
