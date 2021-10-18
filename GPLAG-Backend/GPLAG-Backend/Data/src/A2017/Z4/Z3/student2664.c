#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

void najduzi_bp (char *s1, char *s2){
	char *pocetak_najduze = s1;
	char *kraj_najduze = s1;
	char *poc_naj2 = s1;
	char *kraj_naj2 = s1;
	char *pocetak_max = s1;
	char *kraj_max = s1;
	int brojac = 0;
	int brojac2 = 0 ;
	
	
	char *pocetak_novog = s2;
	
	while(*s1 != '\0'){
		if((*s1 >= 'A' && *s1 <= 'Z') || (*s1 >= 'a' && *s1 <= 'z')){
			pocetak_najduze = s1;
			kraj_najduze = s1;
			while(*pocetak_najduze != ' '){
				s1++;
				brojac++;
			} s1--;
			kraj_najduze = s1; 
			s1++;
			poc_naj2 = s1;
			while(*poc_naj2 != ' ' ){
				s1++;
				brojac2++;
			}
			s1--;
			kraj_naj2 = s1;
			if ( brojac2 > brojac) {
				pocetak_max = poc_naj2;
				kraj_max = kraj_naj2;
			}
		}
		s1++;
	}
	
	while(pocetak_max < kraj_max){
		*pocetak_max++ = *s2++;
	} *s2 = '\0';
	
	s2 = pocetak_novog;
}


int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
