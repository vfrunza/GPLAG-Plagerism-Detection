#include <stdio.h>

/*Funkcija koja provjerava da li cifra postoji u nizu cifara*/
int postoji_u_ciframa (int cifra, int *niz_cifara, int vel_cifara)
{
	int *p ;

	p = niz_cifara;
	while (p < niz_cifara + vel_cifara) {
		if (*p == cifra)
			return 1;
		p++;
	}
	/*Ako je zavrsila ova petlja, znaci da nemamo cifru u nizu*/
	return 0;
}

int izbaci_cifre (int *niz_cijelih, int vel_cijelih, int *niz_cifara, int vel_cifara)
{
	int *p, *q;
	int pom, cifra, broj=0, k=1;

	p = niz_cifara;
	/*provjera korektnosti niza cifara*/
	while (p < niz_cifara + vel_cifara) {
		if (*p < 0 || *p > 9)
			return 0;

		q = p + 1; /* Ako se neki od clanoa niza cifri ponavlja */
		while (q < niz_cifara + vel_cifara) {
			if (*p == *q)
				return 0;
			q++;
		}
		p++;
	}

	/*obrada niza cijelih brojeva(izbacivanje cifara)*/
	p = niz_cijelih;
	while (p < niz_cijelih + vel_cijelih) {

		pom = *p; /* Mijenjamo samo pomocni, ako radili sa *p past ce na nulu, sto ne smije */
		/*ako je broj negativan, zbog uslova u narednoj while petlji radimo ovo*/
		if (pom < 0)
			pom *= -1;

		/*za svaki clan niza cijelih potrebno je restartovati k i broj*/
		k = 1;
		broj = 0;
		while (pom > 0) {
			cifra = pom%10;
			/*ako cifra ne postoji u nizu cifara nju dodajemo u novi broj*/
			if (!postoji_u_ciframa(cifra, niz_cifara, vel_cifara)) { /* Obrnuta logika, ako postoji nece je dodati u broj */
				broj = broj + cifra * k;
				k *= 10;
			}
			pom /= 10;
		}

		/*ako je pocetni broj bio negativan, bit ce i rezultujuci*/
		if (*p < 0)
			*p = -broj;
		else
			*p = broj;

		p++;
	}

	return 1;
}

int main()
{
	return 0;
}
