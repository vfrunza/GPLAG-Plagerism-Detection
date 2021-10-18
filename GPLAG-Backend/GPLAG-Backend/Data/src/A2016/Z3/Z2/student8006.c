#include <stdio.h>
#include <math.h>


/* Najprije nam treba funkcija koja ce sabrati sve cifre broja. 
    Mogli bi to raditi i unutar funkcije, ali ovako je lakse */ 
int Zbir_cifara ( int broj )
{
    int cifra = 0, suma = 0;

    while ( broj != 0 ) {

        cifra = fabs( broj % 10 );
        broj /= 10;
        suma += cifra;

    }

    return suma;

}

/* Funkcija ispod ukratko radi sljedece:
Prva petlja sluzi da bi bukvalno povecali broj clanova jer nam treba tacno jedno mjesto poslije svakog clana 
Druga petlja sluzi da bi popunili "prazna mjesta", sto je i evidentno jer i ne raste za 1 nego za 2*/
void ubaci ( int *niz, int velicina )
{
    int i;

    for( i = velicina - 1; i >= 0; i--) {
        niz[2 * i]=niz[i];
    }

    for( i = 1; i < 2 * velicina; i += 2) {
        niz[i] = Zbir_cifara( niz[i - 1] );
    }

}

/* Iako ne radi kako treba, idejno bi sljedeca funkcija trebala da generice 100 fibonacijevih brojeva, i zatim svaki clan ubacenog niza 
provjeri, tj provjeri da li je jednak nekom od clanova fibonacijevog niza i ako jeste, izbaci ga*/ 

int izbaci ( int *niz, int velicina )
{
    int i, fibonaci[100], j, k;

    fibonaci[0]=0;
    fibonaci[1]=1;

    for ( i = 2; i < 100; i++ ) {
        fibonaci[i] = fibonaci[i-2] + fibonaci[i-1];
    }

    for ( j = 0; j < velicina; j++ ) {
        for ( i = 0; i < 100; i++) {

            if ( niz[i] == fibonaci[j] ) {
                for( k = 0; k < velicina; k++) {
                    niz[k] = niz [k + 1];
                }

                k--;
                velicina--;
            }


        }

    }


    return velicina;
}



int main()
{

    int i, broj, zbircifara, niz[10];

    scanf ( "%i", &broj );

    zbircifara = Zbir_cifara(broj);

    printf ("%i\n", zbircifara);


    for ( i = 0; i < 10; i++ ) {
        scanf ( "%i", &niz[i]);
    }



    return 0;
}
