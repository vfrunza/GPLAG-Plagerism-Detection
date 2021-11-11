#include <stdio.h>

//Zadaca 4 by @WhiteBl4ck

// Zadatak 3.
//Funkcija koja nam vraca duzinu rijeci
int DuzinaRj(char* s)
{
    int duz = 0;

    while (*s != ' ' && *s != '\0') {
        duz ++;
        s++;
    }
    return duz;
}
//Funkcija koja zamijenjuje dvije rijeci
//Funkcija prima string i dva pokazivaca , pokazivac na rijec u stringu koju mjenjamo, i pokazivac na rijec sa kojom mjenjamo
void zamijeni1(char* s, char* rijec_org, char* rijec_zamijeni )
{
    // kada mjenjamo rijeci u stringu postoje 3 uslova
    // 1.) Da su rijeci iste duzine rijec           // duzina stringa ostaje ista
    // 2.) Da je prva rijeci duza od druge          // duzina stringa se smanjuje
    // 3.) Da je druga rijec duza od prve           // duzina stringa se povecava
    
    char* p = rijec_org;
    char* q = rijec_zamijeni;
    int duzina = DuzinaRj(rijec_org) - DuzinaRj(rijec_zamijeni);    // duzina = razlika duzina prve i druge rijeci
    
    if (duzina == 0 ) {                             //duzina stringa ostaje ista
        while (*p != ' ' && *p != '\0') {           //preko prve rijeci upisujemo drugu (brisuci prvu)
            *p = *q;
            p++;
            q++;
        }
    } else if ( duzina > 0) {                       //duzina stringa se smanjuje
        while(*p != ' ' && *p != '\0')              //preko prve upisujemo drugu rijeci
            p++;
        char* poc = p - duzina;             
        char* kraj = p;
        while ((*poc++ = *kraj++));
        p = rijec_org;
        q = rijec_zamijeni;
        while (*p != ' ' && *p != '\0') {
            *p = *q;
            p++;
            q++;
        }
    } else if (duzina < 0) {                        //duzina stringa se povecava
                                                    //preko prve upisujemo drugu rijeci
        while(*p != ' ' && *p != '\0')
            p++;
        char* poc = p;
        char* kraj = s;
        while (*kraj != '\0')
            kraj++;

        while (kraj >= poc) {
            *(kraj-duzina) = *kraj;
            kraj--;
        }
        p = rijec_org;
        q = rijec_zamijeni;
        while (*q != ' ' && *q != '\0' ) {
            *p = *q;
            p++;
            q++;
        }
    }
}

//Funkcija koja prvima dvije rijeci i poredi ih vraca nam logicku istinu
int PrdRj(char* s1, char* s2)
{

    char* p = s1, *q = s2;

    int x = 1;
    while ((*p != ' ' && *p != '\0') && (*q != ' ' && *q != '\0') ) {
        if (*p != *q) {
            x = 0;
            break;
        }
        p++;
        q++;
    }
    if (x) {

        if ((*p != ' ' && *p != '\0') || (*q != ' ' && *q != '\0'))
            x = 0;
    }
    return x;
}
//Funkcija koja prima tekst i dva pokazivaca na nizove rijeci , rijeci koje mjenjamo i rijeci sa kojima mjenjamo
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
    char* p = tekst;
    char* s = tekst;
    char* poc = NULL;
    int i;
    
    while(*s != '\0') {
        if (*s != ' ') {
            poc = s;
            while (*s != ' ' && *s != '\0')
                s++;
            for (i = 0; i < broj_rijeci; i++) {                                 //provjeravamo da li se u tekstu nalazi rijec iz niza rijeci

                if (PrdRj(poc,rijeci[i])) {                                     //kada zamjenimo rijeci pokazivace vracamo za promjenjenu duzinu
                    int duzina = DuzinaRj(rijeci[i]) - DuzinaRj(zamjene[i]);
                    zamijeni1(tekst,poc,zamjene[i]);
                    s = s - duzina;
                }
            }
            if (*s == '\0')
                break;
        }
        s++;
    }

    return p;
}

int main()
{

    return 0;
}
