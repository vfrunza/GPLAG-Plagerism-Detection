#include <stdio.h>


/* Ispitujue da li je karakter medja */
int medja(char c) {
	return (c == 0 || c == 32);
}

/* Vraca duzinu stringa bez NUL karaktera */
int duzina(char *str) {
	int len = 0;
	
	while (*(str + len) != 0) len++;
	
	return len;
}

/* Poredi dvije rijeci */
int uporedi(char *s1, char *s2, int len) {
	int i = 0;
	
	while(i < len) {
		if (*(s1 + i) != *(s2 + i)) return 0;
		i++;
	}
	
	return 1;
}

/* Vraca broj pojavljivanja rijeci u tekstu */
int broj(char *tekst, char *rijec, int len1) {
	int br = 0, len2 = 0, cond = 1;
	
	while (cond) {
		if (!medja(*tekst)) {
			len2++;
		} else {
			if (len2 != 0) { /* Rijec zavrsava */
				if (len1 == len2) {
					br += uporedi(rijec, tekst - len1, len1);
				}
			}
			len2 = 0;
		}
		if (*tekst == 0) cond = 0;
		tekst++;
	}
	
	return br;
}

/* Mijenja dva stringa */
void zamijeni_dvije(char *rijec, char *zamjena, int len) {
	int i = 0;
	
	*rijec = *rijec;
	
	while (i < len) {
		*(rijec + i) = *(zamjena + i);
		i++;
	}
	
} 

/* Mijenja sve instance rijeci za kracu rijec (moze i rijec jednake duzine) */
char *zamijeniZaKracu(char *tekst, char *rijec, char *zamjena, int len1, int len2) {
	char *start = tekst;
	int len3 = 0, n = 0, cond = 1;
	
	while (cond) {
		if (!medja(*tekst)) {
			len3++;
		} else {
			if (len3 != 0) { /* Rijec zavrsava */
				if (len1 == len3) {
					if (uporedi(rijec, tekst - len1 - n, len1)) {
						zamijeni_dvije(tekst - len1 - n, zamjena, len2);
						n += len1 - len2;
					}
				}
			}
			len3 = 0;
		}
		*(tekst - n) = *tekst;
		if (*tekst == 0) cond = 0;
		tekst++;
	}
	
	return start;
}

/* Mijenja sve instance rijeci za duzu rijec */
char *zamijeniZaDuzu(char *tekst, char *rijec, char *zamjena, int len, int len1, int len2) {
	char *start = tekst;
	int len3 = 0, n = 0, cond = 1, diff;
	
	/* Razlika duzina dvije rijeci */
	diff = len2 - len1;
	tekst += len;
	/* Duzina teksta ce se povecati */
	n = broj(start, rijec, len1) * diff;
	len += n;

	while (cond) {
		if (!medja(*tekst)) { /* Karakter nije medja */
			len3++;
		} else {
			if (len3 != 0) { /* Prosli smo pocetak rijeci */
				if (len1 == len3) {
					if (uporedi(rijec, tekst + 1 + n, len1)) {
						n -= diff;
						zamijeni_dvije(tekst + 1 + n , zamjena, len2);
					}
				}
			}
			len3 = 0;
		}
		*(tekst + n) = *tekst;
		
		if (tekst == start) cond = 0;
		tekst--;
	}
	
	/* U slucaju da se rijec nalazila na samom pocetku teksta */
	if (uporedi(rijec, start + diff, len1)) {
		zamijeni_dvije(start, zamjena, len2);
	}
	
	return start;
}


char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci) {
	int len, len1, len2, i;

	for (i = 0; i < broj_rijeci; i++) {
		/* Duzina teksta se moze promijeniti u svakoj iteraciji */
		len = duzina(tekst);
		len1 = duzina(rijeci[i]);
		len2 = duzina(zamjene[i]);

		
		if (len1 < len2) {
			zamijeniZaDuzu(tekst, rijeci[i], zamjene[i], len, len1, len2);
		} else {
			zamijeniZaKracu(tekst, rijeci[i], zamjene[i], len1, len2);
		}
	}
	
	return tekst;
}



int main() {
	
	
	/*/* int len = 0; 
	char t[200] = "  HellO Hello  Hello.Hello  hello Hello*";
	
	char *A = "Hello", *B = "A", *C = "*A!", *D = "AAA", 
	*E[2] = {A, B}, *F[2] = {C, D};

	printf("PRV\n");

	printf(zamjena_rijeci(t, E, F, 2));
	len = duzina(t);*/

	/*printf("%s\n", zamijeniZaKracu(t, "Hello", "*A!", 5, 3));
	printf("%s\n", zamijeniZaDuzu(t, "A", "AAA", len, 1, 3));
	*/
	
	char* rijeci[2] = { "c" };
	char* zamjene[2] = {  "Prijestolonasljednikovica" };

	/* Ovako cemo zadati tekst da bi vrijednosti >3 bile neinicijalizirane */
	char tekst[100]; /* = "c c"; */
	tekst[0] = 'c';
	tekst[1] = ' ';
	tekst[2] = 'c';
	tekst[3] = '\0';

	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));

	return 0;
}



