#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void izbaci_rijec(char* s, char* s2, int vel)
{
    char *poc = s2;
    char *kraj = s2+vel;
    while ((*poc++ = *kraj++));
}
//Funkcija koja pretvara string u float
float s_to_f(char *niz)
{
    char *p = niz;
    char *d = niz;

    float suma = 0;
    int cifra ;
    int brojCifaraizatacke = 0;
    int predznak = 0;

    int decimalan = 0;
    int i = 0;

    //provjeravamo je li broj negativan
    if(*p == '-') {
        predznak = 1;
        p++;
    }
    //PRVO CEMO PROVJERITI DA LI JE BROJ UOPSTE DECIMALAN
    while(*d != '\0') {
        if(*d == '.') {
            decimalan = 1;
        }
        d++;
    }
    // ako jeste decimalan radi sljedece
    if(decimalan == 1) {
        while(*p != '\0') {
            if(*p == '.') {
                //postavljamo q na sljedece mjesto od tacke
                char *q = p+1;
                //s ovom petljom odredujemo kolko je cifara iza tacke jer q na pocetku pokazuje na prvo mjesto iza tacke
                while(*q != '\0') {
                    brojCifaraizatacke++;
                    q++;
                }
            }
            p++;
        }
        //sada p pokazuje na jedno mjesto iza niza pa ga moramo vratiti
        p--;
        //idemo odzada broja sve dok ne dodjemo na znak .
        while(*p != '.') {
            cifra = *p - '0';
            suma += cifra/(float)(pow(10,brojCifaraizatacke));
            brojCifaraizatacke--;
            p--;
        }
        //p sad pokazuje tacno na broj ispred tacke
        p--;
        //ako je broj pozitivan
        if(predznak == 0) {
            do {
                //npr asci kod cvrke je 52 pa oduzimamo asci kod 0(koji je 48) da dobijemo 4
                cifra = *p - '0';
                suma +=cifra*pow(10,i);
                i++;
                p--;
            } while(p != niz-1);
            //petlja ide do niz-1 jer se inace ne bi ispunila za prvi broj...
        } else {
            do {
                cifra = *p - '0';
                suma +=cifra*pow(10,i);
                i++;
                p--;
            } while(p != niz);   //posto je znak minus ispred petlja ide samo od niz
        }
        if(predznak == 0) {
            return suma;
        }
        return -suma;
    }
    //AAKO NIJE DECIMALAN
    if(decimalan == 0) {
        while(*p != '\0') {
            p++;
        }
        //sada pe pokazuje iza niza pa ga mroamo vratit
        p--;
        if(predznak == 0) {
            while(p != niz-1) {
                cifra = *p - '0';
                suma +=cifra*pow(10,i);
                i++;
                p--;
            }
        } else {
            while(p != niz) {
                cifra = *p - '0';
                suma +=cifra*pow(10,i);
                i++;
                p--;
            }
        }
    }

    if(predznak == 0) {
        return suma;
    }
    return -suma;
}
// Funkcija koja nam vraca duzinu jedne tacke sa kordinatama npr. (2.3,-3.6) duzina 10
int duzina(char* s)
{
    int brojac = 1;
    while(*s != '\0' && *s != ')') {
        brojac++;
        s++;
    }
    s++;
    if (*s == ',') {
        brojac++;
    }
    return brojac;
}
//Funkcija koja prima niz tacaka (kordinate x, y) i 4 realna broja koji prave pravougaonik u ravni i izbaciva sve tacke koje nisu unutar pravougaonika
char *obuhvat(char *s, float x1, float y1, float x2, float y2)
{

    char *kopija_poc = s;
    int x = 1;          // Postavljamo uslov da je string dobro unesenes
    int tacka = 0;      // Uslov za tacku

    if (*s == '\0') {
        return s;
    }

    do {

        x = 1;
        tacka = 0;
        // Provjeravamo prvi realan broj, koji mora pocinjati sa otvorenom zagradom a zavrsavati zarezom
        // Provjeravamo da li string pocinje otvorenom zagradom
        if (*s != '(') {
            x = 0;
            break;
        } else {
            s++;
        }
        if (*s == '-') {
            s ++;
        }
        if (!(*s  >= '0' && *s  <= '9')) {
            x = 0;
            break;
        }
        while (1) {

            // Provjeravmo negativne brojeve

            if (*s == '.' && tacka == 1) {
                x = 0;
                break;
            } else if (*s == '.' && (*(s -1) >= '0' && *(s -1) <= '9')) {
                tacka = 1;
            } else if (*s == ',' && ((*(s -1) >= '0' && *(s -1) <= '9') || *(s -1) == '.' )) {
                break;
            } else if (*s  == ',') {
                x = 0;
                break;
            } else if (!(*s  >= '0' && *s  <= '9')) {
                x = 0;
                break;
            }
            s++;
        }

        if ( x == 0) {
            break;
        }

        x = 1;
        tacka = 0;

        // Provjeravamo drugi realan broj, koji mora pocinjati sa zarezom a zavrsavati zatvorenom zagradom
        // Provjeravamo da li string pocinje sa zarezom
        if (*s  != ',') {
            x = 0;
            break;
        } else {
            s++;
        }
        if (*s  == '-') {
            s ++;
        }
        if (!(*s  >= '0' && *s  <= '9')) {
            x = 0;
            break;
        }
        while (1) {

            if (*s  == '.' && tacka == 1) {
                x = 0;
                break;
            } else if (*s  == '.' && (*(s -1) >= '0' && *(s -1) <= '9')) {
                tacka = 1;
            } else if (*s  == ')' && ((*(s -1) >= '0' && *(s -1) <= '9') || *(s -1) == '.' )) {

                break;
            } else if (*s  == ')') {
                x = 0;
                break;
            } else if (!(*s  >= '0' && *s  <= '9')) {
                x = 0;
                break;
            }

            if (*s == '\0')
                break;
            s++;
        }
        if (*s == '\0')
            break;
        s++;
        if ( *s == '\0' || *s == ',') {
            if (*s == '\0') {
                break;
            } else {
                s++;
            }
        } else {                    // ukoliko string nije dobro unesen vracamo NULL pokazivac i zavrsavamo program
            return NULL;
        }
    } while (1);

    if ( x == 0) {
        return NULL;
    }
    // Ako je string ispravno unesen izbacivamo sve tacke van opsega pravougaonika
    char *a = kopija_poc;       // pokazivac a postavljamo na pocetak stringa (niz tacaka sa kordinatama), i njime prolazimo kroz cijeli string
    char r_broj_x[100];         // string u kojem cuvamo kordinate tacke kako bi ih pretvorili u float
    char r_broj_y[100];
    char *b = r_broj_x;         // pokazivacem b prolazimo kroz kordinatu x i kopiramo je u r_broj_x
    char *c = r_broj_y;         // pokazivacem c prolazimo kroz kordinatu y i kopiramo je u r_broj_y
    char *poc_tacke;            // cuvamo pocetak tacke ukoliko je uslov zadovoljen da je mozemo izbaciti iz stringa
    int duzina_tacke;
    int izbaci = 0;

    while (*a != '\0') {
        if (*a == '(') {
            izbaci = 0;
            poc_tacke = a;
            duzina_tacke = duzina(poc_tacke);
            if (*(a+duzina_tacke) == '\0' && a != kopija_poc ) {
                poc_tacke = a - 1;
                duzina_tacke++;
            }
            a++;
            b = r_broj_x;
            
            while(*a != ',' && *a != '\0') {
                *b = *a;
                a++;
                b++;
            }
            *b = '\0';

            if (s_to_f(r_broj_x) < x1 || s_to_f(r_broj_x) > x2) {               // provjeravamo da li je tacka u opsegu pravougaonika 
                izbaci = 1;
            }
            a++;
            c = r_broj_y;
            
            while(*a != ')') {
                *c = *a;
                a++;
                c++;
            }
            *c = '\0';

            if (s_to_f(r_broj_y) < y1 || s_to_f(r_broj_y) > y2) {               // provjeravamo da li je tacka u opsegu pravougaonika 
                izbaci = 1;
            }
            if (izbaci) {
                izbaci_rijec(kopija_poc,poc_tacke,duzina_tacke);                // nakon izbacivanja tacke pokazivac vracamo na pocetak stringa i smanjivamo ga za 1
                a = kopija_poc;                                                 // zbog a++, kako bi provjerili pocetni element
                a--;
            }
        }
        a++;
    }
    return kopija_poc;          // vracamo pokazivac na pocetak stringa
}

int main() {

	return 0;
}
