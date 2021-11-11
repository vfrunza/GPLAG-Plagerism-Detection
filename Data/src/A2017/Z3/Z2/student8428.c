#include <stdio.h>

/* Funkcija za zaokruzivanje na jednu decimalu */
void zaokruzi1 (float *niz, int vel)
{
	float *p = niz;
	int pomocni;
	while (p < niz + vel) {
		if (*p >= 0)
			pomocni = *p * 10 + 0.5;
		else
			pomocni = *p * 10 - 0.5;
			
		*p = pomocni / 10.;
		p++;
	}
	return;
}

/* Funkcija u koju posaljemo jedan clan niza, a ona nam izracuna sumu njegovih cifara */
int suma_cifara (float broj)
{
	int suma = 0, cifra, cijeli_broj;

	cijeli_broj = broj * 10;
	/*u slucaju da je broj negativan, pretvorimo u pozitivan zbog uslova u while*/
	if (cijeli_broj < 0)
		cijeli_broj *= -1;

	while (cijeli_broj > 0) {
		cifra = cijeli_broj%10;
		suma += cifra;
		cijeli_broj /= 10;
	}
	return suma;
}

void preslozi (float *niz, int vel, int k)
{
	float pomocni;
	float *p, *q;

	/*zaokruzivanje*/
	zaokruzi1(niz, vel);
	
	p = niz;
	while (p < niz + vel) {
		if (suma_cifara(*p) >= k) { /* Ako je >= od k tada moramo presloziti broj na odgovarajuce mjesto */
			pomocni = *p; /* Ovdje moramo zapamtiti vrijednost na koju p pokazuje jer ce se prilikom pomjeranja elementa pisati preko nje */

			q = p - 1;
			while (q >= niz && suma_cifara(*q) < k) {
				*(q+1) = *q;
				q--;
			}
			q++;
			*q = pomocni;
		}
		p++;
	}
	return;
}

int main()
{
	int i, vel = 5, k=14;
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };

	zaokruzi1(niz, vel);
	printf ("Zaokruzeni niz:\n");
	for (i=0 ; i<vel ; i++) {
		printf ("%g ", niz[i]);
	}

	preslozi(niz, vel, k);
	printf ("\nPreslozeni niz:\n");
	for (i=0 ; i<vel ; i++) {
		printf ("%g ", niz[i]);
	}
	
	return 0;
}
