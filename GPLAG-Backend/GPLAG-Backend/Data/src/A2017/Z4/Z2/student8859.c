#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	if(znak=='\n') znak = getchar();
	int i=0;
	while (i<velicina-1 && znak != '\n'){
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int duzina_rijeci[], int vel){
	char* pom=s;
	int duz_rijeci=0, broj_rijeci=0;
	
	
	while(*s!='\0'){
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			duz_rijeci++;
			if(*(s+1)=='\0') broj_rijeci++;
		}
			else if(duz_rijeci>0){
				broj_rijeci++;
				duz_rijeci=0;
			}
			
		if(broj_rijeci>vel) return 0;
		
		s++;
	}
	
	s=pom;
	if(broj_rijeci!=vel)return 0;
	broj_rijeci=0;
	duz_rijeci=0;
	while(*s!='\0'){
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			duz_rijeci++;
			if(*(s+1)=='\0') broj_rijeci++;
			
		}
			else if(duz_rijeci>0){
				if(duz_rijeci!=duzina_rijeci[broj_rijeci]) return 0;
				broj_rijeci++;
				duz_rijeci=0;
			}
		
		s++;
	}
	return 1;
}
int main() {
	char recenica[1000];
	int duzina_rijeci[1000], vel;
	return 0;
}
