#include <stdio.h>

/* PROTOTIPI */
void najduzi_bp(char*, char*);

int main() {
	char niz[10];
	najduzi_bp("Ovo je primjer teksta", niz);
	printf("%s\n", niz);
	return 0;
}

/* najduzi_dp - IMPLEMENTACIJA */
void najduzi_bp(char *search, char *res) {
	/* long ima _najmanje_ 32 bita,
	   sto znaci da se moze u njega strpati bitset za slova */
	long letters = 0;
	int currLetter, maxLen = 0, len;
	char *start, *it1, *it2;
	
	while (*search != '\0') {
		start = search;
		letters = 0;
		
		len = 0;
		
		/* Naivna pretraga - za optimizaciju moguce uraditi KMP (Knuth-Morris-Pratt)
		   ali je to izvan opsegaAa */
		while (*start != '\0') {
			/* trenutno slovo - oznaceno brojem od 0 to 25 */
			currLetter = *start - 'a';
			currLetter = (currLetter < 0) ? (*start - 'A') : currLetter;
			
			/* Ukoliko nije slovo, ili je vec se pojavilo */
			if ((currLetter < 0 || currLetter >= 26) || (letters & (1 << currLetter)))
				break;
			
			/* Spasi da je slovo se pojavilo */
			letters |= 1 << currLetter;
			len++;
			start++;
		}
		
		/* Ako je novo-pronadjeni substr duzi, prekopiraj ga u res */
		if (len > maxLen) {
			for (it1 = search, it2 = res; it1 != start; it1++, it2++)
				*it2 = *it1;
				
			maxLen = len;
		}
		
		search++;
	}
	
	/* stavi '\0' radi sigurnosti */
	res[maxLen] = '\0';
}
/* END najduzi_bp */