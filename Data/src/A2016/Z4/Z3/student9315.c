#include <stdio.h>

char *zamjena_rijeci(char *tekst, char **rijeci, char** zamjene, int broj_rijeci);
int jeSlovo(char slovo);
void replace(char *rijec, char *zamjena);
void shrink(int x, char *tekst);

char *zamjena_rijeci(char *tekst, char **rijeci, char** zamjene, int broj_rijeci){
	char *ret = tekst;
	char *temp;
	char **find = rijeci;
	char **change = zamjene;
	int space = 1,i,j;
	char *s = tekst;
	int isti;
	//prolazimo kroz tekst i svaki put kad dodjemo do nove rijeci testiramo da li se nalazi u rijeci
	while(*s != '\0'){
		if(*s == ' '){
			space = 1;
		}
		else if(space){
			for(i = 0; i < broj_rijeci; i++){
				isti = 1;
				temp = s;
				j = 0;
				while(*s != ' ' && *s != '\0'){
					if(*s != *(*(find + i)+j)){
						isti = 0;
						break;
					}
					j++;
					s++;
				}
				s = temp;
				if(isti && *(*(find + i)+j) == '\0'){
					//ako su isti bili do razmaka ili kraja stringa i rijec u rijeci je dosla do svog kraja, tj. nije samo dio isti
					replace(s, *(change + i));
					s--;
					break;
				}
			}
			space = 0;
		}
		s++;
	}
	return ret;
}

int main() {
	return 0;
}

void replace(char *rijec, char *zamjena){
	char *startRijec = rijec;
	char *startZamjena = zamjena;
	int sizeR = 0;
	int sizeZ = 0;
	int korigSize;//potrebno korigovanje duzine stringa
	
	while(jeSlovo(*rijec++)){
		sizeR++;
	}
	while(jeSlovo(*zamjena++)){
		sizeZ++;
	}
	rijec = startRijec;
	zamjena = startZamjena;

	korigSize = sizeZ - sizeR;//ako je veca duzina zamjene moramo razvuci string, u suprotnom ga moramo suzit
	shrink(korigSize, rijec);

	while(jeSlovo(*zamjena)){
		*rijec++ = *zamjena;
		zamjena++;
	}
	rijec = startRijec;
	zamjena = startZamjena;
}

void shrink(int x, char *tekst){
	char *startTekst = tekst;
	char *temp;
	//razvlaci
	if(x > 0){
		while(*tekst++ != '\0');//idemo do kraja teksta
		
		while(x--){
			
			temp = tekst;
			while(tekst > startTekst + 1){
				*tekst = *(tekst - 1);
				tekst--;
			}
			tekst = temp + 1;
			
		}
	}
	//suzava
	else if(x < 0){
		x = -x;
		
		while(x--){
			
			temp = tekst;
			while(*tekst != '\0'){
				*tekst = *(tekst + 1);
				tekst++;
			}
			tekst = temp;
			
		}
	}
	
}
int jeSlovo(char slovo){
	//slovo je znak koji nije razmak ili null
	if(slovo != '\0' && slovo != ' ')
		return 1;
	return 0;
}