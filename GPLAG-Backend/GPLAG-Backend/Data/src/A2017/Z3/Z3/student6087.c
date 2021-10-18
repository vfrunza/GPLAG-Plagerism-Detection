#include <stdio.h>

int izbaci_cifre(int *niz1, int velicina1, int *cifre, int velicina2)
{
    int i,j,histogram[10] = {0},cifra,neg=0,a=0,ima_cifra,mnozilac;

    /*Uvjeti drugog niza*/
    for (i=0; i<velicina2; i++) {
        if(cifre[i] < 0 || cifre[i] > 9) {
            return 0;
            break;
        } else {
            histogram[cifre[i]]++;
        }
    }
    for (i=0; i<10; i++) {
        if (histogram[i]>1) {
            return 0;
            break;
        }
    }
    /*Izbacivanje*/
    for(i=0; i<velicina1; i++) {
        a = niz1[i];
        neg=0;
        niz1[i] = 0;
        if(a<0) {
            neg = 1;
            a *= -1;
        }
        mnozilac = 1;
        do {
            cifra = a % 10;
            ima_cifra = 0;
            a /= 10;
            for (j=0; j<velicina2; j++) {
                if(cifra == cifre[j]) {
                    ima_cifra = 1;
                    continue;
                }
            }
            if (ima_cifra == 1) {
                continue;
            }
            niz1[i] += cifra * mnozilac;
            mnozilac *= 10;
        } while(a != 0);
        if(neg == 1) {
            niz1[i] *= -1;
        }
    }
    return 1;
}



int main()
{
    int brojevi[100],cifre[100],i,vel1,vel2;

    printf("Unesite velicinu 1. i 2. niza: ");
    scanf("%d %d", &vel1, &vel2);

    printf("Unesite elemente 1. niza: ");
    for (i=0; i<vel1; i++) {
        scanf("%d", &brojevi[i]);
    }
    printf("\nUnesite elemente 2. niza: ");
    for (i=0; i<vel2; i++) {
        scanf("%d", &cifre[i]);
    }
    izbaci_cifre(brojevi,vel1,cifre,vel2);

    return 0;
}
