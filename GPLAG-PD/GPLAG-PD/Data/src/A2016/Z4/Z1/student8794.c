#include <stdio.h>

//Zadaca 4 by @WhiteBl4ck

// Zadatak 1.


//Funkcija koja poredi dvije rijeci i vraca nam logicku istinu (1,0)
int PorediRijeci(char* s1, char* s2)
{
    char* p = s1;
    char* q = s2;
    char temp1, temp2;
    int x = 1;                      // Postavljamo logicnu var. x na istinu

    while (((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) && *p != '\0' && *q != '\0') {
        temp1 = *p;
        temp2 = *q;

        if (temp1 >= 'A' && temp1 <= 'Z')
            temp1 = temp1 + 32;

        if (temp2 >= 'A' && temp2 <= 'Z')
            temp2 = temp2 + 32;

        if (temp1 != temp2) {
            x = 0;
            break;
        }
        p++;
        q++;
    }
    if (x) {

        if (((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) || ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) )
            x = 0;
    }

    return x;

}
//Funkcija podstring koja nam vraca broj ponavljanja neke rijeci u stringu

int podstring(char* s1, char* s2, int vel)
{
    char temp1, temp2;
    char* poc = s1;
    int brojac = 0;                 // Postavljamo brojac na nulu

    while (*s1 != '\0') {

        char* p = s1;
        char* q = s2;
        temp1 = *p;
        temp2 = *q;

        if (temp1 >= 'A' && temp1 <= 'Z')
            temp1 = temp1 + 32;

        if (temp2 >= 'A' && temp2 <= 'Z')
            temp2 = temp2 + 32;

        while (temp1 == temp2) {
            p++;
            q++;
            temp1 = *p;
            temp2 = *q;

            if ((q == s2 + vel) && (s1 == poc ||  (!((*(s1-1) >= 'A' && *(s1-1) <= 'Z') || (*(s1-1) >= 'a' && *(s1-1) <= 'z')))) && ((!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))) || *p ==  '\0')) {
                brojac++;
                break;
            } else if (q == s2 + vel)
                break;
        }
        s1++;
    }
    return brojac;
}

// fukncija prima string i vraca nam pokazivac na rijec koja se najvise pojavljiva

char* Rijec_naj(char* s)
{
    int brojac_rijeci = 0;
    int max_repeat;                         // Maximalni broj ponavljanja rijeci u stringu
    int num_repeats;                        // Broj ponavljanja rijeci u stringu
    int vel_r;
    char* poc = NULL;                       // Pokazivac na pocetak rijeci
    char* kraj = NULL;                      // Pokazivac na kraj rijeci
    char* poc_max = NULL;                   // Pokazivac na rijec sa max broj ponavljanja
    char* kop_poc = s;                      //

    int flag = 1, flag2 = 1;

    while(*s != '\0') {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
            brojac_rijeci++;
            flag = 1;
            while ((*s != '\0') && ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
                if (flag) {
                    poc = s;
                    flag = 0;
                }
                s++;
            }
            kraj = s;

            //Prva rijec u stringu , cuvamo velicinu rijeci i broj ponavljanja
            if (flag2) {

                vel_r = kraj - poc;
                max_repeat = podstring(kop_poc,poc,vel_r);
                poc_max = poc;
                flag2 = 0;

            } else if (PorediRijeci(poc_max,poc)) {         // Ako su rijeci iste, postavljamo drugu na "rijec sa max broj ponavljanja"
                poc_max = poc;

            } else {                                        // Provjeravamo da li se trenutna rijec vise ponavlja od rijeci sa max broj ponavljanja

                vel_r = kraj - poc;
                num_repeats = podstring(kop_poc,poc,vel_r);
                if (num_repeats > max_repeat) {

                    max_repeat = num_repeats;
                    poc_max = poc;
                }
            }

            if( *s == '\0')
                break;
        }
        s++;
    }
    if (brojac_rijeci == 0)   //Ako nema rijeci u stringu vracamo NULL pokazivac
        return NULL;
    return poc_max;
}

// Funkcija prima stringu i n-tu po redu rijec koju izbaciva iz stringa

char* izbaci_rijec(char* s, int n)
{
    char* kop_poc = s;          //cuvamo kopiju pocetka stringa
    int brojac = 0;            // brojac za rijeci
    int flag = 0;
    char* poc = NULL;
    char* kraj = NULL;

    while(*s != '\0') {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
            brojac++;
            flag = 1;
            while (((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))&& *s != '\0') {
                if (flag) {
                    poc = s;
                    flag = 0;
                }
                s++;
            }
            kraj = s;               // izbacivamo n-tu rijec iz stringa
            if (brojac == n) {
                while (((*(poc++)) = (*(kraj++))));
            }
            if(*s == '\0')
                break;
        }
        s++;
    }
    return kop_poc;                 // vracamo pokazivac na pocetak
}

// Funkcija koja nam vraca duzinu rijeci

int duz_r(char* s)
{
    int  duzina = 0;

    while (((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0') {
        duzina++;
        s++;
    }
    return duzina;
}

// Funkcija koja izbaciva najcescu rijec //

char* izbaci_najcescu(char* s)
{
    char* s3 = Rijec_naj(s);                    // pokazivac na rijec koja se najvise ponavlja
    if (s3 == NULL)                             //ako nema rijeci prekidamo program
        return s;                               //

    int duzina_rijeci = duz_r(s3);

    char* poc = NULL;
    char* kop_poc = s;
    int flag = 0;                       // postavljamo pokazivac na pocetak rijeci
    int flag1 = 0;                      // kada je rijec sa max broj ponavljanja jedina u stringu izbacivamo je i zaustavljamo program
    int brojac = 0;                     // brojac rijeci
    //
    while(*s != '\0') {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
            brojac++;
            flag = 1;
            while (((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0') {
                if (flag) {
                    poc = s;
                    flag = 0;
                }
                s++;
            }
            if (poc == s3)                          // ako je rijec sa max broj ponavljanja jedina u stringu
                flag1 = 1;
            if(PorediRijeci(s3,poc)) {              // poredimo trenutnu rijec sa "rijec sa max broj ponavljanja", ako su iste izbacivamo rijec

                izbaci_rijec(kop_poc,brojac);       // sve pokazivace vracamo za duzinu smanjenog stringa
                s = s - duzina_rijeci;             // smanjivamo broj rijeci za 1
                brojac--;
                s3 = s3 - duzina_rijeci;
            }
            if (flag1)
                break;
            if (*s == '\0')
                break;
        }
        if (flag1)
            break;
        s++;
    }
    return kop_poc;             // vracamo pokazivac na pocetak stringa
}

//  C++ ya next time :D

int main()
{

    return 0;
}
