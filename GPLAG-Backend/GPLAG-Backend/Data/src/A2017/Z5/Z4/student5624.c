#include <stdio.h>
#include <stdlib.h>

struct predmet {
    char naziv[20];
    char ime_prezime_nastavnika[20];
    int semestar;
};

/* Funkcija vraca broj predmeta ciji naziv pocinje i zavrsava istim slovom 
 * (zanemarujuci razliku izmedju velikih i malih slova) */

int broj_isto_slovo(struct predmet* niz, int vel)
{
    int i, brojac=0;
    for (i=0; i<vel; i++) {
        char prvo = niz[i].naziv[0];

        char* s = niz[i].naziv;
        while (*s != '\0') s++;
        s--;
        char posljednje = *s;

        if (prvo >= 'A' && prvo <= 'Z') prvo += 32;
        if (posljednje >= 'A' && posljednje <= 'Z') posljednje += 32;

        if (prvo == posljednje)
            brojac++;
    }
    return brojac;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
