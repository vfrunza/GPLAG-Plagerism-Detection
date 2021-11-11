#include <stdio.h>
#include <string.h>


char* kodiraj (char* s1, char* s2)
{
    char* kop_poc_s2 = s2;              // cuvamo kopiju pocetka strinka
    char* kop_poc_s1 = s1;              // string s1 je neki text koji prima funkcija
    char* p1 = s1;                      // string s2 cuvamo modifikovanu-ASCI tabelu
    char ASCI[96];                      // ASCI tabela
    int i, j;
    int temp1, temp2;
    int min;

    for (i = 0; i < 95; i++) {          // Inicijalizacija ASCI tabele
        ASCI[i] = i +32;

    }
    ASCI[i] = '\0';

    int niz_brojaca[96] = {0};          // niz brojaca za svaki karakter ASCI tabele

    while ( *p1 != '\0') {              // Inicijalizacija niza brojaca (prolazimo kroz string s1)
        // povecavamo brojac svakog pronadjenog karaktera
        if (*p1 >= 32 && *p1 <= 126)
            niz_brojaca[*p1 - 32]++;
        p1++;
    }

    // Selection sort sortiramo ASCI tabelu (u zavisnosti koliko se karakter pojavljiva), od veceg ka manjem

    for (i=0; i<95; i++) {
        min=i;
        for (j=i+1; j<95; j++) {
            if (niz_brojaca[j] > niz_brojaca[min])
                min = j;
        }
        temp2 = niz_brojaca[i];             // sortiramo niz brojaca ( ukoliko ne sortiramo brojace zamijeniti cemo samo jedan karakter u tabeli)
        niz_brojaca[i] = niz_brojaca[min];
        niz_brojaca[min] = temp2;

        temp1 = ASCI[i];                    // sortiramo ASCI tabelu
        ASCI[i] = ASCI[min];
        ASCI[min] = temp1;
    }
// Nakon sto smo sortirali ASCI tabelu po broju ponavljanja karaktera , sada sortiramo karaktere sa jednakim broj ponavljanja po ASCI vrijednosti
    for (i=0; i<95; i++) {
        min=i;
        for (j=i+1; j<95; j++) {
            if ((ASCI[j] < ASCI[min]) && (niz_brojaca[j] == niz_brojaca[min]))  // ukoliko je broj ponavljanja nekog karaktera jednak,
                min = j;                                                        // sortiramo ih po ASCI vrijednosti
        }
        temp1 = ASCI[i];
        ASCI[i] = ASCI[min];
        ASCI[min] = temp1;
    }
    // svaki karakter u stringu mjenjamo sa njegovim redosljedom u ASCI tabeli po zakonu (126 - indeks u ASCI tabeli)
    for (i = 0; ; i++) {
        if (s1[i] == '\0')
            break;
        for ( j = 0; j < 95; j++) {
            if (s1[i] == ASCI[j]) {
                s1[i] = 126 - j;
                break;
            }
        }
    }

    strcpy (kop_poc_s2,ASCI);       // kopiramo ASCI tabelu u string s2
    return kop_poc_s1;              // vracamo pokazivac na pocetak stringa s1 ( teksta)
}
// Funkcja dekodiraj koja desifruje kodirani tekst
// Funkcija dekodiraj prima kodirani tekst i modifikovanu-ASCI tabelu

char* dekodiraj (char* s1, char* ASCI)
{

    char* kop_poc_s1 = s1;          //cuvamo kopiju pocetka teksta
    int i, j;

    for (i = 0; ; i++) {            // dekodiramo tekst suprotno kako smo ga kodirali
        if (s1[i] == '\0')          // ako je vrijednost znaka 126-index u ASCI tabeli
            break;                  // mjenamjo ga sa znakom koji je na tom indeksu u ASCI tabeli
        for ( j = 0; j < 95; j++) {
            if (s1[i] == 126-j) {
                s1[i] = ASCI[j];
                break;
            }
        }
    }
    return kop_poc_s1;
}

int main() {
char*tekst[100];
char*prazan[100];
printf("%c", kodiraj(tekst,prazan));
	return 0;
}
