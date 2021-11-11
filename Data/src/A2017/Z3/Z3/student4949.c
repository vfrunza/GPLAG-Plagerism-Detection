#include <stdio.h>
#define BREL 1000
#define BRCIF 1000

int izbaci_cifre(int niz1[],  int n1, int niz2[], int n2)
{

	int i, j, temp, novibroj, koeficijent_cifre, cifra;

	if (n2>10) {
		return 0;  /*Najjednostavniji uslov za provjeriti jer postoji samo 10 jednocifrenih brojeva, a to znaci da ako imamo više od 10
		clanova tog niza, neke od cifara se moraju ponavljati ili mozda nisu cjelobrojni jednocifreni clanovi. U tom slucaju fja vraca 0.*/
	}
	for(i=0; i<n2; i++) {
		if(niz2[i]<0 || niz2[i]>9)
			return 0;
	}

	for(i=0; i<n2; i++) {
		for(j=i+1; j<n2; j++) {
			if(niz2[i]==niz2[j])	/*Provjerava ukoliko imamo 2 iste cifre u nizu cifara*/
				return 0;
		}
	}
	/* "novibroj" cemo koristiti kako bi neometano prolazili kroz sve cifre broja preko varijable "temp" dok u "novibroj" spremamo sve cifre
	koje trebaju ostati u broju pomnozene s odgovarajucim koeficijentom. */
	for(i=0; i<n1; i++) {
		for(j=0; j<n2; j++) {
			novibroj=0;
			koeficijent_cifre=1;   /* Prvim djeljenjem nekog broja sa 10 dobijamo jednocifren ostatak tako da koeficijent cifre koju posmatramo
									pocinje sa 1, a kasnije se mnozi sa 10 iduci prema deseticama, stoticama itd. */
			if(niz1[i]<0)
				temp=-1*niz1[i];  /* Poredimo samo cifre, a ne kompletne brojeve, pa ukoliko je neki od brojeva negativan, treba ga pretvoriti u pozitivan,
									ali bez modifikovanja niza, da nam se ne bi desilo da neka cifra ne bude izbacena jer je ostao minus ispred nje*/
			else
				temp=niz1[i];
			while(temp!=0) {
				cifra=temp%10;
				temp=temp/10;   /*Sve varijable su cjelobrojne, stoga nema potrebe uzimanja (int) dijela za skracivanje broja.*/
				if(cifra!=niz2[j]) {
					novibroj=novibroj+(koeficijent_cifre*cifra);
					koeficijent_cifre=koeficijent_cifre*10;
				}
			}

			if(niz1[i]<0)
				niz1[i]=novibroj*(-1); /*Ukoliko je broj bio negativan na pocetku, mora biti negativan i poslije izbacivanja cifara*/
			else
				niz1[i]=novibroj;  /* Broj i-tog indeksa poslije promjene sada odgovara novom broju i kao takav je spremljen u novi niz*/
		}
	}
	return 1;
}
int main()
{
	int nizbrojeva[BREL], nizcifara[BRCIF], nBr, nCif, i;

	printf("Unesite broj elemenata prvog niza: \n");
	scanf("%d", &nBr);

	printf("Unesite niz cijelih brojeva: \n");
	for(i=0; i<nBr; i++)
		scanf("%d", &nizbrojeva[i]);

	printf("Unesite broj cifara drugog niza: \n");
	scanf("%d", &nCif);

	printf("Unesite niz cifara: ");
	for(i=0; i<nCif; i++)
		scanf("%d", &nizcifara[i]);

	izbaci_cifre(&nizbrojeva[0], nBr, &nizcifara[0], nCif);
	printf("Niz brojeva glasi:");
	for(i=0; i<nBr; i++) {
		printf("%d ", nizbrojeva[i]);
	}
	return 0;
}
