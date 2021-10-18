#include <stdio.h>

int provjeri_duzine (char* s, int niz[], int vel)
{
    int brojSlova=0, temp=0;

    while (*s!='\0' && temp<vel) {
        /*Prodji pokazivacem kroz karaktere ili razmake koji ne predstavljaju rijec*/
        while (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z' )) {
            if (*s!='\0') {
                s++;
            } else {
                return 0;
            }
        }
        /*Prodji pokazivacem kroz karaktere (slova) koji cine rijec i prebroji slova*/
        while (*s>='A' && *s<='Z' || *s>='a' && *s<='z' ) {
            brojSlova++;
            if (*s!='\0') {
                s++;
            } else {
                return 0;
            }

        }
        /*Ako je broj iz niza razlicit od broja slova vrati 0, u suprotnom postavi broj slova na 0 i nastavi prebrojavati slova*/
        if (niz[temp]!=brojSlova)
            return 0;
        brojSlova=0;
        temp++;
    }
    if (*s!='\0') {
        s++;
    }

    if (*s!='\0') {
        return 0;
    }

    if (temp<vel) {
        return 0;
    }


    else {
        return 1;
    }
}

int main ()
{
    char tekst[100];
    int niz[100];
    int vel;
    printf("%d ", provjeri_duzine(tekst, niz, vel));
    return 0;
}
