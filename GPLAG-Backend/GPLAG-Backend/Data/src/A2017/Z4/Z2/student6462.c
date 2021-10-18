#include <stdio.h>

/* PROTOTIPI */
int provjeri_duzine(char*, int*, int);

int main() {
	char *s = "   Ovo    je neki primjer teksta...\0";
	int arr[] = {3, 2, 4, 7, 6};
	printf("%d", provjeri_duzine(s, arr, sizeof(arr) / sizeof(arr[0])));
	
	return 0;
}

/* provjeri_duzine - IMPLEMENTACIJA */
int provjeri_duzine(char *txt, int *arr, int arrLen) {
	int currWordIndex = 0;
	int currWordLen, wordEnd = 0;
	
	/* Provjera se vrsi samo dok nismo dosli do kraja niza za provjeru
	   ili kraja stringa */
	while (*txt != '\0' && currWordIndex < arrLen) {
		currWordLen = 0;
		
		/* prebroj sva slova koja se nalaze u rijeci,
		   i zapamti da smo vidjeli rijec */
		while ((*txt >= 'A' && *txt <= 'Z') || (*txt >= 'a' && *txt <= 'z')) {
			currWordLen++;
			txt++;
			
			wordEnd = 1;
		}
		
		/* Ukoliko je rijec bila vidjena provjeri je li okej duzina */
		if (wordEnd) {
			if (currWordLen != arr[currWordIndex])
				return 0;
			
			currWordIndex++;
			wordEnd = 0;
		}
		else /* else ovdje ide jer se moze desiti da se gornjim while-om
				"zapuca" u '\0' a da ga ovo pomjeri iza '\0' sto bi ovo ucinilo
				beskonacnom petljom koja pristupa nedozvoljenoj memoriji */
			txt++;
	}
	
	/* Ako smo prosli kroz string, a nismo prosli kroz citav niz duzina */
	if (currWordIndex != arrLen)
		return 0;
	
	/* Ako smo prosli kroz citav niz duzina, a postoji jos rijeci */
	while (*txt != '\0') {
		if ((*txt >= 'A' && *txt <= 'Z') || (*txt >= 'a' && *txt <= 'z'))
			return 0;
			
		txt++;
	}
	
	/* Ako je sve okej, niz je zaista niz duzina rijeci u stringu */
	return 1;
}
/* END provjeri_duzine */