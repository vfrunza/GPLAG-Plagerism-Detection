#include <stdio.h>
//poor summer child...
//professor, we needed more time...

int daj_broj(int n)
{
    int broj_cifara = 0;

    if (n == 0) return 1;
    else if(n < 0) {
        broj_cifara++;
        n *= -1;
    }
    while(n != 0) {
        broj_cifara++;
        n /= 10;
    }
    return broj_cifara; //zbog razmaka iza -.-
}

char *ubaci_broj(char *tekst, int broj)
{
    char *s = tekst, *kraj = NULL, *p = NULL, *q = NULL, *r = NULL;
    int razmaci = 0, tmp, razmak = 1, brojac = 0, broj_rijeci = 0;

    while(*s != '\0') {
        if(*s == ' ') razmak = 1;
        else if(razmak == 1) {
            razmak = 0;
            brojac++;
        }
        s++;
    }

    s = tekst;
    razmak = 1;
    while (*s != '\0') {
        if(*s == ' ') razmak = 1;
        else if(razmak == 1) {
            razmak = 0;
            broj_rijeci++;
            if(broj_rijeci != brojac) {
                while(*s != '\0' && *s != ' ') s++;
                if(*s == '\0') return tekst;
                razmaci = 0;
                if(*(s + 1) == ' ') razmaci = 1;
                kraj = s;
                while(*kraj != '\0') kraj++;
                p = kraj;
                //p = --kraj;
                kraj += daj_broj(broj);
                if(razmaci == 0) kraj += 1;
                while( p != s) {
                    *kraj = *p;
                    p--;
                    kraj--;
                }
                /**kraj = '\0';
                q = --kraj;
                while(p != s) {
                    *q = *p;
                    q--;
                    p--;
                }*/
                if(broj < 0) {
                    *s = ' ';
                    s++;
                    *s = '-';
                    s += daj_broj(broj);
                } else s += daj_broj(broj)+1;
                *s = ' ';
                r = s;
                s--;
                tmp = broj;
                if(tmp < 0) tmp *= -1;

                while(tmp != 0) {
                    *s = tmp % 10 + '0';
                    tmp /= 10;
                    s--;
                }
                s = --r;
            }
        }
        s++;
    }
    return tekst;
}



int main()
{
/* AT5: Razmaci na pocetku stringa */
char s[57] = "     Ovaj string pocinje razmacima";
printf("\"%s\"", ubaci_broj(s, -98765));
    return 0;
}
