#include <stdio.h>
#define DEBUG 0

char veliko(char x) {
	if (x>='a' && x<='z') return x-32;
	return x;
}

const char* daj_zatvarajuci(const char* s) {
	const char* pocetak = s;
	if (*s == '<') {
		if (*(s+1) == '>') {
			if (DEBUG) printf("<> nije validno %s\n", pocetak);
			return 0;
		}
		/* Prvo nalazimo kraj taga */
		while (*s != '>' && *s != '\0') s++;
		if (*s == '\0') {
			if (DEBUG) printf("Tag se nikada ne zavrsava %s\n", pocetak);
			return 0;
		}
		s++;
	}
	
	/* Trazimo sljedeci tag */
	while (*s != '\0') {
		if (*s == '>') {
			if (DEBUG) printf("Invalidan > na lokaciji %s\n", s);
			return 0;
		}
		
		/* Pronadjen novi otvarajuci tag */
		if (*s == '<' && *(s+1) != '/') {
			s = daj_zatvarajuci(s);
			if (s==0) return 0;
			
		} else if (*s == '<') break;
		
		s++;
	}
	
	/* Prvi poziv funkcije */
	if (*pocetak != '<') {
		if (*s == '\0') return s; /* Sve ok */
		
		if (DEBUG) printf("Prvi tag u stringu je zatvarajuci %s\n", s);
		return 0;
	}

	/* Jedina preostala mogucnost je da smo naisli na zatvarajuci tag */
	/* Provjeravamo da li je odgovarajuceg tipa */
	
	const char* tmp = pocetak+1;
	s += 2;
	while (veliko(*s) == veliko(*tmp) && *s != '>' && *s != ' ' && *s != '\0') { s++; tmp++; }
	
	/* Preskacemo razmake u zatvarajucem tagu (koji su dozvoljeni) */
	while (*s == ' ') s++;
	
	if (*s == '\0') {
		if (DEBUG) printf("Zatvarajuci tag se nikada ne zavrsava %s\n", pocetak);
		return 0;
	}
	/* Zatvarajuci pronadjen */
	if ((*tmp == ' ' || *tmp == '>') && *s == '>') return s;
	
	if (DEBUG) printf("Nije odgovarajuci zatvarajuci tag %s\n", pocetak);
	return 0;
}

int provjeri(const char* tekst) {
	while (*tekst != '\0') {
		tekst = daj_zatvarajuci(tekst);
		if (tekst == 0) return 0;
		if (*tekst == '>') tekst++;
	}
	return 1;
}

int main() {
	printf ("Provjera  7: %d\n", provjeri("<p>razmak prije p a poslije / </ p>"));
	printf ("Provjera  8: %d\n", provjeri("<p   >a ovo je ipak validno, razmaci NAKON p</p>"));
	printf ("Provjera  9: %d\n", provjeri("<p   >i ovo je validno, razmaci NAKON p</p    >"));
	printf ("Provjera 10: %d\n", provjeri("<></>")); /* nije validno */
	printf ("Provjera 11: %d\n", provjeri("")); /* ok */
	printf ("Provjera 12: %d\n", provjeri("                                            ")); /* ok */
	printf ("Provjera 13: %d\n", provjeri("< p> razmak prije p i prije / p, sto nije ispravno!  </ p>"));
		
	return 0;
}
