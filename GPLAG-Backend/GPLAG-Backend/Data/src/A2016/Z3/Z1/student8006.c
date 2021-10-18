#include <stdio.h>

int daj_prost()
{
	static int broj = 2;
	int j = 0, control;
	/* Napravimo petlju koja ce sluziti za provjeru broja(da li je prost). Najbolje je da bude beskonacna petlja
	jer je onda mozemo prekinuti kada nadje prost broj ili je pustiti da radi ako broj na koji smo naisli nije prost
	ili je vec raniej pronadjeni prost broj. */
	while( 1 ) {
		control = 1;
		/* Napravimo petlju za provjeru da li je broj prost i krene od 2, jer je svaki broj djeljiv sa 1, i ide do tog broja,
		iskljucujuci taj broj. */
		for( j = 2; j < broj; j++ ) {

			if ( broj % j == 0 ) {
				control = 0;
				break;
			}

		}
		/* Provjera istinitisti petlje iznad */
		if(control == 1) {
			return broj++;
			break;
		} else
			broj++;
	}
}

int main()
{

	int A, B, suma = 0, prost = 0, i = 0;

	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);

		if (A <= 0)
			printf ("A nije prirodan broj.\n");

		else if (A >= B)
			printf ("A nije manje od B.\n");

	} while ( A <= 0 || B <= 0 || A == B );


	for ( i = 1; i < B; i++ ) {
		prost = daj_prost();
		if ( prost > A && prost < B )
			suma += prost;
	}

	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

	return 0;
}