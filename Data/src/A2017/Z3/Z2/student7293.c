#include <stdio.h>
#include <math.h>

void zaokruzi1 (float niz[], int vel) {
	int i;
	for (i=0; i<vel; i++) {
		*niz = round(*niz * 10)/10;
		niz++;
	}
}

void preslozi (float niz[], int vel, int k) {
	
	int i=0, pom=1, cifra, br=0;
	float suma, novi[100];
	float *pok = niz;
	
	zaokruzi1(niz, vel);
	
	while (i<vel) {											/* duzina petlje ne valja */
		pom = niz[i]*10;
		suma = 0;
		while (pom!=0) {
			cifra = pom % 10;
			suma += cifra;
			pom /= 10;
		}
		novi[i]=suma;
		i++;
	}
	
	for (i=0; i<vel; i++) {
		if (novi[i]>=k) {
			br++;
			*niz = *(pok+i);
			niz++; pok++;
		}
	}
	
	for (i=br; i<vel; i++) {					/* samo jos ovo popraviti */
		*niz = *(pok+i);
		niz++; pok++;
	}
	
}

int main() {
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 
	return 0;
}
