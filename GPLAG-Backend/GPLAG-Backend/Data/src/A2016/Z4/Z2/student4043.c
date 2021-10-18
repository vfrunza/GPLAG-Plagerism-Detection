#include <stdio.h>

char* kodiraj(char *tekst, char *tablica) {
	char *pocetak=tekst,*poc=tablica;
	int i,max=0;
	int hist[127]={0};
	while(*tekst!='\0') {
		hist[*tekst]++;
		tekst++;
	}
	
	/*trazim znak koji se najvise ponavlja*/
	
	for(i=32;i<=126;i++) {
		if(max<hist[i]) max=hist[i];
	}
	
	/*redam znakove po broju ponavljanja*/
	
	while(max!=0) {
		for(i=32;i<=126;i++) {
			if(hist[i]==max) {
				*tablica=i;
				tablica++;
			}
		}
		max--;
	}
	
	/*redam ostale znakove po ASCII tabeli*/
	
	for(i=32;i<=126;i++) {
		if(hist[i]==0) {
			*tablica=i;
			tablica++;
		}
	}
	tablica++;
	*tablica='\0';
	tekst=pocetak;
	tablica=poc;
	
	/*kodiranje teksta*/
	
	while(*tekst!='\0') {
		for(i=0;i<96;i++) {
			if(*tekst==tablica[i]) {
				*tekst=126-i;
				break;
			}
		}
		tekst++;
	}
	tekst=pocetak;
	return tekst;
}

char* dekodiraj(char *tekst, char *tablica) {
	char *pocetak=tekst;
	int i;
	while(*tekst!='\0') {
		for(i=0;i<96;i++) {
			if(*tekst==126-i) {
				*tekst=tablica[i];
				break;
			}
		}
		tekst++;
	}
	tekst=pocetak;
	return tekst;
}
int main() {
	
	/*printf("Zadaća 4, Zadatak 2");*/
	return 0;
}
