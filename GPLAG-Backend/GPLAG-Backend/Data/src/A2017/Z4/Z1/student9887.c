#include <stdio.h>
#include <math.h>

void unesi(char niz[], int velicina)
{

    int i = 0;
    char znak = getchar();

    if (znak == '\n')
        znak = getchar();

    while (i < velicina - 1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}


int duzina_broja(int broj)
{
    int duz_br = 1;
    if(broj < 0) duz_br++;

    broj = broj / 10;

    while (broj != 0) {
        duz_br++;
        broj = broj / 10;
    }

    return duz_br;
}

int obrnut(int p)
{
    int cifra, novi_broj, k = 1, broj;

    broj = fabs(p);
    cifra = broj % 10;
    novi_broj = cifra * k;
    broj /= 10;
    k *= 10;

    while (broj != 0) {
        cifra = broj % 10;
        novi_broj = novi_broj * k + cifra;
        broj /= 10;
    }
    return novi_broj;
}

int broj_rijeci(char *tekst)
{
    int broj=0;
    while(*tekst!='\0') {
        if(*tekst!=' ' && (*(tekst+1)==' ' || *(tekst+1)=='\0')) {
            broj++;
            tekst++;
        } else {
            tekst++;
        }
    }
    return broj;
}

char* ubaci_broj(char* tekst, int broj)
{
    char* s = tekst;
    int duzina=0, br_razmaka=0, cifra, vrijednost=0, p, k=0, b_rijeci;

    if (broj % 10 == 0)
        vrijednost = 1;
    b_rijeci=broj_rijeci(tekst);
    while (*tekst != '\0') {
        if (*tekst != ' ' && *(tekst + 1) == ' ') {
            char* razmak=tekst;
            char* kraj=++tekst;
            br_razmaka=0;
            while(*(razmak+1)==' ') {
                br_razmaka++;
                razmak++;
                if(*(razmak+1)!=' ') break;
            }
            if(br_razmaka>1) duzina=duzina_broja(broj);
            else if(br_razmaka==1) duzina=duzina_broja(broj)+1;
            k++;
            if(k==b_rijeci) break;
            while (*kraj != '\0')
                kraj++;

            while(kraj>tekst) {
                *(kraj+duzina)=*kraj;
                kraj--;
            }


            tekst++;
            if(broj<0) {
                *tekst='-';
                tekst++;
            }
            p=obrnut(broj);
            while(p!=0) {
                cifra=p%10;
                p=p/10;
                *tekst='0' + cifra;
                tekst++;
            }
            if(vrijednost) {
                *tekst='0';
                tekst++;
            }
            if(br_razmaka==1) {
                *tekst=' ';
                tekst++;
            }
        } else {
            tekst++;
        }

    }
    return s;
}

int main()
{
    char s[50];
    int k;
    printf("Unesi tekst: ");
    unesi(s, 50);
    k=broj_rijeci(s);
    printf("%d", k);
    printf("evo j: %s", ubaci_broj(s, 1));
    return 0;
}
