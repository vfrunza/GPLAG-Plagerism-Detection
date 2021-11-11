#include <stdio.h>

// Funkcija koja provjerava da li je broj prost

int prost(int a)
{

    int x = 1, i;

    if (a == 1)
        return 0;

    for (i = 2; i < a; i++) {
        if (a % i == 0) {
            x = 0;
            break;
        }
    }

    if (x)
        return 1;
    else
        return 0;
}

// Funkcija daj_prost koja nam svaki put vraca sljedeci prost broj

int daj_prost()
{
    // static int
    static int prost_broj = 2;

    // Petlja iz koje vracamo prost broj
    while (1) {
        if (prost(prost_broj))
            break;
        else
            prost_broj++;
    }
    // vracamo prost broj, a zatim ga povecavamo kako bi vratili sljedeci prost broj naredni put kada funkcija daj_prost bude pozvana
    return prost_broj++;
}

int main()
{

    int A, B, prost, suma = 0;

    // Unos brojeva A i B i provjera da li su u opsegu
    do {
        printf("\nUnesite brojeve A i B: ");
        scanf("%d %d", & A, & B);

        if (A < 1)
            printf("A nije prirodan broj.");
        else if (A >= B)
            printf("A nije manje od B.");
        else if (B < 1)
            printf("B nije prirodan broj.");
    } while (A >= B || A < 1 || B < 1);

    // Racunanje sume izmedju A i B
    while (1) {
        prost = daj_prost();

        if (prost > A && prost < B)
            suma = suma + prost;

        if (prost >= B)
            break;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

    return 0;
}
