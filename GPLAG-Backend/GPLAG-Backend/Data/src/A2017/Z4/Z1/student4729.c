#include <stdio.h>

void unesi (char niz[], int velicina)
{
    char znak = getchar ();
    if (znak =='\n') znak = getchar ();
    int i = 0;
    while ( i<velicina - 1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar ();
    }

    niz[i] = '\0';
}


char* ubaci_broj (char* tekst, int broj)
{
    int n,predznak;
    char *p, *q, *end;
    if (broj<0) {
        predznak = -1;
        broj = -broj;
    } else {
        predznak = 1;
    }
    end = tekst;
    while (*end != '\0')
        end++;
    for (p = tekst; p < end; p++) {
        if (*p == ' ') {
            p++;
            if (*p != ' ') {
                for (q = end; q >= p; q--)
                    *(q+1) = *q;
                end++;
                *p = ' ';
            }
            for (n = broj; n > 0; n = n / 10) {
                for (q = end; q >= p; q--)
                    *(q+1) = *q;
                end++;
                *p = (n % 10) + '0';

            }
            if (predznak < 0) {
                for (q = end; q >= p; q--)
                    *(q+1) = *q;
                *p = '-';
                end++;
            }
            while (*p != ' ')
                p++;
            while (*p == ' ')
                p++;
        }
    }
    return tekst;
}

int main()
{
    char neki_tekst [100];
    int br;
    printf ("Unesite broj: ");
    scanf ("%d", &br);
    unesi (neki_tekst, 100);
    printf (" %s\n ",  ubaci_broj (neki_tekst , br) );
    return 0;
}
