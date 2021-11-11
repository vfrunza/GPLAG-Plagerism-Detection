#include <stdio.h>
int daj_prost() {
    /* Funkcija koja vraća proste brojeve*/
    static int i=1;
    int j, prost=1;
    do {
        prost=1;
        i++;
        for (j=2; j<i; j++) {
            if (i%j==0) {
                prost=0;
                break;
            }
        }
    } while (prost==0);
    return i;
}
int main() {
    /* Ulaz i provjera da li su uneseni brojevi A i B u zadanom intervalu */
    int  A,B,x,s=0;
    do {
        printf ("\nUnesite brojeve A i B: ");
        scanf ("%d %d", &A, &B);
        if (A<1) {
            printf ("A nije prirodan broj.");
            continue; }
                if (A>=B) {
                    printf ("A nije manje od B.");
                    continue; }
                         if (B<1) {
                             printf ("B nije prirodan broj.");
                             continue; }
    } while(A<1 || B<1 || A>=B);
/* Pozivanje funkcije i racunanje sume prostih brojeva */
    do {
         x=daj_prost();
            if (x>A && x<B)
                s=s+x;
    } while (x<B);
     printf ("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	return 0;
}
