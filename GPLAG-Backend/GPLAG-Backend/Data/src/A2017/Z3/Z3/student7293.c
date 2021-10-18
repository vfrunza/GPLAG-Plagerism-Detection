#include <stdio.h>

int izbaci_cifre (int niz1[], int vel1, int niz2[], int vel2) {		/* niz1-niz brojeva; niz2-niz cifara; */
	
	int i, j, cifra, prvi;
	int *p = niz1;
	int *pok = niz2;
	
	prvi = *pok;
	for (i=0; i<vel2; i++) {
		if (*pok < 0 || *pok>9)	return 0;
		if (*pok==prvi)	return 0;
		pok++;
	}
	
	/*for (i=0; i<vel1; i++) {
		for (j=0; j<vel2; j++) {
			cifra = *p % 10;
			if (cifra == *pok) {
				return 1;
			}
			*p = *p / 10;
			p++;
		}
		
	}*/
	
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
