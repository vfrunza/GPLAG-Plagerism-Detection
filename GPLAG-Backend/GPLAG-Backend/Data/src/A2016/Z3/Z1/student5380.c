#include <stdio.h>

int daj_prost ()
{

    static int prost=1;
    int i, brprost=0;

    do {
        brprost=0;
        prost++;
        for (i=1; i<=prost; i++) {
            if (prost%i==0) {
                brprost++;
            }
        }
    } while (brprost !=2);   /*provjeravanje prostog broja*/
    return prost;
}

int main ()
{
    int brojA,brojB,suma=0,broj;

    do {
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &brojA, &brojB);
        if (brojA<=0)
            printf ("A nije prirodan broj.\n");
        else if (brojA>=brojB)
            printf ("A nije manje od B.\n");
    } while
    (brojA<=0 || brojA>=brojB);    /*unos*/

    do {
        broj = daj_prost();   /*pozivanje f-je daj_prost*/
        if ((broj>brojA) &&(broj<brojB))
            suma+=broj;
    }

    while (broj<brojB);
    printf ("Suma prostih brojeva izmedju %d i %d je %d.", brojA,brojB,suma);



    return 0;

}
