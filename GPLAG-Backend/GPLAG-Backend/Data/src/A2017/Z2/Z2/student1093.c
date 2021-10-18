#include <stdio.h>
//URADJENO SA POKAZIVACIMA, MADA KAD JE POSTAVLJENA ZADACA NISMO RADILI POKAZIVACE TAD :/ SADLY...
int main()
{
	int niz[100];
	int i = 0, n, vel;

	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &vel);
		if(vel <= 0 ) printf("Neispravan unos! Ponovi!\n");
	} while(vel <= 0);

	printf("Unesite clanove niza: ");
	do {
		scanf("%d", &n);
		niz[i] = n;
		i++;
		if( n < 0) printf("Pogresan unos! Ponovi!\n");
	} while(i < vel || n <  0);

	printf("Finalni niz glasi: \n");

	char pomocni[100];
	char *pok = pomocni;
	char *pocetak = pomocni;
	int broj_cifara;

	int broj;
	for(i = 0 ; i < vel; i++) {
		broj = niz[i];
		broj_cifara = 0;
		if(broj == 0) broj_cifara = 1;
		while(broj != 0) {
			broj_cifara++;
			broj /= 10;
		}
		broj = niz[i];
		pok += broj_cifara - 1;
		if(broj == 0) {
			*pok = broj + '0';
			pok++;
		} else {
			while(broj != 0) {
				*pok = broj % 10 + '0';
				broj /= 10;
				pok--;
			}
			pok += broj_cifara + 1;

		}
	}
	*pok = '\0';
	pok = pocetak;

	int niz2[1000];
	int brojac = 0;
	char znak;
	int indeks = 0;
	while( *pok != '\0') {
		znak = *pok;
		brojac = 0;
		while(*pok != '\0' && znak == *pok) {
			brojac++;
			pok++;
		}
		niz2[indeks++] = znak - '0';
		niz2[indeks++] = brojac;
	}

	for(i = 0; i < indeks; i++) {
		printf("%d ", niz2[i]);
	}

	return 0;
}
