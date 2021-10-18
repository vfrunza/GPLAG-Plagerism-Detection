#include <stdio.h>

int postoji_u_nizu ( int broj, int niz[], int n)
{

	if( n == 0) return 0;

	int i;

	for ( i = 0; i< n; i++) {
		if (broj == niz[i]) {
			return 1;
		}
	}

	return 0;
}

int dva_od_tri(int nizA[], int velA, int nizB[], int velB, int nizC[], int velC )
{

	int brojac = 0;

	int nizJedinstvenihBrojeva [20];

	int i,j,k,l;

	//kreiramo niz jedinstvenih brojeva koji se nalaze u tri niza koje primimo

	for( i = 0 ; i < velA; i++) {
		if( !postoji_u_nizu(nizA[i], nizJedinstvenihBrojeva, brojac) ) {
			nizJedinstvenihBrojeva[brojac] = nizA[i];
			brojac++;
		}
	}

	for( i = 0 ; i < velB; i++) {
		if( !postoji_u_nizu(nizB[i], nizJedinstvenihBrojeva, brojac) ) {
			nizJedinstvenihBrojeva[brojac] = nizB[i];
			brojac++;
		}
	}

	for( i = 0 ; i < velC; i++) {
		if( !postoji_u_nizu(nizC[i], nizJedinstvenihBrojeva, brojac) ) {
			nizJedinstvenihBrojeva[brojac] = nizC[i];
			brojac++;
		}
	}

	// sada pretrazujemo sva tri niza koristeci brojeve iz niza jedinstvenih vrijednosti, i brojimo koliko puta smo pronasli svaki broj

	int pronadjenPuta = 0;
	int rezultat = 0;
	int broj = 0;

	for( i = 0; i < brojac; i++) {
		pronadjenPuta = 0;

		broj = nizJedinstvenihBrojeva[i];

		for( j = 0; j < velA; j++) {

			if(broj == nizA[j]) {
				pronadjenPuta++;
				break;
			}
		}

		for( k = 0; k < velB; k++) {

			if(broj == nizB[k]) {
				pronadjenPuta++;
				break;
			}
		}

		for( l = 0; l < velC; l++) {

			if(broj == nizC[l]) {
				pronadjenPuta++;
				break;
			}
		}

		if ( pronadjenPuta == 2) {
			rezultat++;
		}


	}

	return rezultat;

}

int main()
{
	int nizA[4] = {1,2,3,5};
	int nizB[5] = {1,2,4,6,7};
	int nizC[5] = {1,3,4,8,9,10};

	int rezultat = dva_od_tri(nizA, 4, nizB, 5, nizC, 6);

	printf("Broj pronadjenih brojeva je : %d", rezultat);

}