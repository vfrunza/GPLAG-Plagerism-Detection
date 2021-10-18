#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz[], int vel1, int izbaci[], int vel2) /* Prototip funkcije */
{
	int i, j,k,z,brojac=0;
	int p, brojach;
	int niz_istih[5] = {0}; /* POCETAK ISPITIVANJA USLOVA */
	for(i=0; i<vel2; i++) {  /* Ovdje od poetka poredimo da li se u nizu nalaze isti brojevi, ako se nalaze onda program vraca 0 */
		for(j=0; j<vel1; j++) {
			if(izbaci[i] == niz[j]) {
				niz_istih[i] == niz[j]; /* Da li su projevi u nizu isti? Ako jesu onda se prebacuju clanovi*/
			}
		}
	}
	for(i=0; i<vel1; i++) {
		for(j=0; j<vel1-1; j++) {
			if(niz_istih[1] == niz[1]) {
				brojac++;
			}
		}
	}
	if(brojac==vel1)
		for(i=0; i<vel1; i++) printf("0 "); /* KRAJ ISPITIVANJA USLOVA */

	for(i=0; i<vel2; i++) { /* Uzimamo niz brojeva koje treba izbaciti */
		if(izbaci[i]>9 || izbaci[i]<0) { /* Ispitujemo uslov iz postavke zadatka */
			return 0;
		}
		for(j=i+1; j<vel2; j++) { /* Takodjer ako imamo iste brojeve u ovome nizu, program opet treba da vrati nulu */
			if(izbaci[i] == izbaci[j]) {
				return 0;
			}
		}
	} /* Kraj ispitivanja uslova koji su postavljeni u samome zadatku */

	for(i=0; i<vel1; i++) { /* Uzimamo broj iz prvog niza i prolazimo kroz niz "izbacivaca" */
		for(j=0; j<vel2; j++) {
			p = 0; /* Varijabla koja ce kasnije postati i-ti clan niza nakon izbacivanja brojeva */
			brojach = 0;

			while(niz[i]!=0) {
				if(fabs(niz[i] % 10) != izbaci[j]) { /* Ako je apsolutna vrijednost broja modulo 10 razlicita od broja izbacivaca: */
					p = p + niz[i] % 10 * pow(10, brojach);
					brojach = brojach + 1;
				}
				niz[i] = niz[i] / 10;
			}
			niz[i] = p;
		}
	}
}

int main() /* Funkcija main je koristena za testove */
{
	int brojevi[] = {123, 456};
	int cifre1[] = {1, 2, 3, 1};
	int cifre2[] = {1, 2, 10, 4};
	int cifre3[] = {1, 2, 3, -4};
	int i, rez;

	cifre3[3] = 4;
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	printf("%d %d", brojevi[0], brojevi[1]);
}
