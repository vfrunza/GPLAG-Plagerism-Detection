#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL char
#define FALSE 0
#define TRUE 1

#define epsilon 0.0001

char* obuhvat(char* string, double x1, double y1, double x2, double y2) {
    char *pocetak = string;
    char *pocetakTacke, *krajTacke, *temp;
    double x, y;
    BOOL tacka;
    int cifra;
    int predznak;
    while(*string != '\0') {
        if(*string == '(') {
            /* ili je na pocetku, ili joj mora prethoditi zarez */
            if(!(string == pocetak || *(string - 1) == ',')) {
                pocetak = 0;
                return pocetak;
            }
            pocetakTacke = string;
            string++;
            x = 0;
            tacka = FALSE;
            cifra = 1;
            if(*string == '-') {
                predznak = -1;
                string++;
            }
            else
                predznak = 1;
            /* mora postojati barem jedna cifra */
            if(!(*string >= '0' && *string <= '9')) {
                pocetak = 0;
                return pocetak;
            }
            while(*string != ',') {
                /* ako nije cifra, ili ako se ponavlja tacka */
                if(!((*string >= '0' && *string <= '9') || (*string == '.' && tacka == FALSE))) {
                    pocetak = 0;
                    return pocetak;
                }
                if(*string == '.') {
                    /* mora joj prethoditi cifra */
                    if(!(*(string - 1) >= '0' && *(string - 1) <= '9')) {
                        pocetak = 0;
                        return pocetak;
                    }
                    tacka = TRUE;
                    string++;
                }
                else if(!tacka) {
                    x = 10*x + (*string - '0');
                    string++;
                }
                else if(tacka) {
                    x = x + (*string - '0')/pow(10, cifra);
                    cifra++;
                    string++;
                }
            }
            x *= predznak;
            string++;
            y = 0;
            tacka = FALSE;
            cifra = 1;
            if(*string == '-') {
                predznak = -1;
                string++;
            }
            else
                predznak = 1;
            /* mora postojati barem jedna cifra */
            if(!(*string >= '0' && *string <= '9')) {
                pocetak = 0;
                return pocetak;
            }
            while(*string != ')') {
                /* ako nije cifra, ili ako se ponavlja tacka */
                if(!((*string >= '0' && *string <= '9') || (*string == '.' && tacka == FALSE))) {
                    pocetak = 0;
                    return pocetak;
                }
                if(*string == '.') {
                    /* mora joj prethoditi cifra */
                    if(!(*(string - 1) >= '0' && *(string - 1) <= '9')) {
                        pocetak = 0;
                        return pocetak;
                    }
                    tacka = TRUE; 
                    string++;
                }
                else if(!tacka) {
                    y = 10*y + (*string - '0');
                    string++;
                }
                else if(tacka) {
                    y = y + (*string - '0')/pow(10, cifra);
                    cifra++;
                    string++;
                }
            }
            y *= predznak;

            krajTacke = string;
            if(x < x1 || x > x2 || y < y1 || y > y2) {
                /* izbacivanje tacke */
                while(krajTacke != pocetakTacke - 1) {
                    temp = krajTacke;
                    while(*temp != '\0') {
                        temp++;
                        *(temp-1) = *temp;
                    }
                    krajTacke--;
                }
                if(*pocetakTacke == ',') {
                    temp = pocetakTacke;
                    while(*temp != '\0') {
                        temp++;
                        *(temp-1) = *temp;
                    }
                }
                else if(*pocetakTacke == '\0' && pocetakTacke != pocetak) 
                    *(pocetakTacke - 1) = *pocetakTacke;
                if(pocetakTacke == pocetak)
                    string = pocetakTacke;
                else
                    string = pocetakTacke - 1;
            }
            else
                string++;
        }
        else if(*string == ',') {
            /* string pocinje zarezom ili ima duplih zareza, nije dobro formatiran */
            if(string == pocetak || *(string - 1) != ')' || *(string + 1) == '\0') {
                pocetak = 0;
                return pocetak;
            }
            string++;
        }
        else {
            pocetak = 0;
            return pocetak;
        }
    }
    return pocetak;
}

int main()
{
    char primjer[] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
    printf("%s\n", primjer);
    printf("%s", obuhvat(primjer, -3, -3, 3, 3));
    return 0;
}