#include <stdio.h>

int main() {
	int n, unos; /* Unos postoji kako se ne bi spremilo u niz prije provjere uslova */
	int uslov_clanovi, i, j, broj, broj_cifri, duzina_niza_cifara, broj_ponavljanja;
	int polazni_niz[100];
	int niz_cifara[1000];
	int rezultujuci_niz[1000];
	
	/* Postavljanje cifara na -1, jer je 0 legalna cifra */
	
	for (i=0 ; i<100 ; i++)
		polazni_niz[i] = -1;
		
	for (i=0 ; i<1000 ; i++)
		niz_cifara[i] = rezultujuci_niz[i] = -1;
		
	/* Unos */
	
	do {
		uslov_clanovi = 1;
		
		printf ("Unesite velicinu niza: ");
		scanf("%d", &n);
		
		printf("Unesite clanove niza: ");
		for (i=0 ; i<n ; i++) {
			scanf ("%d", &unos);
			if (unos < 0)
				uslov_clanovi = 0;
			else 
				polazni_niz[i] = unos;
		}
		
	} while (n <= 0 || !uslov_clanovi);

	
	/* Kreiranje medjuniza koji se sastoji od cifara polaznog niza */
	duzina_niza_cifara = 0;
	for (i=0; i<n; i++) {
		/*prvo uzimamo svaki clan polaznog niza i njegove cifre unosimo u niz cifara*/
		broj = polazni_niz[i];
		broj_cifri = 0;
		if (broj != 0) {
			/*prebrojimo cifre broja*/
			while (broj != 0) {
				broj_cifri++;
				broj /= 10;
			}
			/*upis u rezultujuci niz*/
			/*moramo ovdje restartovati broj jer je on smanjen na nulu u prethodnoj while petlji*/
			broj = polazni_niz[i];
			j = duzina_niza_cifara + broj_cifri - 1;
			while (j >= duzina_niza_cifara) {
				niz_cifara[j] = broj % 10;
				broj /= 10;
				j--;
			}
			/*mijenjamo velicinu rezultujuceg niza*/
			duzina_niza_cifara += broj_cifri;
		}
		else {
			/*nula kao element polaznog niza je specijalan slučaj jer gore iznad ne bi radilo while (broj != 0)*/
			/*potrebno je samo upisati 0 na kraj rezultujućeg niza i povećati njegovu dužinu za 1*/
			niz_cifara[duzina_niza_cifara] = 0;
			duzina_niza_cifara++;
		}
	}
	
	
	/* Formiranje rezultujuceg niza */
	 
	i = 0;
	j = 0; /* Sa j se krecemo kroz rezultujuci niz */
	
	while (niz_cifara[i] != -1) {
		broj = niz_cifara[i];
		broj_ponavljanja = 1;
		i++;
		
		while (broj == niz_cifara[i]) {
			broj_ponavljanja++;
			i++;
		}
		
		rezultujuci_niz[j] = broj;
		j++;
		rezultujuci_niz[j] = broj_ponavljanja;
		j++;
	}
	
	i = 0;
	printf("Finalni niz glasi:\n");
	while (rezultujuci_niz[i] != -1) {
		printf ("%d ", rezultujuci_niz[i]);
		i++;
	}
	
	
	return 0;
}
