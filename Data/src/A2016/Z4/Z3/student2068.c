#include <stdio.h>

char *zamijeni(char *tekst, char *rijec) {
	/* Naci cemo duzine rijeci koju treba zamijeniti i rijeci kojom je mijenjamo da bismo mogli napraviti tacno onoliko mjesta koliko treba
	   za zamjensku rijec. Ako su duzine iste nema potrebe za mijenjanjem iceg */ 
	
	int duz_rijeci=0, duz_zamjene=0;
	char *temp=tekst, *kraj_teksta=NULL;
	while(*(tekst+duz_rijeci)!=' ' && *(tekst+duz_rijeci)) duz_rijeci++;
	while(*(rijec+duz_zamjene)) duz_zamjene++;
	
	if(duz_zamjene==duz_rijeci) {
		while(*rijec) {
			*tekst=*rijec;
			tekst++; rijec++;
		}
	}
	else if(duz_zamjene>duz_rijeci) {
		
		while(*tekst) tekst++;
		kraj_teksta=tekst;
		kraj_teksta+=duz_zamjene-duz_rijeci;
		tekst=temp;
		
		while(kraj_teksta>= tekst+duz_zamjene) {
			*kraj_teksta=*(kraj_teksta-(duz_zamjene-duz_rijeci));
			kraj_teksta--;
		}
		
		while(*rijec) {
			*tekst=*rijec;
			tekst++; rijec++;
		}
	}
	
	else if(duz_rijeci>duz_zamjene) {
		while(*(tekst+duz_rijeci-duz_zamjene)) {
			*tekst=*(tekst+duz_rijeci-duz_zamjene);
			tekst++;
		}
		*tekst=*(tekst+duz_rijeci-duz_zamjene);
		
		tekst=temp;
		
		while(*rijec) {
			*tekst=*rijec;
			tekst++; rijec++;
		}
	}
	/* Funkcija vraca pointer na clan iza zadnjeg clana rijeci da bismo mogli nastaviti sa trazenjem sljedece rijeci */
	return tekst;
}

int daLiSuIste(char *tekst, char *rijec) {
	/* Ova funkcija provjerava da li su dvije rijeci iste i vraca 1 ako jesu i 0 ako nisu */
	while(*tekst!=' ' && *tekst && *rijec) {
		if(*tekst!=*rijec) return 0;
		tekst++; rijec++;
	}
	if(( *tekst==' ' || *tekst=='\0') && *rijec=='\0') return 1;
	return 0;
}


char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci) {
	char *temp=tekst;
	int i;
	while(*tekst) {
		while(*tekst==' '&& *tekst) tekst++; /* Idemo kroz string dok ne naidjemo na pocetak rijeci */
		if(!*tekst) return temp;
		for(i=0; i<broj_rijeci; i++) {  /* Za nadjenu rijec provjeravamo da li je ista kao neka od rijeci koje se mijenjaju */
			if(daLiSuIste(tekst, *(rijeci+i))) {
				tekst=zamijeni(tekst, *(zamjene+i));
				break;
			}
		}
		/* Ako rijec nije jednaka nijednoj od datih rijeci, shiftamo pointer na clan iza kraja rijeci da mozemo nastaviti sa pretragom */ 
		if(i==broj_rijeci && *tekst) {
			while(*tekst && *tekst!=' ') tekst++;
		}
	}
	return temp;
}

int main() {
	char* rijeci[2] = { "par", "stop" };
	char* zamjene[2] = { "", "start" };
	char tekst[100] = "par par par stop";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
