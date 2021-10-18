#include <stdio.h>
#include <math.h>
#define BR_EL 100

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{

	int i, j, cifra, temp, exponent = 0;
	int niz_cifara2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int znak;

	/*Provjeravamo jesu li cifre unutar niza ispravne*/
	for(i = 0; i < vel2; i++) {
		if(niz2[i] < 0 || niz2[i] > 9)
			return 0;
	}

	for(i = 0; i < vel2; i++) {
		for(j = 0; j < i; j++)
			if(niz2[i] == niz2[j])
				return 0;
	}

	/*U pomocnom nizu cifara od 1 do 9, uklanjamo one cifre koje treba izbaciti,
	tj. oznacavamo sa -1, jer to nije cifra,
	tako da ostaju samo one koje mogu biti unutar svakog od brojeva niza*/
	for(i = 0; i < 10; i++) {
		for(j = 0; j < vel2; j++) {
			if(niz_cifara2[i] == niz2[j])
				niz_cifara2[i] = -1;
		}
	}


	/*Svaki clan niza*/
	for(j = 0; j < vel1; j++) {
		/*pospremamo u pomocnu varijablu*/
		temp = fabs(niz1[j]);

		/*pamtimo znak broja*/
		if(niz1[j] < 0) znak = -1;
		else znak = 1;

		/*postavljamo broj i eksponent na 0, da bi kasnije mogli ispravno racunati broj*/
		niz1[j] = 0;
		exponent = 0;

		/*rastavljamo temp na cifre*/
		while(temp > 0) {
			cifra = temp % 10;
			temp = temp / 10;

			/*ako trenutna cifra postoji u nizu cifara koje se ne izbacuju*/
			for(i = 0; i < 10; i++) {
				if(cifra == niz_cifara2[i]) {
					/*mnozimo tu cifru sa 10 na eksponent i povecavamo eksponent za sljedecu cifru*/
					niz1[j] = niz1[j] + cifra * pow(10, exponent);
					exponent++;
					break;
				}
			}
		}

		/*nakon sto su izbacene cifre iz broja, vratimo odgovarajuci znak broju kojeg je prvobitno imao*/
		niz1[j] *= znak;
	}

	return 1;
}

int main()
{
	int i,vel1, niz1[BR_EL], vel2, niz2[BR_EL];
	printf("Unesite velicinu prvog niza: ");
	scanf("%d",&vel1);
	printf("Unesite clanove prvog niza: ");
	for(i = 0; i < vel1; i++)
		scanf("%d",&niz1[i]);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d",&vel2);
	printf("Unesite clanove drugog niza: ");
	for(i = 0; i < vel2; i++)
		scanf("%d",&niz2[i]);

	return 0;
}
