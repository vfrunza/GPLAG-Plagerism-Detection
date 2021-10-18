#include <stdio.h>
int provjeri(char* s) {
	char niz[10000];
	char* openTags = niz;
	int velicina = 0;
	char *zatvoreniTag = s;
	char *otvoreniTag = s;
	*openTags = '+';   // Kao delimiter tagova u nizu koristit cu znak "+" 
	openTags++;
	while(*s!='\0') {
		// Trazim otvoreni tag
		if(*s=='<') {
			s++; // Gledam sta je iza znaka "<"
			// Spremam ime otvorenog taga u niz tagova
			if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				otvoreniTag = s;
				while(*otvoreniTag!=' ' && *otvoreniTag!='>') {
					if(*otvoreniTag=='\0')
						return 0;
					// Pretvaram sve u mala slova..
					if(*otvoreniTag>='a' && *otvoreniTag<='z') 
						*openTags++ = *otvoreniTag++; 
					else	
						*openTags++ = *otvoreniTag++ + 32;
					//
					velicina++; // Velicina niza otvorenih tagova
				}
				*openTags = '+'; // Stavljam tacku kao granicu izmedju otvorenih tagova
				openTags++;  // U slucaju da ne pregazi '+' ako ponovo naidje na otvoren tag
			} 
			
			 // Ako je zatvoreni tag,onda ga uporedjujem sa prethodnim otvorenim
			 
			else if(*s=='/') {
				if(openTags==niz)
					return 0; // U slucaju ako string pocinje zatvarajucim tagom
				zatvoreniTag = s+1;
				while(*zatvoreniTag!=' ' && *zatvoreniTag!='>') {
					if(*zatvoreniTag=='\0') // Dosao do kraja stringa,odnosno nije pravilno zatvoren tag
						return 0; 
					zatvoreniTag++;
				}
				zatvoreniTag--; // Moram vratiti jedno mjesto unazad zbog "space" ili ">"
				
				openTags-=2; // Sada pointer niza pokazuje jedno mjesto prije plusa i ici ce do prethodnog plusa ili eventualno pocetka niza
				if(openTags<niz) // U slucaju da je niz prazan a naidjemo na zatvoreni tag
				 	return 0;
				while(*openTags!='+' && openTags!=niz) {  // Provjeri da li zatvoreni tag odgovara zadnjem otvorenom
					if(*zatvoreniTag==*openTags || *zatvoreniTag==*openTags -32 ){ // Kratkospojna evaluacija osigurava i mala i velika slova
						zatvoreniTag--;
						openTags--;
						velicina--; // Ako su tagovi uredu onda smanji broj tagova (zapravo "brise" karakter po karakter)
					}
					else
						return 0;
				}
				openTags++;
				s++;
			} 
			// Ako nije ni otvoreni ni zatvoreni onda je pogresan...
			else
				return 0;
		}
		else
			s++;
	}
	if(velicina>0) // Ako je ostalo nezatvorenih tagova
		return 0;
	return 1;
}
int main() {
	return 0;
}
