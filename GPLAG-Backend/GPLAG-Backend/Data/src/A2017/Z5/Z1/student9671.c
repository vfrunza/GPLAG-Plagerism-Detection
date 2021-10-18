#include <stdio.h>
#include <stdlib.h>


struct Datum { int dan, mjesec, godina; };
struct Uposlenik
{
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};

/* Ova funkcija trazi rijec na ciji pocetak pokazuje s2 u stringu na ciji pocetak
    pokazuje s1 i vraca pokazivac jedno mjesto iza rijeci ako je pronadje, a u suprotnom vraca NULL pokazivac */
char* trazi_rijec(char* s1, char* s2)
{
    int pocetak=1;
    char* p=s1;
    char* q=s2;

    while(*s1!='\0')
    {
        while(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')))
        {
            s1++;
            pocetak=0;
        }
        p=s1;
        q=s2;
        while(*p==*q || *p==*q+32 || *p+32==*q)
        {
            p++;
            q++;
            if(pocetak==0 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0') && !((*(s1-1)>='A' && *(s1-1)<='Z') || (*(s1-1)>='a' && *(s1-1)<='z')))  return p;
            if(pocetak==1 && *q=='\0' && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) || *p=='\0')) return p;
        }
        s1++;
        pocetak=0;
    }
    return NULL;
}

int izracunaj_prestupne_godine(struct Datum d)
{
    int godine = d.godina;

    if (d.mjesec <= 2)
        godine--;
    return godine / 4 - godine / 100 + godine / 400;
}

int daj_broj_dana(struct Datum dt1, struct Datum dt2)
{
    int i = 0;
    int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int n1 = dt1.godina*365 + dt1.dan;

    for (i=0; i<dt1.mjesec - 1; i++)
        n1 += broj_dana[i];

    n1 += izracunaj_prestupne_godine(dt1);

    long int n2 = dt2.godina*365 + dt2.dan;
    for (i=0; i<dt2.mjesec - 1; i++)
        n2 += broj_dana[i];
    n2 += izracunaj_prestupne_godine(dt2);

    return (n2 - n1);
}

/* Ova funkcija vraca pokazivac na pocetak prezimena */
char* daj_prezime(char* d)
{
    char* d_pom;
    while(*d!=' ')
        d++;
    d++;
    d_pom = d;
    while(*d!=' ' && *d!='\0' && *d!='-')
        d++;
    if(*d=='\0' || *d=='-') return d_pom;
    else
    {
        d++;
        d_pom = d;
        while(*d!='\0' && *d!='-')
            d++;
        if(*d=='\0' || *d=='-') return d_pom;
    }
    return NULL;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
    int i = 0, j=0;
    char n[50];
    char *p, *d, *d_pom, *s = n, *pom;
    for(i=0; i<vel; i++)
    {
        p = daj_prezime(kandidati[i].ime_prezime);
        d = daj_prezime(direktor.ime_prezime);
        if(broj_dana > 0 && daj_broj_dana(kandidati[i].datum_rodjenja, direktor.datum_rodjenja)>broj_dana)
        {

            pom = p;
            while(*p!='\0' && *p!='-')
                p++;
            if(*p=='\0')
            {
                if(trazi_rijec(d, pom)==NULL)
                {
                    for(j=i; j<vel-1; j++)
                        kandidati[j] = kandidati[j+1];
                    vel--;
                    i--;
                }
            }
            else
            {
                p = pom;
                d_pom = s;
                while(*p!='-')
                {
                   *s = *p;
                   s++;
                   p++;
                }
                *s='\0';
                p++;
                if(trazi_rijec(d, d_pom)==NULL && trazi_rijec(d, p)==NULL)
                {
                    for(j=i; j<vel-1; j++)
                        kandidati[j] = kandidati[j+1];
                    vel--;
                    i--;
                }
            }
        }
        else if (broj_dana < 0 && daj_broj_dana(kandidati[i].datum_rodjenja, direktor.datum_rodjenja)*(-1)<broj_dana*(-1))
        {
            pom = p;
            while(*p!='\0' && *p!='-')
                p++;
            if(*p=='\0')
            {
                if(trazi_rijec(d, pom)==NULL)
                {
                    for(j=i; j<vel-1; j++)
                        kandidati[j] = kandidati[j+1];
                    vel--;
                    i--;
                }
            }
            else
            {
                p = pom;
                d_pom = s;
                while(*p!='-')
                {
                   *s = *p;
                   s++;
                   p++;
                }
                *s='\0';
                p++;
                if(trazi_rijec(d, d_pom)==NULL && trazi_rijec(d, p)==NULL)
                {
                    for(j=i; j<vel-1; j++)
                        kandidati[j] = kandidati[j+1];
                    vel--;
                    i--;
                }
            }
        }
    }
    return vel;
}

int main()
{
  struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 10, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljc", { 15, 1, 1992 } },
};

int novi_br = suzi_listu(kandidati, 0, direktor, 15);
int i;
printf("Novi broj: %d\n", novi_br);

/* Ispravka za funkcije koje ne rade nista */
novi_br = suzi_listu(kandidati, 7, direktor, 15);
printf("Novi broj: %d\n", novi_br);
    return 0;
}
