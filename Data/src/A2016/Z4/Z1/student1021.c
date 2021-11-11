#include <stdio.h>
	
	/* Funkcija koja ispituje da li je karakter koji joj je poslan slovo ili ne (uvedena zbog skracenja duzine if uslova u kodu) */
	int if_slovo (char c) {
		if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
			return 1;
		}
		return 0;
	}
	
	/* Bibliotecna funkcija toupper (string.h), koja vraca veliko slovo bez obzira da li joj se posalje veliko ili malo slovo */
	char touper (char c) {
		if (c>='a' && c<='z') {
			return c-('a'-'A');
		}
		return c;
	}
	
	/* Funkcija koja ispituje koliko se puta rijeci pojavljuju u stringu */ 
	int broj_pojavljivanja (char *s, char *pocetak, char *kraj) {
		char *p=s, *q;
		int brojac=0;
		while (*p!='\0') {
			q=pocetak;
			if (touper(*p)==touper(*q) && (p==s || if_slovo(*(p-1))==0)) {
				while (touper(*p)==touper(*q) && q!=kraj && *p!='\0') { 
					p++; q++;
				}
				if (q==kraj && if_slovo(*p)==0) { 
					brojac++;
				}
			} else {
				p++;
			}
			
		}
		return brojac;
	}
	
	/* Pomocna funkcija za izbacivanje rijeci iz stringa */
	void izbacivanje_rijeci (char *s, char *pocetak, char *kraj) {
		char *p=s;
		char *q, *citaj, *pisi;
		while (*p!='\0') {
			q=pocetak;
			if (touper(*p)==touper(*q) && (p==s || if_slovo(*(p-1))==0)) {
				pisi=p;
				while (touper(*p)==touper(*q) && q!=kraj) {
					p++; 
					q++;
				}
				if (q==kraj && if_slovo(*p)==0) {
					citaj=p;
					while (*citaj!='\0') {
						*pisi++=*citaj++;
					}
					*pisi='\0';
					p=p-(citaj-pisi);
				}
			}
			else {
				p++;
			}
		}
	}
	
	/* Funkcija koja izbacuje rijec koja se pojavljuje najvise puta u unesenom tekstu */
	char *izbaci_najcescu (char *s) {
		char *pocetak_trenutne, *kraj_trenutne, *p, *pocetak_max, *kraj_max, *pisi, *citaj;
		int br, max=0, pretpostavka=0;
		p=s;
		if (*p=='\0') {
			return 0;
		}
		while (*p!='\0') {
			if (if_slovo(*p)==1) {
				pretpostavka=1;
				pocetak_trenutne=p;
				while (if_slovo(*p)==1) { 
					p++; 
				}
				kraj_trenutne=p;
				br=broj_pojavljivanja(s, pocetak_trenutne, kraj_trenutne);
				if (br>max) {
					max=br;
					pocetak_max=pocetak_trenutne;
					kraj_max=kraj_trenutne;
				}
			}
			else {
				p++;
			}
		}
		
		if (pretpostavka==1) {
			izbacivanje_rijeci(kraj_max, pocetak_max, kraj_max);
			pisi=pocetak_max;
			citaj=kraj_max;
			while (*citaj!='\0') {
				*pisi++=*citaj++;
			}
			*pisi='\0';
		}
		return s;
	}
	
	int main () {
		
		return 0;
	}