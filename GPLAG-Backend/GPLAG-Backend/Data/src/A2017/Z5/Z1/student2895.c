#include <stdio.h>

struct Datum {
    int dan, mjesec, godina;
};
struct Uposlenik {
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};
char *prezime(struct Uposlenik osoba)
{
    int broj_rijeci = 0, razmak =  1;
    char *s = osoba.ime_prezime;
    char prezime1[50], prezime2[50];
    char *p1 = prezime1, *p2 = prezime2;

    while(*s != '\0') {
        if(!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))) neslovo = 1;
        else if(neslovo) {
            neslovo = 0;
            broj_rijeci++;
        }
        s++;
    }
    s = osoba.ime_prezime;
    if(broj_rijeci == 2) {
        while((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) s++;
        if(*s != '\0') s++;
        while(*s != '\0') {
            *p1 = *s;
            p1++;
            s++;
        }
        *p1 = '\0';
    }


}

/*int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{

}*/
