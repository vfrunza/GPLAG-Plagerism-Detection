#include <stdio.h>

int jednakaSlova(char a, char b){
	if(a >= 'A' && a <= 'Z') a += 32;
	if(b >= 'A' && b <= 'Z') b += 32;
	
	return a == b;
}

void najduzi_bp(char* s1, char* s2){
	char *s, *p, *r;
	s = p = r = s1;
	//Za s2 string
	char *s2p, *s2k; //s2pocetak, s2kraj
	s2p = s2k = s2;
	
	int len = 0, maxlen = 0, ponovioSe;
	
	while(*s != '\0'){
		
		if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
			//p postaje trenutno slovo
			p = s;
			//Duzina podniza je 1
			len = 1;
			//Predji na sljedeci karakter
			s++;
			
			//Prodji kroz slova
			while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
				//Pregledati je li se do sada ponovilo trenutno *s slovo
				r = p;
				//Budimo fini i pretpostavimo da nije
				ponovioSe = 0;
				
				//Prodjemo kroz dosadasnja slova podstringa
				while(r < s){
					//Ako se ponovilo, prekidamo potragu
					if(jednakaSlova(*r, *s)){
						ponovioSe = 1;
						break;
					}
					r++;
				}
				//Ako se ponovio, nasli smo podstring
				if(ponovioSe) break;
				
				len++;
				s++;
			}
			
			//Ako je nadjeni podstring duzi od vec nadjenog, upisi ga u s2
			if(len > maxlen){
				s2p = s2;
				s2k = p;
				
				//Moguce da izlazi iz niza???
				while(s2k < s){
					*s2p = *s2k;
					s2p++;
					s2k++;
				}
				*s2p = '\0';
				//Sada je on najduzi
				maxlen = len;
			}
			
			//Vrati s na pocetno slovo p, da bi se moglo provjeravati za sljedeci karakter u stringu
			s = p;
		}
		
		//Mozda izlazi iz niza???
		
		s++;
	}
	
}

int main() {
	
	char niz[10];
	niz[0] = '\0';
    najduzi_bp ("   aba   ", niz);
    printf ("Niz: '%s'", niz);
	
	return 0;
}