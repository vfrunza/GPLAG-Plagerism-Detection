#include <stdio.h>
int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3)
{
	int brojac, brojJednakihClanova=0, i, j, logicka=0;
	// Brojac se koristi za brojanje u koliko se nizova broj nalazi, brojJednakihClanova se vraca iz funkcije, i i j su promjenljive koje se koriste u petljama, logicka promjenljiva sprjecava ponavljanje //
	for (i=0; i<velicina1; i++) {
		// Provjeravanje da li se vec taj broj brojao u prvom nizu, ako jest, postavlja logicku na 1, i u tom slucaju se preskace trazenje u koliko se nizova taj broj nalazi (da bi se sprijecilo ponavljanje) //
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j])
				logicka=1;
		}
		if (logicka)
			continue;
		else {
			// Dvije petlje koje prolaze kroz drugi i treci niz, i traze da li se broj nalazi u nizu, samo u slucaju da se nalazi u jednom od dva niza povecava brojJednakihClanova za 1 (break se koristi da sprijeci ponavljanje) //
			brojac=0;
			for (j=0; j<velicina2; j++) {
				if (niz2[j]==niz1[i]) {
					brojac++;
					break;
				}
			}
			for (j=0; j<velicina3; j++) {
				if (niz3[j]==niz1[i]) {
					brojac++;
					break;
				}
			}
			if (brojac==1)
				brojJednakihClanova++;
		}
	}
	logicka=0;
	// U drugom dijelu funkcije, trazi se clan koji se nalazi u drugom nizu a ne nalazi u prvom, i onda se provjerava da li se taj broj nalazi u trecem nizu //
	for (i=0; i<velicina2; i++) {
		// Identicno sprjecavanje ponavljanja kao na pocetku funkcije //
		for (j=0; j<i; j++) {
			if (niz2[i]==niz2[j])
				logicka=1;
		}
		if (logicka)
			continue;
		else {
			brojac=0;
			for (j=0; j<velicina1; j++) {
				if (niz1[j]==niz2[i]) {
					brojac++;
					break;
				}
			}
			// Trazimo broj koji se ne nalazi u prvom nizu, zato postavljamo uslov za brojac==0 //
			if (brojac==0) {
				for (j=0; j<velicina3; j++) {
					if (niz2[i]==niz3[j]) {
						brojJednakihClanova++;
						break;
					}
				}
			}
		}
	}
	return brojJednakihClanova;
}

int main()
{
	int niz1[10], niz2[10], niz3[10], velicina1, velicina2, velicina3, i, broj;
	printf("Unesite velicine 3 niza: ");
	scanf("%d %d %d", &velicina1, &velicina2, &velicina3);
	printf("Unesite 1. niz: ");
	for (i=0; i<velicina1; i++) {
		scanf("%d", &niz1[i]);
	}
	printf("Unesite 2. niz: ");
	for (i=0; i<velicina2; i++) {
		scanf("%d", &niz2[i]);
	}
	printf("Unesite 3. niz: ");
	for (i=0; i<velicina3; i++) {
		scanf("%d", &niz3[i]);
	}
	broj=dva_od_tri(niz1, velicina1, niz2, velicina2, niz3, velicina3);
	printf("Funkcija vraca broj %d", broj);
	return 0;
}
