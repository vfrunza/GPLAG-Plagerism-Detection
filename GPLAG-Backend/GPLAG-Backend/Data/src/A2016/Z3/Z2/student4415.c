#include <stdio.h>
#include <math.h>

// Funkcija koja provjerava da li je broj fibonacijev

int Fibonaci(int a)
{

	int	b = a, first = 0, second = 1, next, x = 1;

	while (1) {
		next = first + second;

		if (b == next)
			break;
		else if (b < next) {
			x = 0;
			break;
		} else {
			first = second;
			second = next;
		}
	}

	return x;
}

// Funkcija koja racuna sumu cifara


int Suma_cif(int a)
{

	int	zad_cifra, suma = 0;
	int b=fabs(a);

	while (b) {
		zad_cifra = b%10;
		suma = suma + zad_cifra;
		b = b/10;
	}

	return suma;
}

// Funkcija ubaci ( ubaciva sumu vrijednost elementa iza tog elemta)

void ubaci (int niz[], int vel)
{

	int i, position = 2;                        // pozicija na koju ubavicamo sumu
	int vel1 = vel;							// kopija velicina niza
	int	*p = niz, *q = niz, *d = niz;         // Pokazivaci na niz

	while (d < niz + vel) {
		// Ubacivamo sumu cifara broja odma poslije broja tako da pozicija gdje ubacivamo sumu poveca va za 2 (1, 3, 5....)
		// Petlja koja pomjera cijeli niz za jedno mjesto napred

		for (i = vel1 - 1; i >= position - 1; i--) {
			*(p+i+1) = *(p+i);
		}
		// Ubacivamo sumu u niz
		*(p+position-1) = Suma_cif(*q);

		// povecavamo velicinu niza, poziciju na koju ubacivamo sumu, i pokazivac gdje dodajemo sumu na niz
		vel1++;
		position += 2;
		q += 2;
		d++;
	}
}

//Funkcija koja izbaciva sve fibonacijeve brojeve iz niza

int izbaci(int niz[], int vel)
{

	int vel1 = vel, i, j;		 // kopija velicine niza
	int *p = niz, *q = niz;	// pokazivaci na niz

	// Izbacivamo elemente iz niza uz ocuvanje redoslijeda

	for (i = 0; i < vel1; i++) {
		// Provjeravamo da li je broj fibonacijev , ako je izbacivamo ga
		if (Fibonaci(*(p+i))) {
			for (j=i; j < vel1 - 1; j++) {
				*(q+j) = *(q+j+1);
			}
			vel1 --;
			i --;
		}
	}
	// Vracamo novu velicinu niza
	return vel1;
}

int main()
{

	int		niz[30], vel = 10, vel1,  i;

	// Unos niza
	printf ("Unesite niz od 10 brojeva: ");

	for (i = 0 ; i < vel; i++) {
		scanf ("%d", &niz[i]);
	}
	// Pozivamo funkciju ubaci saljemo duzinu niza za koju znamo da je 10, funkcija nam ne vraca nista jer znamo da je nova velicina niza duplo vec
	ubaci(niz, vel);
	// Pozivamo funkciju izbaci , saljemo novu velicinu niza , funkcija nam vraca sada novu velicinu koju moramo sacuvati u neku varijablu
	vel1 = izbaci (niz, 2*vel);

	printf ("Modificirani niz glasi: ");
    
	for (i = 0 ; i < vel1; i++) {

		if ( i == vel1 -1 )
			printf ("%d.", niz[i]);
		else
			printf ("%d, ", niz[i]);
	}

	return 0;
}
