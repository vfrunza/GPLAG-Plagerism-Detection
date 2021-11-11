#include <stdio.h>

int rijeciString(char* s){                                                      /* funkcija koja vraca broj rijeci u 
																					posmatranom stringu */
	int karakter=1, brojRijeci=0;
	
	while(*s != '\0'){
		
		if(!((*s>='A' && *s <='Z') || (*s>= 'a' && *s <='z'))) karakter=1;
		else if(karakter){
			
			karakter=0;
			brojRijeci++;
		}
		
		s++;
	}
	return brojRijeci;
}

char* pocetakRijeci(char*s, int n){                                              /* funkcija koja vraca pokazivac na pocetak
																					rijeci */
	int brojac=0;
	int bul=1;
	
	while(*s != '\0'){
		if(!((*s>='A' && *s <='Z') || (*s>= 'a' && *s <='z'))) bul=1;
		else if(bul){
			bul=0;
			brojac++;
			if(brojac== n) return s;
		}
		s++;
	}
	return s;
}

char* krajRijeci(char* s){                                                       /* funkcija koja vraca pokazivac na kraj rijeci*/
	
	while((*s>= 'A' && *s <= 'Z') || (*s >= 'a' && *s <='z')) s++;
	return --s;
}

int slovo(char* s){																/* prolazimo kroz cijeli string i kada nadjemo
																					karakter koji ima ascii vrijednost malog ili*/
	int i=0;																	/*	velikog slova, povecamo i(brojac) za 1*/
	while((*s>='A' && *s<= 'Z') || (*s>='a' && *s <= 'z')){
		i++;
		s++;
	}
	return i;
}

int compare(char *prva, char* druga){											/* funkcija primi dvije rijeci i poredi ih,
                                                                                   vraca vrijednosti logicke istine/neistine*/	
	char* krajPrve= krajRijeci(prva);
	int bul=0;
	if(slovo(prva)==slovo(druga)){                                               /* preduslov da su jednake je da imaju isti
	                                                                             broj karaktera, tj slova */
		while(prva <= krajPrve){
			
			if(*prva == *druga ||*prva + 32 == *druga ||*prva == *druga +32){   /* case-sensitive */
				bul=1;
				prva++;
				druga++;
			}
			else return 0;     
		}
	}
	return bul;
}

char* najcescaLociraj(char* s){                                                 /* funkcija koja trazi rijec koja se ponavlja */ 
	int brojac=0, max = 0, i, j;												/*	najvise puta */
	char* pok=s;
	char *prva, *druga;
	int br= rijeciString(s);                                                    /* petlja ide do broj rijeci u stringu */
	
	for(i=1; i<=br; i++){														
		prva= pocetakRijeci(s,i);
		brojac=0;
		for(j=1; j<= br; j++){
			druga=pocetakRijeci(s,j);
			if(compare(prva,druga)==1) brojac++;
		}
		if (brojac>max){                                                        /* dio koda koji cuva najvecu vrijednost */
			pok=prva;
			max=brojac;
		}
	}
	
	return pok;
}

char* krajStringa(char* s){                                                     /* funkcija koja pokazivac prebacuje do kraja stringa */
	while(*s != '\0') s++;
	return s;
}

char* izbaci_najcescu(char* s){													/* trazena funkcija */
	
	char* najcesca = najcescaLociraj(s);                                       
	char* rijeci;
	int j, br, duzinaRijeci;
	char* krajstringa, *p, *pokazivac;
	
	krajstringa= krajStringa(s);
	br= rijeciString(s);
	
	for(j=1; j< br;j++){                                                         /* petlja ide od 1 do br, gdje je br - broj rijeci*/
		rijeci= pocetakRijeci(s,j);                                              /* u stringu */
		if(rijeci==najcesca){                                                         
			pokazivac = rijeci;
		}
		else if (compare(najcesca, rijeci))
		{
			duzinaRijeci=slovo(rijeci);
			p=rijeci;
			while( p<= krajstringa-duzinaRijeci){                               /* izbacivanje rijeci */
				*p=*(p+duzinaRijeci);
				p++;
			}
			j--;
		}
	}
	
	p=najcesca;
	duzinaRijeci=slovo(najcesca);
	
	while( p<= krajstringa-duzinaRijeci){                                         /* izbacivanje */
				*p=*(p+duzinaRijeci);
				p++;
			} 
			
		return s;
}

int main() {
	return 0;
}