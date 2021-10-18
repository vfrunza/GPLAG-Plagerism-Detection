#include <stdio.h>

int provjeri_duzine(char* recenica, int niz[], int velicina) {
	char* p1=recenica;
	char* p2=recenica;
	int rijeci=0, razmak, broj=0, i=0;
	
	while(*p1!='\0') {
		/*Provjera da li je velicina niza jednaka broju rijeci u recenici*/
		while( (*p1<'A' || (*p1>'Z' && *p1<'a') || *p1>'z' ) && *p1!='\0') p1++;
		if(*p1=='\0') break;
		while( ( (*p1>='A' && *p1<='Z') || (*p1>='a' && *p1<='z') ) && *p1!='\0' ) {
			p1++;
		}
		rijeci++;
	}
	if(rijeci!=velicina) return 0;
	
	while(*p2!='\0') {
		razmak=0;
		if( (*p2<'A' || (*p2>'Z' && *p2<'a') || *p2>'z') && *p2!='\0') {
			if(*p2=='\0') break;
			razmak=1;
		} else if (razmak==0){
			broj=0;
			while( ( (*p2>='A' && *p2<='Z') || (*p2>='a' && *p2<='z') ) && *p2!='\0' ) {
				broj++;
				p2++;
			}
			if(niz[i]==broj) i++;
			else return 0;
		}
		p2++;
	}
	
	return 1;
}

int main() {
	
	/*printf("Zadaća 4, Zadatak 2");*/
	return 0;
}
