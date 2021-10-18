#include <stdio.h>
#include <math.h>

/* PROTOTIPI */
char *ubaci_broj(char*, int);

int main() {
	/* Quick test code */
	char s[100] = "T t a \tbcde \n fgi\0";
	int br = -10;
	ubaci_broj(s, br);
	printf("%s\n", s);
	
	return 0;
}

/* ubaci_broj - IMPLEMENTACIJA */
char *ubaci_broj(char *text, int num) {
	int sign = (num < 0) ? 1 : 0;
	int numLen, lenPow, i;
	/* cpy sluzi za premijestanje dijela strina unaprijed pri ubacivanju broja */
	char *ret = text, *end = text, *cpy, *endWords;
	
	/* broj bez znaka, tj. apsolutna vrijednost */
	num = sign ? -num : num;
	/* duzina broja bez znaka */
	numLen = (int)log10(num ? num : 1) + 1;
	lenPow = (int)pow(10, numLen);
	
	/* Sacuvat cemo gdje se nalazi kraj posljednje rijeci, te gdje se nalazi
	   kraj stringa na pocetku, kasnije ce biti pomijerani */
	while (*end != '\0') {
		if (*end != ' ')
			endWords = end;
			
		end++;
	}
	
	/* ubacivat cemo samo do kraja posljednje rijeci, ne zelimo u razmak poslije
	   posljednje ubacivati*/
	while (text < endWords) {
		/* ukoliko se ne nalazimo na pocetku stringa, te nismo vec ubacili broj
		   za prethodnu rijec*/
		if (text != ret && *text == ' ' && *(text - 1) != ' ') {
			/* pomjeri sve za dovoljno mijesta udesno da broj moze stati */
			cpy = end;
			while (cpy != text) {
				*(cpy + numLen + sign) = *cpy;
				cpy--;
			}
			
			text++;
			/* dodati znak ako je broj negativan */
			if (sign) {
				*text = '-';
				text++;
			}
			
			/* dodavanje broja */
			for (i = lenPow; i >= 10; i /= 10, text++) {
				*text = (num % i) / (i / 10) + '0';
			}
			
			/* pomjeranje kraja stringa za onoliko koliko smo ubacili */
			end += (numLen + sign);
			endWords += (numLen + sign);
			
			/* ako nema razmaka poslije ubacenog broja, njega moramo dodati */
			if (*text != ' ') {
				cpy = end;
				
				while (cpy != text)
					*(cpy + 1) = *cpy--;
				
				*(text + 1) = *text;
				*text++ = ' ';
				
				end++;
				endWords++;
			}
		}
		
		text++;
	}
	
	return ret;
}
/* END ubaci_broj */