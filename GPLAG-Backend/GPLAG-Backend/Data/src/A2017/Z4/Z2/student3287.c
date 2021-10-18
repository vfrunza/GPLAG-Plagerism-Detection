#include <stdio.h>

int JeLiSlovo (char znak){
    
    return ((znak >= 'A' && znak <= 'Z') || ( znak >= 'a' && znak <= 'z'));
    
}

// provjeravamo duzinu naseg stringa, modifikovana funkcija tako, da ce da mjeri duzinu do prvog razmaka, odnosno
//do prvog znaka koji nije slovo, za sta koristimo pozivanje gornje funkcije

int duzina (char *string){
	int duzina = 0;
	while(*string != '\0' && JeLiSlovo(*string)){
		duzina ++;
		string++;
	}
	return duzina;
}



int provjeri_duzine(char* tekst, int niz[], int velicina){
		int DuzinaRijeci , brojac = 0, BrojacRijeci = 0;
		char *p = tekst;
		char *q = tekst;
		char *s = tekst;
		
		// najprije prolazimo kroz string i brojimo rijeci 
		while(*s != '\0'){
			if(JeLiSlovo(*s)){
				while(*s != '\0' && JeLiSlovo(*s)){
					s++;
				}
				BrojacRijeci++;
				s--;
			}
			s++;
		}
		
		if (BrojacRijeci != velicina)return 0; // ako se broj rijeci ne poklapa sa velicinom niza, vracamo 0, ne provjeravamo dalje uslove
		
		// ako je broj rijeci jednak velicini niza, provjeravamo da li clanovi niza, respektivno odgovaraju velicini, pojedinacnih rijeci
		while (*p != '\0'){
			q = p;
			if (JeLiSlovo(*p)){
				while(*p != '\0' && JeLiSlovo(*p)){
					p++;
				}
				
				brojac++;
				
				DuzinaRijeci = duzina(q);
				if(DuzinaRijeci != niz[brojac - 1]) return 0; // neka jedan clan niza ne odgovara velicini jedne rijeci, vraca se nula
				p --;
		}
		
		p++;
	}
	return 1; // ako dodje do kraja, vraca se 1 
}


int main(){
	return 0;
}