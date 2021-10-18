#include <stdio.h>

int duzina_stringa(char * s) {
	int vel = 0;
	while(*s++ != '\0') vel++;
	return vel; //vraca duzinu stringa
}


void kopiraj_string(char * to, char * from) {
	while (*from != '\0') *to++ = *from++;     //"from" se kopira u "to"
	*to = '\0';
}

/*param char c => slovo koje ispitujemo*/

int slovo(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * funkcija provjerava da li su dva slova ista, zanemaruje razliku izmedju
 * 	velikih i malih slova */
 
int ista_slova(char c1, char c2) {
	if (! slovo(c1) || ! slovo(c2)) return -1; // ako jedan od param. nije slovo vraca -1
	
	if (c1 == c2) return 1;   // ako su slova ista 
	
	if (c1 >= 'a' && c1 <= 'z' && c1 - 32 == c2) return 1;   
	
	if (c1 >= 'A' && c1 <= 'Z' && c1 + 32 == c2) return 1;    
	
	return 0;
}

/**
 * @param char * s string koji se provjerava
 * @return int | bool 1 (true) ako ima ponavljanja, u suprotnom 0 (false)
 * 		vraca 2 ako se zadnji znak iz stringa ponavlja
 */
int ima_ponavljanja(char * s) {
	int tacno = 0;
	char * p, *kraj = s;
	while (*kraj != '\0') kraj++;
	
	kraj--; // postavili na kraj 
	while (! tacno && *s != '\0') {
		p = s;
		p++; 
		while (*p != '\0') {
			if (ista_slova(*p, *s)) {
		
				if (ista_slova(*s, *kraj)) { //ako se zadnji znak iz stringa ponavlja vraca 2
					tacno = 2;
					break;
				}
				tacno = 1; // ako se ponavlja bilo koji vraca 1
				break;
			}
			p++;
		}
		s++;
	}
	return tacno; // nema ponavljanja
}



char * uzmi_rijec(char * tekst, char * output) {  // iz tekst uzimam sljedecu rijec
	while (! slovo(*tekst) && *tekst != '\0') tekst++;
    while (*tekst != '\0' && slovo(*tekst)) {
    	*output++ = *tekst++; // u output upisujem rijec iz tekst
    }
    *output = '\0'; //nulterminiram string
    return tekst;
}

/**
 * funkcija izbacuje zadnje slovo(znak) iz proslijedjenog stringa
 * @param char * s 
 * @return void
 */
void izbaci_zadnje(char * s) {
	while (*(s++) != '\0');
	s--; // s doveli na kraj i upisali \0 preko zadnjeg slova
	*--s = '\0';
}

void izbaci_prvo(char * s) {
	char * p = s;
	while (*++p != '\0') *s++ = *p; // pomjeram p  i upisem *s na p
	*s = '\0'; // nulterminiram
}

/*char * s1 string koji pretrazujemo
 char * s2 string u koji upisujemo najduzi podstring
 */
void najduzi_bp(char * s1, char * s2) {   
	char podnizovi[100][100]; //matrica
	int i = 0, j = 0, temp;
	*s2 = '\0'; //prazan drugi string, da se obezbijedim
	while (*(s1 = uzmi_rijec(s1, podnizovi[i++])) != '\0');  // iz s1 upisujem rijeci u matricu ; sve dok *s1 sa pocetka neke rijeci != od \0
	
	for (j = 0; j < i; j++) {
		if ((temp = ima_ponavljanja(podnizovi[j]))) {    // ako u rijeci podnizovi[j] ima ponavljanja 
			
			if (temp == 2) { izbaci_zadnje(podnizovi[j]); }
			else izbaci_prvo(podnizovi[j]); 
		
		
			j--;
		} else if (duzina_stringa(podnizovi[j]) > duzina_stringa(s2)) {
			kopiraj_string(s2, podnizovi[j]);  
		}
	}
		
}

int main() {
	 char niz[10];
        najduzi_bp ("Ovo", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}

