                         -------> ZADACI ZA SAMOSTALAN RAD I ROKOVI <-------
                
ZSR9                         
posljednja rijec unutar stringa

char *PosljednjaRijec(char *s){
	while(s!='\0'){
 	char *pocetak;
 	
		if(*s==' '){
		while(*s==' ')
		s++;
		}
		pocetak=s;
		
		// posaljemo pokazivac na kraj stringa 
		int razmak=0;
		while(*s!='\0'){
			if(*s==' '){
				razmak=1;
			}
			s++;
		}
		
			s--; 

		if(razmak==1){ 
			char *pomocni=s;
			
			if(*pomocni=='!'){
			*pomocni='\0';
			
			}
			
			char *kraj;
			s--;
			
			if(*s==' '){ // zbog razmaka ispred kraja stringa:  _ _ \0
				while(*s==' ')
				s--;
				
			kraj=s+1;
			*kraj='\0';
			}
		
			
			while(*s!=' '){
				s--;
			}
			if(*s==' ')
			s++;
			
			return s;
		}
		else{
			if(*s=='!')
			*s='\0';
			
			
			while(s>pocetak){
				s--;
			}
			return s;
		}
	
		}

		s++;
	}
	

kapitaliziraj-fja koja pretvara prvo slovo svake rijeci u veliko

char *Kapitaliziraj(char*s){
	char *pok=s;
	int prvi_put=1;
	while(*s!='\0'){
		
		
		while(*s==' ')
		s++;
		
		// ako je prvo slovo veliko, uci ce nam i drugo pretvorit u veliko
		if(*s>='a' && *s<='z'){
			if(prvi_put){
			*s-=32;
			prvi_put=0;
			s++;
			}
			
			while(*s!=' ' && *s!='\0')
			s++;
		}
		else if(*s>='A' && *s<='Z'){
			prvi_put=0;
			s++;
			
			while(*s!=' ' && *s!='\0')
			s++;
		}
		
		if(*s==' ' && *s!='\0'){
			while(*s==' ' && *s!='\0'){
				s++;
			}
			if(*s!=' ' && *s!='\0'){
				prvi_put=1;
				s--;
			}
		}
		
		if(*s=='\0')
		s--;
	
		
		s++;
	}
	return pok;
	
}

napomena:
Zadatak-da se izvrsi zamjena postojece rijeci u stringu sa onom koju zadajemo da bude nova rijec-ZSR.10(ZAD.6)

Zadatak-izbacivanje maksimalnog broja iz stringa je u ZSR.10(zad.11)

 
 
 
 
 
           --------------------------------> STRUKTURE <-----------------------------------
           
           
ZADATAK SA ZAVRSNOG:-uradjen na ZSR-13 (ZAD 3)

struct Grad {          struct Drzava {               struct Regija {
char naziv[20];         char naziv[50];               char naziv[50];
int br_stanovnika;       struct Grad glavni;}         struct Grad glavni;}
};

da se napise fja koja prima niz drzava i izbacuje sone sa istim gl.gradom kao regija, one koje pocinju sa slovom 
Z, te one ciji glavni grad ima manje od 10 000 stanovnika



ZADATAK STRUKTURA-TOP-STUDENT-ISPIT-5-URADJENO

ZADATAK STRUKTURA-GENIJALCI-dase izbace studenti iz niza ciji prosjek je manji od unesenog-ZSR-11(ZAD 11)
